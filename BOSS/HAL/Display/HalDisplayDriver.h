#ifndef HALDISPLAYDRIVER_H_
#define HALDISPLAYDRIVER_H_

#include "HAL/video.h"
#include "DisplayService/Graphics.h"

typedef unsigned int uint32;

#define VENC_MODE_NTSC 	(0)
#define VENC_MODE_PAL 	(1)

class HalDisplayDriver {
	private:
		HalDisplayDriver();
		virtual ~HalDisplayDriver();
	
		static void omap_venc_init(int mode);
		static void omap_beagle_init(void);
		static void omap_clock_init(void);
		static void omap_dss_init(void);
		static void omap_dispc_init(void);
		static void omap_disable_display(int vid);
		static void omap_set_lcd_mode(int w, int h, int d);
	
	public:		
		static void video_init(void);
		static void omap_attach_framebuffer(int id, struct BitMap *bm);
};

#endif /*HALDISPLAYDRIVER_H_*/
