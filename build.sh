#!/bin/sh
#
# build.sh -- small utility to build the ISO.
# usage:
#    ./build.sh
#
CROSS_PATH="/opt/cross/bin/"
HOME="/home/wmd"

cd sys/boot
$CROSS_PATH/i686-elf-as boot.s -o boot.o
$CROSS_PATH/i686-elf-gcc -c init_kernel.c -o init_kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra
$CROSS_PATH/i686-elf-gcc -T linker.ld -o ev.bin -ffreestanding -O2 -nostdlib boot.o init_kernel.o -lgcc

mkdir -p $HOME/iso/boot/grub
cp $HOME/ev/sys/boot/ev.bin $HOME/iso/boot/ev.bin

echo "
menuentry "ev" {
        multiboot /boot/ev.bin
}
" >> $HOME/iso/boot/grub/grub.cfg

cd $HOME && grub-mkrescue -o ev.iso iso
