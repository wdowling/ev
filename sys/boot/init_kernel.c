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

static const size_t CONSOLE_WIDTH = 120;
static const size_t CONSOLE_HEIGHT = 80;

enum console_color {
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGENTA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGENTA = 13,
	LIGHT_BROWN = 14,
	WHITE = 15,
};
	
/* The console is a simple black background, 120 columns wide, 80 rows high. */
void
console_init()
{
	uint8_t color;
	uint16_t *fb;

	color = LIGHT_GREY | BLACK << 4;
	uint16_t ch = ' ';
	uint16_t cl = color;
	fb = (uint16_t *) 0xB8000;

	/* Color screen black. */
	for (size_t y = 0; y < CONSOLE_HEIGHT; y++) {
		for (size_t x = 0; x < CONSOLE_WIDTH; x++) {
			const size_t i = y * CONSOLE_WIDTH + x;
			fb[i] = ch | cl << 8; 
		}
	}
}

void
init_kernel()
{
	/* Initialize console screen. */
	console_init();
}
