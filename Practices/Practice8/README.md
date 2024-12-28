Student Name of member 1: `Iman Mohammadi`

Student Name of member 2: `Negar Babashah`

- [x] Read Session Contents.

### Section 8.3

کد `syscall_printer.c`:
```c
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
```

کد `Makefile`:
```Makefile
obj-m += syscall_printer.o

build:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

remove:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

# توضیح کدها:

**کد `syscall_printer.c`** برای بارگذاری یک ماژول هسته‌ای نوشته شده است که وظیفه‌اش چاپ آدرس‌های توابع سیستمی موجود در جدول فراخوانی سیستمی است. این ماژول از مکانیزم‌های نظیر `kprobes` برای دستیابی به نمایه `sys_call_table` استفاده می‌کند که در آن آدرس توابع سیستمی ذخیره شده‌اند. هنگامی که ماژول بارگذاری می‌شود، این آدرس‌ها را در لاگ‌های هسته چاپ می‌کند و هنگامی که ماژول حذف می‌شود، پیامی مبنی بر اتمام کار ماژول نمایش داده می‌شود.

# توضیح اجرا:

برای اجرای این ماژول، ابتدا باید فایل `syscall_printer.c` را با استفاده از ابزارهای ساخت هسته لینوکس کامپایل کنیم. پس از کامپایل، فایل ماژول (`syscall_printer.ko`) تولید می‌شود که باید با استفاده از دستور `insmod` آن را بارگذاری کنیم. هنگام بارگذاری، ماژول آدرس‌های توابع سیستمی را در لاگ‌ها ثبت می‌کند. پس از بررسی خروجی‌ها و اطمینان از صحت عملکرد ماژول، می‌توان آن را با دستور `rmmod` حذف کرد. خروجی‌های مربوطه را می‌توان در لاگ‌های هسته با استفاده از دستور `dmesg` مشاهده کرد.

# اسکرین‌شات‌های خروجی:

<div align="center">

![image](https://github.com/user-attachments/assets/ded438b5-5cdc-4f5b-b09f-edf134b920bc)

![image](https://github.com/user-attachments/assets/1fb9a8dd-f97d-4db7-9dd8-c38d799ef78a)

![image](https://github.com/user-attachments/assets/bf8b9fd8-9bbb-4973-ba52-de5084b20655)

</div>

# نیازمندی‌های اجرای این کد:

- **دسترسی ریشه (Root Access):** برای بارگذاری و حذف ماژول‌های هسته‌ای نیاز به دسترسی‌های ریشه است.
- **کامپایلر و ابزارهای ساخت کرنل لینوکس:** نصب بسته‌های `build-essential` و `linux-headers-$(uname -r)` برای توسعه ماژول‌های هسته.
- **محیط لینوکس:** از آنجایی که این ماژول برای هسته لینوکس نوشته شده است، نیاز به یک محیط لینوکس با هسته‌ای که از ماژول‌های بارگذاری شده پشتیبانی می‌کند، داریم.
- **ابزار insmod و rmmod:** برای بارگذاری و حذف ماژول‌ها.
- **دستور dmesg:** برای مشاهده خروجی‌های ماژول هنگام بارگذاری و حذف.


### Section 8.4

کد `hide_home_entries.c`:
```c
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
```

کد `Makefile`:
```Makefile
obj-m += hide_home_entries.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

# توضیح کدها:

کد ماژول `hide_home_entries.c` را برای پنهان کردن محتویات خاصی در دایرکتوری `/home` طراحی کرده‌ایم. این ماژول با استفاده از توابع هوک شده در جدول فراخوان‌های سیستم (syscall table)، توابع مربوط به خواندن دایرکتوری‌ها (`getdents64`) را دستکاری می‌کند تا موارد خاصی را از نتایج حذف کند. تابع `modified_getdents` جایگزین تابع اصلی می‌شود و فقط آن داده‌هایی که مطابق با شرایط معینی هستند را نشان می‌دهد، مانند فیلتر کردن فایل‌ها یا پوشه‌های خاص.

# توضیح اجرا:

برای اجرای این ماژول، این مراحل را باید دنبال کنیم:

1. **کامپایل ماژول:** با استفاده از دستور `make`، ماژول را کامپایل کنیم تا فایل `hide_home_entries.ko` ایجاد شود.
2. **بارگذاری ماژول:** با دستور `sudo insmod hide_home_entries.ko` ماژول را بارگذاری می‌کنیم.
3. **بررسی عملکرد:** با استفاده از `dmesg` آخرین پیام‌های سیستم را بررسی می‌کنیم تا اطمینان حاصل شود که ماژول به درستی بارگذاری شده است.
4. **حذف ماژول:** پس از اتمام تست، ماژول را با دستور `sudo rmmod hide_home_entries` حذف می‌کنیم.
5. **پاک‌سازی:** با دستور `make clean` فایل‌های ایجاد شده در فرآیند ساخت را پاک می‌کنیم.

# اسکرین‌شات‌های خروجی:

<div align="center">

![image](https://github.com/user-attachments/assets/4c475e6f-2e6d-4e77-ade7-a7984f2f739b)

</div>

# نیازمندی‌های اجرای این کد:

- **دسترسی به ریشه (Root Access):** برای بارگذاری و حذف ماژول‌های هسته‌ای نیاز به دسترسی‌های ریشه است.
- **ابزارهای توسعه کرنل لینوکس:** نصب شده بر روی سیستم برای کامپایل کردن ماژول‌ها. این شامل `build-essential` و `linux-headers-$(uname -r)` است.
- **محیط لینوکس سازگار:** باید در یک محیط لینوکس با نسخه‌ی هسته‌ای سازگار با ماژول نوشته شده، کار کنیم.
- **ابزارهای کنترل ماژول:** مانند `insmod`، `rmmod`، و `dmesg` برای بارگذاری، حذف ماژول و بررسی لاگ‌های سیستم.