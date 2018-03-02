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
	{ 0xea147363, "printk" },
	{ 0x6020e5b, "free_netdev" },
	{ 0x4df31d0, "register_netdev" },
	{ 0xb4390f9a, "mcount" },
	{ 0x7073038a, "alloc_netdev_mq" },
	{ 0x4f8c9af, "ether_setup" },
	{ 0x5638a743, "unregister_netdev" },
	{ 0x3d0b7e37, "__netif_schedule" },
	{ 0x97d0687d, "consume_skb" },
};

static const char __module_depends[]
__used
__attribute__((section(".modinfo"))) =
"depends=";


MODULE_INFO(srcversion, "F34CA0F1CBEAAB60D5C5287");
