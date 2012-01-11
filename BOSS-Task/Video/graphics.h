/*  graphics.h: graphics library header

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

#ifndef _GRAPHICS_H
#define _GRAPHICS_H

struct RomFont {
	const char *name;
	int width;
	int height;
	int stride;
	int first;
	int last;
	int baseline;
	int lineheight;
	unsigned const char *bitmap;
};

struct BitMap {
	int width;
	int height;
	int format;
	int stride;
	void *data;
};

/* NB: these mirror the omap modes */
#define BM_BITMAP1 0
#define BM_BITMAP2 1
#define BM_BITMAP4 2
#define BM_BITMAP8 3
#define BM_RGB16 6
#define BM_RGB23 9
#define BM_ARGB32 12
#define BM_YUV2 10
#define BM_UYVY 11

struct RastPort {
	int x, y;
	void *point;
	unsigned int colour;
	union {
		struct RomFont *romfont;
	} font;
	union {
		struct BitMap *bitmap;
	} drawable;
};

extern struct RomFont const font_misc_fixed;

/* can only be called once ... */
struct RastPort *graphics_init(char *fbaddr, int width, int height, int type);

void setColour(struct RastPort *rp, unsigned int rgb);
void moveTo(struct RastPort *rp, int x, int y);
void drawPixel(struct RastPort *rp);
void drawRect(struct RastPort *rp, int w, int h);
void drawChar(struct RastPort *rp, unsigned int c, int scale);
void drawString(struct RastPort *rp, const char *s, int scale);

#endif
