#ifndef HALDISPLAYDRIVER_H_
#define HALDISPLAYDRIVER_H_

#include "HAL/video.h"
#include "Tasks/Services/Display/Graphics.h"

typedef unsigned int uint32;

#define VENC_MODE_NTSC 	(0)
#define VENC_MODE_PAL 	(1)

class HalDisplayDriver {
	private:		
		Graphics* _graphics;
		void omap_attach_framebuffer(int id, struct BitMap *bm);
	
		void omap_venc_init(int mode);
		void omap_beagle_init(void);
		void omap_clock_init(void);
		void omap_dss_init(void);
		void omap_dispc_init(void);
		void omap_disable_display(int vid);
		void omap_set_lcd_mode(int w, int h, int d);
	
	public:	
		HalDisplayDriver();
		virtual ~HalDisplayDriver();
		
		void setColour(unsigned int rgb);
		void moveTo(int x, int y);
		void drawPixel(void);
		void drawRect(int w, int h);
		void drawChar(unsigned int c, int scale);
		void drawString(const char* s, int scale);
};

#endif /*HALDISPLAYDRIVER_H_*/
