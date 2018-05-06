ifeq ($(KERNELRELEASE),)
   KERNELDIR?=/lib/modules/2.6.32-21-generic/build
   PWD:=$(shell pwd)
modules: 
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules
modules_install:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules_install
clean:
	rm -rf *.o *~core .depend .*.cmd *.mod.c .tmp_versions
else
	obj-m:=hello.o
endif
        

