#!/bin/sh
qemu-system-x86_64 \
    -m 128M \
    -cpu kvm64 \
    -kernel vmlinuz-6.1.2 \
    -initrd initramfsz \
    -hdb flag.txt \
    -snapshot \
    -nographic \
    -monitor /dev/null \
    -no-reboot \
    -append "console=ttyS0 nosmap nosmep nokaslr kpti=0 nopti quiet panic=1"
