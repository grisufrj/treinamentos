#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/mm.h>
#include <linux/highmem.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("esoj");
MODULE_DESCRIPTION("GRIS Kernel Tranining");


ssize_t pwnme_read(struct file *file_in, char __user *userbuf, size_t num_bytes, loff_t *offset);
ssize_t pwnme_write(struct file *file_in, const char __user *userbuf, size_t num_bytes, loff_t *offset);

static struct proc_dir_entry *pwnme_procfs = NULL;
static const struct proc_ops   pwnme_ops = {
    .proc_write = pwnme_write,
    .proc_read  = pwnme_read,
};


ssize_t pwnme_read(struct file *file_in, char __user *userbuf, size_t num_bytes, loff_t *offset) {
    // Reading does nothing
    return 0;
}

ssize_t pwnme_write(struct file *file_in, const char __user *userbuf, size_t num_bytes, loff_t *offset) {
    int (*p)(void);
    copy_from_user(&p, userbuf, sizeof(p));

    printk(KERN_INFO "[pwnme] executing addr %lx!\n",(long)p);
    printk(KERN_INFO "[pwnme] returned  %lx!\n",p());
    
    return num_bytes;
    
}

int pwnme_init(void) {
    printk(KERN_INFO "[pwnme] Starting module\n");
    pwnme_procfs = proc_create("pwnme", 0666, NULL, &pwnme_ops);
    return 0;
}

void pwnme_fini(void) {
    printk(KERN_INFO "[pwnme] Goodbye!\n");
    proc_remove(pwnme_procfs);
}


module_init(pwnme_init);
module_exit(pwnme_fini);