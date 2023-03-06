obj-m += hello.o
all:
	make -C /lib/modules/5.4.0-137-generic/build/ M=$(PWD) modules
	mv hello.ko ../initramfs.cpio/
	
clean:
	make -C /lib/modules/5.4.0-137-generic/build/ M=$(PWD) clean