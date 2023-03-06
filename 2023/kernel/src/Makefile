obj-m += pwnme.o
all:
	make -C ~/linux-6.1.2 M=$(PWD) modules
	cp pwnme.ko ../initramfs/
	
clean:
	make -C ~/linux-6.1.2 M=$(PWD) clean