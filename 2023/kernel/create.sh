#!/bin/bash

# from https://github.com/ntegan/basic_initramfs/blob/master/misc/init_template

set -exuo pipefail

my_dir="$(cd $(dirname $0) && pwd)"

function create_folder_structure {
    initramfs_dirs=(bin sbin etc proc sys newroot)
    mkdir -p $work_dir/initramfs
    for dir in ${initramfs_dirs[@]}; do
        mkdir -p $work_dir/initramfs/$dir
    done
}
function touch_mdev_conf {
    # apparently this is needed so newer busy boxes
    # don't complain
    touch $work_dir/initramfs/etc/mdev.conf
}
function get_busybox {
    # Using statically compiled here
    # If used dynamically linked busybox, would just have to put
    # necessary libraries in /lib in initramfs.
    # Busybox compiled with glibc and/or uclibc.
    # uclibc produces much smaller binaries
    local busybox_path=$work_dir/initramfs/bin/busybox
    wget $busybox_link -O $busybox_path
    chmod +x $busybox_path
}
function link_busy_box_to_sh {
    local busybox_path=$work_dir/initramfs/bin/busybox
    ln -s busybox $work_dir/initramfs/bin/sh
}
function create_init_script {
    # If an initramfs is build into kernel / passed to it,
    # kernel will try to execute /init in the initramfs.
    # Usually /init is shell script that will find and mount
    # root partition, then switch_root onto root partition and
    # execute /sbin/init.
    local init_path=$work_dir/initramfs/init
    cp $misc_dir/init_template $init_path
    chmod +x $init_path
    # NOTE: this initramfs doesn't do anything you couldn't
    # do without an initramfs, but it can be extended very 
    # easily as needed.
}
function create_cpio_and_igz {
    # When passing initramfs to krnl using bootloader,
    # kernel expects gzipped cpio archive (.igz).
    # Easiest way to build initramfs img into kernel
    # is to create a cpio archive (.cpio). We will create both

    # Create cpio
    (   cd $work_dir/initramfs; 
        find . | cpio -H newc -o | gzip > $output_dir/initramfsz
    ) 
    
    
}

work_dir=$my_dir
misc_dir=$my_dir/src
output_dir=$my_dir
busybox_link='https://busybox.net/downloads/binaries/1.31.0-defconfig-multiarch-musl/busybox-x86_64'

rm -rf $work_dir/initramfs

mkdir -p $work_dir
mkdir -p $output_dir


create_folder_structure
touch_mdev_conf
get_busybox
link_busy_box_to_sh
create_init_script


echo "Building module"
cd src
make
make clean
cd ..

create_cpio_and_igz

./run.sh