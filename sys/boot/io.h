/*
 * Code sourced from Linux kernel sys/io.h
 */
#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

static __inline void
outb(unsigned char data, unsigned short int port)
{
	__asm__ __volatile__ ("outb %b0,%w1": :"a" (data), "Nd" (port));
}

#endif
