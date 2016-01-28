#!/bin/sh
#
# build.sh -- small utility to build the ISO.
# usage:
#    ./build.sh
#
mkdir -p $HOME/iso/boot/grub
cp $HOME/ev/sys/boot/ev.bin $HOME/iso/boot/ev.bin

echo "
menuentry "ev" {
        multiboot /boot/ev.bin
}
" >> $HOME/iso/boot/grub/grub.cfg

cd $HOME && grub-mkrescue -o ev.iso iso
