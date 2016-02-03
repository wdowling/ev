CC=/opt/cross/bin/i686-elf-gcc
AS=/opt/cross/bin/i686-elf-as
SOBJ=system.o
KOBJ=init_kernel.o
LOBJ=boot.o
CFLAGS=-std=gnu99 -ffreestanding -O2 -Wall -Wextra
LFLAGS=-ffreestanding -O2 -nostdlib -lgcc

ev:
	$(AS) boot.s -o boot.o
	$(CC) -c system.c -o $(SOBJ) $(CFLAGS)
	$(CC) -c init_kernel.c -o $(KOBJ) $(CFLAGS)
	$(CC) -T linker.ld -o ev.bin $(LFLAGS) boot.o init_kernel.o system.o

clean:
	rm -f *.o *.bin
