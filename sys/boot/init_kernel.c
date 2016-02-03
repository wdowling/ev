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

/*
 * This file begins the initialization of the kernel. Is starts by creating a
 * simple console to display initialization messages.
 */

#include <stddef.h>
#include <stdint.h>
#include "console.h"
#include "io.h"
#include "system.h"

void
set_cursor(int row, int col)
{
	unsigned short position=(row * CONSOLE_HEIGHT) + col;
        outb(0x3D4, 0x0F);
	outb(0x3D5, (uint8_t)(position&0xFF));
	outb(0x3D4, 0x0E);
	outb(0x3D5, (uint8_t)(position>>8)&0xFF);
}

/* The console is a simple black background, 120 columns wide, 80 rows high. */
void
console_init()
{

	const char *msg;
	msg = INIT_MSG;

	/* Color screen black. */
	for (size_t y = 0; y < CONSOLE_HEIGHT; y++) {
		for (size_t x = 0; x < CONSOLE_WIDTH; x++) {
			const size_t i = y * CONSOLE_WIDTH + x;
			framebuffer[i] = __write_char(' ', color);
		}
	}

	/* Now that the console is initialized, update the console with the
	 * status of initialization.
	 */
	__write(msg, __strlen(msg));
	set_cursor(1, 0);
}

void
init_kernel()
{
	/* Initialize console screen. */
	console_init();
}
