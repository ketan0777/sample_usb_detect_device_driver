obj-m := stick_driver.o

KERNEL_DIR = /lib/modules/$(shell uname -r)/build
PWD = $(shell pwd)
default:
	$(MAKE) -C $(KERNEL_DIR) SUBDIRS=$(PWD) modules

clean:
	rm -rf *.o *.ko *.mod *.symvers *.order *~
