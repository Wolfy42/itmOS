/*  graphics.c: some (very very) basic graphics functions.

    Copyright (C) 2010 Michael Zucchi

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "graphics.h"
#include <stdarg.h>

struct RastPort defrp;
struct BitMap fb;

/* can only be called once ... */
struct RastPort *graphics_init(char *fbaddr, int width, int height, int type) {
	fb.width = width;
	fb.height = height;
	fb.format = type;
	fb.stride = width * 2;
	fb.data = fbaddr;

	defrp.x = defrp.y = 0;
	defrp.point = fb.data;
	defrp.colour = 0x000000;
	defrp.font.romfont = (struct RomFont *)&font_misc_fixed;
	defrp.drawable.bitmap = &fb;

	return &defrp;
}

void setColour(struct RastPort *rp, unsigned int rgb) {
	// TODO: switch rp->drawable->format ...

	rp->colour = ((rgb & 0xf80000) >> 8)
		| ((rgb & 0xfc00) >> 5)
		| ((rgb & 0xf8) >> 3);
}

extern void fill_rect_565(void *addr, int width, int height, unsigned int colour, int stride);

void drawRect(struct RastPort *rp, int w, int h) {
	unsigned int colour = rp->colour;
	unsigned short *outp = (unsigned short *)rp->point;

	if (w + rp->x > rp->drawable.bitmap->width)
		w = rp->drawable.bitmap->width - rp->x;
	if (h + rp->y > rp->drawable.bitmap->height)
		h = rp->drawable.bitmap->height - rp->y;
	int i, j;

	for (j = 0;j<h;j++) {
		for (i=0;i<w;i++) {
			outp[i] = colour;
		}
		outp = (unsigned short *)((char *)outp + rp->drawable.bitmap->stride);
	}
}

void moveTo(struct RastPort *rp, int x, int y) {
	rp->x = x;
	rp->y = y;
	rp->point = ((unsigned char *)rp->drawable.bitmap->data)
		+ x * 2
		+ y * rp->drawable.bitmap->stride;
}

void drawPixel(struct RastPort *rp) {
	*((unsigned short *)rp->point) = rp->colour;
}

void drawChar(struct RastPort *rp, unsigned int c, int scale) {
	int i, j, s;
	int w, h;
	unsigned short *outp;
	unsigned int colour = rp->colour;
	unsigned const char *inp;

	if (c < rp->font.romfont->first || c > rp->font.romfont->last)
		return;

	w = rp->font.romfont->width;
	h = rp->font.romfont->height;

	c = (c - rp->font.romfont->first) * w;

	outp = ((unsigned short *)rp->point) - rp->font.romfont->baseline*scale*rp->drawable.bitmap->stride;
	inp = rp->font.romfont->bitmap + c;

	for (j=0;j<h;j++) {
		for (s=0;s<scale;s++)  {
			for (i=0;i<w*scale;i++) {
				unsigned int b;

				b = inp[i/scale];
				if (b)  {
					outp[i] = colour;
				}
			}
			outp = (unsigned short *)((char *)outp + rp->drawable.bitmap->stride);
		}
		inp += rp->font.romfont->stride;
	}

	rp->point = ((unsigned short *)rp->point) + w*scale;
	rp->x += w*scale;
}

void drawString(struct RastPort *rp, const char *s, int scale) {
	unsigned int c;
	unsigned int x = rp->x;

	while ((c = *s++)) {
		if (c == '\n') {
			if (rp->y + 20 > rp->drawable.bitmap->height*scale) {
				//moveTo(rp, x, 20);
				x = x;
			} else
				moveTo(rp, x, rp->y + rp->font.romfont->lineheight*scale);
		} else
			drawChar(rp, c, scale);
	}
}