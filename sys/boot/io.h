/*
 * Permission to use, copy, modify, and distribute this software any
 * purpose with or without fee is hereby granted, provided that above
 * copyright notice and this permission notice appear copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */
#ifndef INCLUDE_IO_H
#define INCLUDE_IO_H

static __inline void
outb(uint16_t port, uint16_t data)
{
	__asm volatile ("outb %b0,%w1": :"a" (data), "Nd" (port));
}

#endif
