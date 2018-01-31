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
	{ 0x6bc3fbc0, "__unregister_chrdev" },
	{ 0x9c1fe301, "per_cpu__current_task" },
	{ 0xea2411c4, "__register_chrdev" },
	{ 0x1cefe352, "wait_for_completion" },
	{ 0xea147363, "printk" },
	{ 0xb4390f9a, "mcount" },
	{ 0xe456bd3a, "complete" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "4D447C1687A5F46332CF99D");
