#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <stdarg.h>

/* NB: these mirror the omap modes */
#define BM_BITMAP1 		0
#define BM_BITMAP2 		1
#define BM_BITMAP4 		2
#define BM_BITMAP8 		3
#define BM_RGB16 		6
#define BM_RGB23 		9
#define BM_ARGB32 		12
#define BM_YUV2 		10
#define BM_UYVY 		11

struct RomFont {
	const char* name;
	int width;
	int height;
	int stride;
	int first;
	int last;
	int baseline;
	int lineheight;
	unsigned const char* bitmap;
};

struct BitMap {
	int width;
	int height;
	int format;
	int stride;
	void* data;
};

struct RastPort {
	int x, y;
	void* point;
	unsigned int colour;
	union {
		struct RomFont* romfont;
	} font;
	union {
		struct BitMap* bitmap;
	} drawable;
};

extern struct RomFont const font_misc_fixed;		


class Graphics {
	private:
		Graphics();
		virtual ~Graphics();
	
	public:		
		/* can only be called once ... */
		static struct RastPort* graphics_init(char* fbaddr, int width, int height, int type);
		static void setColour(struct RastPort* rp, unsigned int rgb);
		static void moveTo(struct RastPort* rp, int x, int y);
		static void drawPixel(struct RastPort* rp);
		static void drawRect(struct RastPort* rp, int w, int h);
		static void drawChar(struct RastPort* rp, unsigned int c, int scale);
		static void drawString(struct RastPort* rp, const char* s, int scale);
};

#endif /*GRAPHICS_H_*/
