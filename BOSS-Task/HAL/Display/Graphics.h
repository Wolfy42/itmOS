#ifndef GRAPHICS_H_
#define GRAPHICS_H_

#include <stdarg.h>

// Settings
#define WIDTH 1024
#define HEIGHT 768
#define RES_WIDTH 1024
#define RES_HEIGHT 768
#define FBADDR ((char *)0x30000000)


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
		RastPort* _rastPort;
		/* can only be called once ... */
		struct RastPort* graphics_init(char* fbaddr, int width, int height, int type);
	
	public:		
		Graphics();
		virtual ~Graphics();
	
		void setColour(unsigned int rgb);
		void moveTo(int x, int y);
		void drawPixel(void);
		void drawRect(int w, int h);
		void drawChar(unsigned int c, int scale);
		void drawString(const char* s, int scale);
		
		RastPort* getRastPort(void);
};

#endif /*GRAPHICS_H_*/
