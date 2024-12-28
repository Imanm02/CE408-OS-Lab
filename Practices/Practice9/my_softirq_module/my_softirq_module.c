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
