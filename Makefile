
ifneq ($(KERNELRELEASE),)
# kbuild
obj-m := cpiofs.o

else
# makefile

KDIR ?= /lib/modules/`uname -r`/build

default:
	$(MAKE) -C $(KDIR) M=$$PWD

install:
	$(MAKE) -C $(KDIR) M=$$PWD modules_install

clean:
	$(MAKE) -C $(KDIR) M=$$PWD clean
	rm -rf *.o *.mod.c .*.cmd *.ko modules.order

endif
