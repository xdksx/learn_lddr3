#include <linux/module.h>
#include <linux/vermagic.h>
#include <linux/compiler.h>

MODULE_INFO(vermagic, VERMAGIC_STRING);

struct module __this_module
__attribute__((section(".gnu.linkonce.this_module"))) = {
 .name = KBUILD_MODNAME,
 .init = init_module,
#ifdef CONFIG_MODULE_UNLOAD
 .exit = cleanup_module,
#endif
 .arch = MODULE_ARCH_INIT,
};

static const struct modversion_info ____versions[]
__used
__attribute__((section("__versions"))) = {
	{ 0x7ef7cd24, "module_layout" },
	{ 0x26188f53, "cdev_del" },
	{ 0xd356f174, "kmalloc_caches" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x8836b224, "cdev_init" },
	{ 0x6980fe91, "param_get_int" },
	{ 0xd8e484f0, "register_chrdev_region" },
	{ 0x5b47f990, "seq_open" },
	{ 0x105e2727, "__tracepoint_kmalloc" },
	{ 0x45d11c43, "down_interruptible" },
	{ 0xb523ecaa, "seq_printf" },
	{ 0x569b57b9, "remove_proc_entry" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xff964b25, "param_set_int" },
	{ 0x3c2c5af5, "sprintf" },
	{ 0x7536105, "seq_read" },
	{ 0xde0bdcff, "memset" },
	{ 0xea147363, "printk" },
	{ 0xa1c76e0a, "_cond_resched" },
	{ 0xbe499d81, "copy_to_user" },
	{ 0xb4390f9a, "mcount" },
	{ 0x6dcaeb88, "per_cpu__kernel_stack" },
	{ 0xc4808da5, "cdev_add" },
	{ 0x7dceceac, "capable" },
	{ 0x22928ae2, "kmem_cache_alloc" },
	{ 0xb2fd5ceb, "__put_user_4" },
	{ 0x7e0dcf23, "create_proc_entry" },
	{ 0xc37dd794, "seq_lseek" },
	{ 0x37a0cba, "kfree" },
	{ 0x3f1899f1, "up" },
	{ 0x31293b66, "seq_release" },
	{ 0x945bc6a7, "copy_from_user" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7AB32123DA44C702FC65E4F");
