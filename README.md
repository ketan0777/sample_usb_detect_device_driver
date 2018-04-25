# sample_usb_detect_device_driver
This C Device Driver will detect your usb device but Pls include your vendor id & product id in device array table


NOTE
--------------
Before Loading This Driver Pls unload existing usb driver beacuase if mass_usb driver it's already loaded then This Driver's probe function will not be called so it's not able to recognise device

How To Compile
--------------
sudo make

How To Run
-------------
sudo insmod stick_driver.ko

How To Check Log
----------------
dmesg
or
tail -f /var/log/kern.log

How to remove Driver
--------------------
sudo rmmod stick_driver.ko
