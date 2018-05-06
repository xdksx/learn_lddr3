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
	{ 0x9c1fe301, "per_cpu__current_task" },
	{ 0x5a34a45c, "__kmalloc" },
	{ 0x8836b224, "cdev_init" },
	{ 0x6980fe91, "param_get_int" },
	{ 0xc8b57c27, "autoremove_wake_function" },
	{ 0x45d11c43, "down_interruptible" },
	{ 0x7485e15e, "unregister_chrdev_region" },
	{ 0xff964b25, "param_set_int" },
	{ 0x47f2d35b, "nonseekable_open" },
	{ 0xffc7c184, "__init_waitqueue_head" },
	{ 0xde0bdcff, "memset" },
	{ 0xea147363, "printk" },
	{ 0xbe499d81, "copy_to_user" },
	{ 0xb4390f9a, "mcount" },
	{ 0x748caf40, "down" },
	{ 0xc4808da5, "cdev_add" },
	{ 0x1000e51, "schedule" },
	{ 0x642e54ac, "__wake_up" },
	{ 0x37a0cba, "kfree" },
	{ 0x33d92f9a, "prepare_to_wait" },
	{ 0x3f1899f1, "up" },
	{ 0x9ccb2622, "finish_wait" },
	{ 0x945bc6a7, "copy_from_user" },
	{ 0x29537c9e, "alloc_chrdev_region" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "7DEC42A9D5B6FCF5E0033DC");
