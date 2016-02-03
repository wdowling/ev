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

#include "system.h"
#include "console.h"

/* __strlen() returns the length of a string. */
size_t
__strlen(const char *msgstring)
{
	size_t ret = 0;
	while (msgstring[ret] != 0)
		ret++;

	return ret;
}

/* Set the character along with the foreground and background colours to write
 * to the console.
 */
uint16_t
__write_char(char c, uint16_t c_col)
{
	uint16_t c_char = c;
	uint16_t c_color = c_col;
	return c_char | c_color << 8;
}

/* Write the character string in *message to the console */
void
__write(const char *message, size_t len)
{
	size_t console_row = 0;
	size_t console_column = 0;

	for (size_t mc = 0; mc < len; mc++) {
		const size_t j = console_row * CONSOLE_WIDTH + console_column;
		framebuffer[j] = __write_char(message[mc], color);
		if (++console_column == CONSOLE_WIDTH) {
			console_column = 0;
			if (++console_column == CONSOLE_HEIGHT) {
				console_column = 0;
			}
		}
	}
}
