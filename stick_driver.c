#include<linux/module.h>
#include<linux/kernel.h>
#include<linux/usb.h>


//probe function   pls unload existing usb device driver otherwise this function will not called
static int pen_probe(struct usb_interface *interface,const struct usb_device_id *id)
{
	printk(KERN_INFO "Pen Drive Detected (%04X:%04X) plugged\n",id->idVendor,id->idProduct);
	return 0;
}

static void pen_disconnect(struct usb_interface *interface){
	printk(KERN_INFO "Pen Drive removed\n");
}


// usb_device id
static struct usb_device_id pen_table[] = {
	//1d6b:0002
	{ USB_DEVICE(0x1d6b, 0x0002)},      //information of usb's VID,PID using lsusb command
	{} /*Terminating Entry  here you can add any usb VID PID this is struct array of VID PID*/
};


// usb_driver

static struct usb_driver pen_driver=
{
	.name = "USB-Stick Driver",   //name of the naming driver
	.id_table = pen_table,        //match with this driver that attached bus  usb_device id
	.probe = pen_probe,	      
	.disconnect = pen_disconnect,
};


static int __init pen_init(void){
	int ret = -1;
	printk(KERN_INFO "Pendriver Constructor Driver");
	printk(KERN_INFO "\tRegistring Driver With Kernel");
	ret = usb_register(&pen_driver);
	printk(KERN_INFO "\tRegistration is complete"); 

	return ret;
}

static void __exit pen_exit(void){
	printk(KERN_INFO "Pendriver Deconstructor Driver");
	usb_deregister(&pen_driver);
	printk(KERN_INFO "\tderegestration is complete");
}


module_init(pen_init);
module_exit(pen_exit);

MODULE_AUTHOR("KE7TAN");
MODULE_DESCRIPTION("USB Pen Reg. Driver");
MODULE_LICENSE("GPL");
