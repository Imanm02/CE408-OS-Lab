#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/syscalls.h>
#include <linux/kprobes.h>

MODULE_AUTHOR("Iman Mohammadi & Negar Babashah");
MODULE_LICENSE("GPL");

typedef unsigned long (*lookup_name_t)(const char *name);

static int __init syscall_printer_init(void) {
    struct kprobe kp_instance;
    lookup_name_t lookup;
    void **sys_table;
    int index;

    memset(&kp_instance, 0, sizeof(struct kprobe));
    kp_instance.symbol_name = "kallsyms_lookup_name";

    if (register_kprobe(&kp_instance) < 0) {
        printk(KERN_INFO "kallsyms_lookup_name not found.\n");
        return -1;
    }

    lookup = (lookup_name_t) kp_instance.addr;
    unregister_kprobe(&kp_instance);

    sys_table = (void **) lookup("sys_call_table");
    if (!sys_table) {
        printk(KERN_INFO "sys_call_table not found.\n");
        return -1;
    }

    for (index = 0; index < __NR_syscalls; index++) {
        printk(KERN_INFO "SYSCALL %03d: %px\n", index + 1, sys_table[index]);
    }

    return 0;
}

static void __exit syscall_printer_exit(void) {
    printk(KERN_INFO "SYSCALLShowMod finished.\n");
}

module_init(syscall_printer_init);
module_exit(syscall_printer_exit);