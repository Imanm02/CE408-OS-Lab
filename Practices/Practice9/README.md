Student Name of member 1: `Iman Mohammadi`

Student Name of member 2: `Negar Babashah`

- [x] Read Session Contents.

## Section 9.3

- [x] Printing all linux interrupts

- [x] Code Explanation

کد `display_interrupts.c`:
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    char buffer[1024];

    fp = fopen("/proc/interrupts", "r");
    if (fp == NULL) {
        perror("Error in opening /proc/interrupts");
        return EXIT_FAILURE;
    }

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        printf("%s", buffer);
    }

    fclose(fp);
    return EXIT_SUCCESS;
}
```

<div dir="rtl">

- خط ۱-۲: وارد کردن کتابخانه‌های استاندارد مورد نیاز، stdio.h برای ورودی/خروجی و stdlib.h برای توابع عمومی.
- تابع main:
  - خط ۸: تلاش برای باز کردن فایل /proc/interrupts در حالت خواندن با استفاده از `fopen`.
  - خط ۹-۱۲: اگر باز کردن فایل موفقیت‌آمیز نبود (مثلاً به دلیل عدم دسترسی)، پیغام خطا با استفاده از `perror` نمایش داده می‌شود و برنامه با کد شکست (`EXIT_FAILURE`) خاتمه می‌یابد.
  - خط ۱۴-۱۶: در صورت موفقیت در باز کردن فایل، به طور پیوسته هر خط از فایل خوانده شده و با استفاده از `printf` چاپ می‌شود تا انتهای فایل برسیم.
  - خط ۱۸: پس از اتمام خواندن، فایل بسته می‌شود.
  - خط ۱۹: برنامه با کد موفقیت (`EXIT_SUCCESS`) خاتمه می‌یابد.

</div>

- [x] Screenshots after Run

<div align="center">

![image](https://github.com/user-attachments/assets/2349c0e6-6a43-4c01-83ef-c9d7d9c411de)
![image](https://github.com/user-attachments/assets/cd394031-2e47-4762-b1c6-106f8dd05b20)

</div>

- [x] Requirements

<div dir="rtl">
سیستم عامل: لینوکس
<br>
زبان برنامه‌نویسی: C
<br>
کامپایلر: GCC یا هر کامپایلر C دیگری
<br>
مجوز دسترسی: دسترسی به فایل /proc/interrupts، معمولاً دسترسی کاربر عادی کافی است

</div>

## Section 9.4
- [x] Adding a new interrupt  
    - [x] `FILL HERE with your descriptions (write in English or Persian)`
    - [x] `FILL HERE with screenshot of execution`   
    - [x] `FILL HERE with requirements`
# ۱. توضیحات

<div dir="rtl">

هدف از این پروژه، ایجاد یک وقفه نرم‌افزاری است که با نوشتن به فایل `/proc/my_softirq` توسط برنامه کاربر، فعال می‌شود و هندلر مرتبط با آن در ماژول کرنل اجرا می‌گردد. این فرآیند شامل مراحل زیر است:

## ایجاد ماژول کرنل:

- تعریف یک IRQ آزاد، در اینجا IRQ شماره 16 که توسط ماژول کرنل استفاده می‌شود. این مورد را با توجه به سیستم شخصی خود باید تنظیم کنیم.
- ثبت هندلر IRQ با استفاده از `request_irq`.
- ایجاد فایل `/proc/my_softirq` که به کاربران امکان تحریک IRQ را می‌دهد.

کد `my_softirq_module.c`:
```c
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>
#include <linux/init.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/irq.h>

#define MY_SOFTIRQ_VECTOR  16
#define PROC_NAME "my_softirq"

static struct proc_dir_entry *proc_entry;

static irqreturn_t my_irq_handler(int irq, void *dev_id) {
    printk(KERN_INFO "My Software Interrupt Handler Invoked!\n");
    return IRQ_HANDLED;
}

static ssize_t proc_write(struct file *file, const char __user *buffer, size_t count, loff_t *pos) {
    printk(KERN_INFO "Interrupt triggered by user space.\n");
    generic_handle_irq(MY_SOFTIRQ_VECTOR);
    return count;
}

static const struct proc_ops proc_fops = {
    .proc_write = proc_write,
};

static int __init my_module_init(void) {
    int result;

    result = request_irq(MY_SOFTIRQ_VECTOR, my_irq_handler, IRQF_SHARED, "my_softirq_handler", (void *)(my_irq_handler));
    if (result) {
        printk(KERN_ALERT "Failed to register interrupt handler\n");
        return result;
    }

    proc_entry = proc_create(PROC_NAME, 0666, NULL, &proc_fops);
    if (proc_entry == NULL) {
        free_irq(MY_SOFTIRQ_VECTOR, (void *)(my_irq_handler));
        printk(KERN_ALERT "Failed to create /proc entry\n");
        return -ENOMEM;
    }

    printk(KERN_INFO "My SoftIRQ Module Loaded\n");
    return 0;
}

static void __exit my_module_exit(void) {
    free_irq(MY_SOFTIRQ_VECTOR, (void *)(my_irq_handler));

    proc_remove(proc_entry);

    printk(KERN_INFO "My SoftIRQ Module Unloaded\n");
}

