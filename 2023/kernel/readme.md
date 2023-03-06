

Download kernel linux
wget https://cdn.kernel.org/pub/linux/kernel/v6.x/linux-6.2.tar.xz
https://kernel.ubuntu.com/~kernel-ppa/mainline/v6.2/amd64/

Get a precompiled kernel
wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v6.2/amd64/linux-image-unsigned-6.2.0-060200-generic_6.2.0-060200.202302191831_amd64.deb

Extract vmlinuz from deb
sudo apt-get install binutils
ar vx linux-image-unsigned-6.2.0-060200-generic_6.2.0-060200.202302191831_amd64.deb

tar -xvf data.tar

wget https://kernel.ubuntu.com/~kernel-ppa/mainline/v6.2/amd64/linux-modules-6.2.0-060200-generic_6.2.0-060200.202302191831_amd64.deb


Build cpio
find ./initramfs.cpio | cpio -ov --format=newc | gzip -9 > ./initramfsz