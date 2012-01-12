#include "Graphics.h"

struct RastPort defrp;
struct BitMap fb;

Graphics::Graphics() {
	_rastPort = graphics_init(FBADDR, RES_WIDTH, RES_HEIGHT, BM_RGB16);
}

Graphics::~Graphics() {}

/* can only be called once ... */
struct RastPort* Graphics::graphics_init(char *fbaddr, int width, int height, int type) {
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

void Graphics::setColour(unsigned int rgb) {
	// TODO: switch rp->drawable->format ...

	_rastPort->colour = ((rgb & 0xf80000) >> 8)
		| ((rgb & 0xfc00) >> 5)
		| ((rgb & 0xf8) >> 3);
}

extern void fill_rect_565(void *addr, int width, int height, unsigned int colour, int stride);

void Graphics::drawRect(int w, int h) {
	unsigned int colour = _rastPort->colour;
	unsigned short *outp = (unsigned short *)_rastPort->point;

	if (w + _rastPort->x > _rastPort->drawable.bitmap->width)
		w = _rastPort->drawable.bitmap->width - _rastPort->x;
	if (h + _rastPort->y > _rastPort->drawable.bitmap->height)
		h = _rastPort->drawable.bitmap->height - _rastPort->y;
	int i, j;

	for (j = 0;j<h;j++) {
		for (i=0;i<w;i++) {
			outp[i] = colour;
		}
		outp = (unsigned short *)((char *)outp + _rastPort->drawable.bitmap->stride);
	}
}


void Graphics::moveTo(int x, int y) {
	_rastPort->x = x;
	_rastPort->y = y;
	_rastPort->point = ((unsigned char *)_rastPort->drawable.bitmap->data)
		+ x * 2
		+ y * _rastPort->drawable.bitmap->stride;
}

void Graphics::drawPixel(void) {
	*((unsigned short *)_rastPort->point) = _rastPort->colour;
}

void Graphics::drawChar(unsigned int c, int scale) {
	int i, j, s;
	int w, h;
	unsigned short *outp;
	unsigned int colour = _rastPort->colour;
	unsigned const char *inp;

	if (c < _rastPort->font.romfont->first || c > _rastPort->font.romfont->last)
		return;

	w = _rastPort->font.romfont->width;
	h = _rastPort->font.romfont->height;

	c = (c - _rastPort->font.romfont->first) * w;

	outp = ((unsigned short *)_rastPort->point) - _rastPort->font.romfont->baseline*scale*_rastPort->drawable.bitmap->stride;
	inp = _rastPort->font.romfont->bitmap + c;

	for (j=0;j<h;j++) {
		for (s=0;s<scale;s++)  {
			for (i=0;i<w*scale;i++) {
				unsigned int b;

				b = inp[i/scale];
				if (b)  {
					outp[i] = colour;
				}
			}
			outp = (unsigned short *)((char *)outp + _rastPort->drawable.bitmap->stride);
		}
		inp += _rastPort->font.romfont->stride;
	}

	_rastPort->point = ((unsigned short *)_rastPort->point) + w*scale;
	_rastPort->x += w*scale;
}

void Graphics::drawString(const char *s, int scale) {
	unsigned int c;
	unsigned int x = _rastPort->x;

	while ((c = *s++)) {
		if (c == '\n') {
			if (_rastPort->y + 20 > _rastPort->drawable.bitmap->height*scale) {
				//moveTo(_rastPort, x, 20);
				x = x;
			} else
				moveTo(x, _rastPort->y + _rastPort->font.romfont->lineheight*scale);
		} else
			drawChar(c, scale);
	}
}

RastPort* Graphics::getRastPort(void) {
	return _rastPort;
}