module_init(my_module_init);
module_exit(my_module_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Iman Mohammadi & Negar Babashah");
MODULE_DESCRIPTION("A module for adding a software interrupt to Linux using /proc");
```

## ایجاد برنامه کاربر:

- نوشتن برنامه‌ای که با اجرای آن، به فایل `/proc/my_softirq` نوشته و IRQ را تحریک می‌کند.

کد `trigger_interrupt.c`:
```c
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define PROC_PATH "/proc/my_softirq"

int main() {
    int fd;
    const char *message = "Trigger Interrupt";

    fd = open(PROC_PATH, O_WRONLY);
    if (fd == -1) {
        perror("Failed to open /proc/my_softirq");
        return EXIT_FAILURE;
    }

    if (write(fd, message, sizeof("Trigger Interrupt")) == -1) {
        perror("Failed to write to /proc/my_softirq");
        close(fd);
        return EXIT_FAILURE;
    }

    printf("Interrupt triggered successfully.\n");

    close(fd);
    return EXIT_SUCCESS;
}
```

## کامپایل و بارگذاری ماژول کرنل:

- کامپایل ماژول با استفاده از `make`.

کد `Makefile`:
```Makefile
obj-m += my_softirq_module.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

- بارگذاری ماژول با دستور `insmod` و بررسی موفقیت‌آمیز بودن بارگذاری از طریق لاگ کرنل (`dmesg`).

## تحریک IRQ و بررسی عملکرد:

- اجرای برنامه کاربر برای تحریک IRQ.
- بررسی لاگ کرنل برای اطمینان از اجرای هندلر IRQ.

## آزادسازی ماژول کرنل پس از آزمایش:

- آزادسازی ماژول با دستور `rmmod`.
- پاکسازی فایل‌های کامپایل شده و فایل‌های اجرایی.

### توضیح فنی:
سیگنال‌های IRQ (Interrupt Request)، سیگنال‌هایی هستند که توسط سخت‌افزار یا نرم‌افزار به پردازنده ارسال می‌شوند تا توجه سیستم عامل را به یک رویداد خاص جلب کنند. در این پروژه، از یک IRQ آزاد، مثلاً IRQ 16 برای ایجاد یک وقفه نرم‌افزاری استفاده شده است. با نوشتن به فایل `/proc/my_softirq`، تابع `generic_handle_irq` فراخوانی شده و IRQ تحریک می‌شود. هندلر IRQ ثبت شده در ماژول کرنل، پیام‌های مشخصی را در لاگ کرنل ثبت می‌کند تا تأیید کند که IRQ به درستی تحریک و هندلر اجرا شده است.

</div>

# ۲. Screenshot of Execution

<div dir="rtl">

### کامپایل ماژول کرنل:

- نمایش خروجی دستور `make` که نشان‌دهنده موفقیت‌آمیز بودن فرآیند کامپایل است.

### بارگذاری ماژول کرنل:

- نمایش خروجی دستور `insmod my_softirq_module.ko` و پیام‌های مربوطه در لاگ کرنل (`dmesg`).

### تحریک IRQ از طریق برنامه کاربر:

- نمایش اجرای برنامه `trigger_interrupt` و خروجی آن.

### بررسی لاگ کرنل:

- نمایش خروجی دستور `dmesg | tail` پس از تحریک IRQ که نشان‌دهنده اجرای هندلر IRQ است.

### آزادسازی ماژول کرنل:

- نمایش اجرای دستور `rmmod my_softirq_module` و پیام‌های مربوطه در لاگ کرنل.


<div align="center">

![image](https://github.com/user-attachments/assets/b0ede199-0120-4a23-86a1-b17a6504ec15)
![image](https://github.com/user-attachments/assets/ff296235-7f09-44a7-9ad5-ab7c7fac238c)
![image](https://github.com/user-attachments/assets/8ad58f84-dbe4-4ae1-a9fe-42f0948885a0)
![image](https://github.com/user-attachments/assets/f202bb8d-99b1-42d8-a29a-ae4e85d06765)

</div>

</div>

# ۳. نیازمندی‌ها

<div dir="rtl">

برای اجرای این پروژه، نیاز به موارد زیر داریم:

## سیستم عامل:

- لینوکس، توزیع‌های مبتنی بر دبیان مانند Ubuntu

## هسته لینوکس (Kernel):

- نسخه `6.8.0-48-generic` یا مشابه آن.
- هدرهای کرنل مرتبط نصب شده‌اند:

    ```bash
    sudo apt-get install linux-headers-$(uname -r)
    ```

## کامپایلر:

- GCC نسخه `13.3.0` (تفاوت نسخه با نسخه هسته معمولاً مشکلی ایجاد نمی‌کند).

## ابزارهای کامپایل:

- `build-essential` نصب شده‌اند:

    ```bash
    sudo apt-get install build-essential
    ```

## دسترسی ریشه (Root):

- برای بارگذاری و آزادسازی ماژول‌های کرنل نیاز به دسترسی ریشه دارید که چالش خاصی نیست اگر مثلا روی سرور یا سیستم خودتون در حال ران گرفتن از برنامه هستید.

## فایل‌های سورس:

- `my_softirq_module.c`: سورس کد ماژول کرنل.
- `Makefile`: فایل Makefile برای کامپایل ماژول.
- `trigger_interrupt.c`: سورس کد برنامه کاربر برای تحریک IRQ.

</div>