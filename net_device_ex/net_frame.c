#include<linux/module.h>
#include<linux/errno.h>
#include<linux/netdevice.h>
MODULE_LICENSE("GPL");
static struct net_device *sg_dev;
struct demo_priv
{
  struct net_device_stats stats;
  struct sk_buff *skb;
  spinlock_t lock;
};
static int virnet_open(struct net_device *dev)
{
   netif_start_queue(dev);
   return 0;
}
static int virnet_stop(struct net_device *dev)
{
    //free_irq(dev->irq,dev);
    netif_stop_queue(dev);
    return 0;
}
static int virnet_send_packet(struct sk_buff *skb,struct net_device *dev)
{
    int i;
    netif_stop_queue(dev);
    printk("send,length=%d:\n",skb->len);
    for(i=0;i<skb->len;i++)
    {
      printk("%x ",skb->data[i]);
    }
    printk("\n");

    dev->stats.tx_packets++;
    dev->stats.tx_bytes+=skb->len;
    netif_wake_queue(dev);
    dev_kfree_skb(skb);
    return 0;
}
static void demo_interrupt(int irq,void *dev_id)
{
   ...
  switch(status &ISQ_EVENT_MASK){
  case ISQ_RECEIVER_EVENT:
     demo_rx(sg_dev);
     break;
   }
}

static void demo_rx(struct net_device *dev)
{
   skb=dev_alloc_skb(length+2);
   skb_reserve(skb,2);
   skb->dev=dev;
   ...
   netif_rx(skb);
}
static struct net_device_ops sg_ops=
{
   .ndo_start_xmit=virnet_send_packet,
   .ndo_open=virnet_open;
   .ndo_stop=virnet_stop;
};
static int virnet_init(void)
{  
   int result,ret=-ENOMEM;
   sg_dev=alloc_netdev(sizeof(struct demo_priv),"virnet%d",demo_init);
   if(sg_dev==NULL)goto out;
   ret=-ENODEV;
   if((result=register_netdev(sg_dev)))
  {
    printk("demo:error %i register device :%s \n",result,sg_dev->name);
  }
   else
    ret=0;
   out:
   if(ret)
     demo_cleanup();

 //  sg_dev=alloc_netdev(0,"virnet%d",NET_NAME_UNKNOWN,ether_setup);
//   sg_dev->netdev_ops=&sg_ops;
 //  memcpy(sg_dev->dev_addr,"\x01\x02\x03\x04\x05\x06",6);
   //register_netdev(sg_dev);
   return ret;
}
void demo_init(struct net_device *dev)
{
  struct demo_priv *priv;
  ether_setup(dev);
  dev->netdev_ops=&sg_ops;
  dev->...=..
}  
static void virnet_exit(void)
{
  unregister_netdev(sg_dev);
  free_netdev(sg_dev);
}
module_init(virnet_init);
module_exit(virnet_exit);


