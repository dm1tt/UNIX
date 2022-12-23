#include <linux/init.h>             // Macros used to mark up functions e.g., __init __exit
#include <linux/module.h>           // Core header for loading module into the kernel
#include <linux/kernel.h>           

MODULE_LICENSE("GPL");              ///< The license type -- this affects function visibility
MODULE_AUTHOR("dm1tt");      ///< The author -- visible when you use modinfo
MODULE_DESCRIPTION("info");  ///< The description -- see modinfo
MODULE_VERSION("1.0");


static int __init simple_init(void) {
	printk(KERN_INFO "Hello, world\n");
	return 0;
}


static void __exit simple_exit(void) {
	printk(KERN_INFO "bei, AHIM TEL HAI!\n");
}

module_init(simple_init);
module_exit(simple_exit);
