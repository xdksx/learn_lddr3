#include<linux/init.h>
#include<linux/module.h>
#include "add_sub.h"
static int a=1;
static int b=1;
static AddOrSub=1;
static int test_init(void)
{
   long result=0;
   printk(KERN_ALERT "test init\n");
   if(1==AddOrSub)
   {
     result=add_integer(a,b);
   }
   else 
   {
    result=sub_integer(a,b);
    }
   printk(KERN_ALERT "the %s result is %ld",AddOrSub==1?"Add":"SUb",result);
   return 0;
}
static void test_exit(void)
{
   printk(KERN_ALERT "test exit\n");
}
module_init(test_init);
module_exit(test_exit);
module_param(a,int,S_IRUGO);
module_param(b,int,S_IRUGO);
module_param(AddOrSub,int,S_IRUGO);
MODULE_LICENSE("Dual BSD/GPL");
MODULE_AUTHOR("KSANCE");
MODULE_DESCRIPTION("A MODULE JUST TO TESTING PARAM AND EXPORT_SYMBOL");
MODULE_VERSION("VI.0");

