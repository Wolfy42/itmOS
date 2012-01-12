#include "HalDisplayDriver.h"

HalDisplayDriver::HalDisplayDriver()
{
}

HalDisplayDriver::~HalDisplayDriver()
{
}


// ~~~~~~~~~~ STRUCTS AND STUFF ~~~~~~~~~~
struct video_mode {
	short width, height;
	char *name;
	uint32 dispc_size;
	uint32 dispc_timing_h;
	uint32 dispc_timing_v;
	uint32 dispc_divisor;
	uint32 dss_divisor;
};

// Master clock is 864 Mhz, and changing it is a pita since it cascades to other devices.
// Pixel clock is  864 / cm_clksel_dss.dss1_alwan_fclk / dispc_divisor.divisor.pcd
// So most of these modes are just approximate. List must be in ascending order.
struct video_mode modes[] = {
	// 640x480@72	31.500		640	24	40	128  	480	9	3	28
	{
		640, 480, "640x480-71",
		((480-1) << 16) | (640-1),
		(128 << DISPCB_HBP) | (24 << DISPCB_HFP) | (40 << DISPCB_HSW),
		(28 << DISPCB_VBP) | (9 << DISPCB_VFP) | (3 << DISPCB_VSW),
		2, 14
	},
	//	  800x600, 60Hz  	40.000  	800	40	128	88  	600	1	4	23
	{
		800, 600, "800x600-59",
		((600-1) << 16) | (800-1),
		(88 << DISPCB_HBP) | (40 << DISPCB_HFP) | (128 << DISPCB_HSW),
		(23 << DISPCB_VBP) | (1 << DISPCB_VFP) | (4 << DISPCB_VSW),
		2, 11
	},       	  
	// 1024x768, 60Hz  	65.000  	1024	24	136	160  	768	3	6	29
	{
		1024, 768, "1024x768-61",
		((768-1) << 16) | (1024-1),
		(160 << DISPCB_HBP) | (24 << DISPCB_HFP) | (136 << DISPCB_HSW),
		(29 << DISPCB_VBP) | (3 << DISPCB_VFP) | (6 << DISPCB_VSW),
		1, 13
	},
	{
		1280, 1024, "1280x1024-60",
		((1024-1) << 16) | (1280-1),
		(248 << DISPCB_HBP) | (48 << DISPCB_HFP) | (112 << DISPCB_HSW),
		(38 << DISPCB_VBP) | (1 << DISPCB_VFP) | (3 << DISPCB_VSW),
		1, 8
	},
};

/*
  Default video-encoder setup for NTSC and PAL from OMAP TRM S1.8.5.4
*/
struct {
	int reg;
	unsigned int mode[2];
} venc_setup[] = {
	{ VENC_VIDOUT_CTRL, 					{ 0x00000001, 0x00000001 } },
	{ VENC_LLEN, 							{ 0x00000359, 0x0000035F } },
	{ VENC_FLENS, 							{ 0x0000020C, 0x00000270 } },
	{ VENC_HFLTR_CTRL, 						{ 0x00000000, 0x00000000 } },
	{ VENC_CC_CARR_WSS_CARR,				{ 0x043F2631, 0x2F7225ED } },
	{ VENC_C_PHASE, 						{ 0x00000000, 0x00000000 } },
	{ VENC_GAIN_U, 							{ 0x00000102, 0x00000111 } },
	{ VENC_GAIN_V, 							{ 0x0000016C, 0x00000181 } },
	{ VENC_GAIN_Y, 							{ 0x0000012F, 0x00000140 } },
	{ VENC_BLACK_LEVEL, 					{ 0x00000043, 0x0000003B } },
	{ VENC_BLANK_LEVEL, 					{ 0x00000038, 0x0000003B } },
	{ VENC_X_COLOR, 						{ 0x00000007, 0x00000007 } },
	{ VENC_M_CONTROL, 						{ 0x00000001, 0x00000002 } },
	{ VENC_BSTAMP_WSS_DATA,					{ 0x00000038, 0x0000003F } },
	{ VENC_S_CARR, 							{ 0x21F07C1F, 0x2A098ACB } },
	{ VENC_LINE21, 							{ 0x00000000, 0x00000000 } },
	{ VENC_LN_SEL, 							{ 0x01310011, 0x01290015 } },
	{ VENC_L21_WC_CTL, 						{ 0x0000F003, 0x0000F603 } },
	{ VENC_HTRIGGER_VTRIGGER, 				{ 0x00000000, 0x00000000 } },
	{ VENC_SAVID_EAVID, 					{ 0x069300F4, 0x06A70108 } },
	{ VENC_FLEN_FAL, 						{ 0x0016020C, 0x00180270 } },
	{ VENC_LAL_PHASE_RESET, 				{ 0x00060107, 0x00040135 } },
	{ VENC_HS_INT_START_STOP_X, 			{ 0x008E0350, 0x00880358 } },
	{ VENC_HS_EXT_START_STOP_X, 			{ 0x000F0359, 0x000F035F } },
	{ VENC_VS_INT_START_X, 					{ 0x01A00000, 0x01A70000 } },
	{ VENC_VS_INT_STOP_X_VS_INT_START_Y, 	{ 0x020701A0, 0x000001A7 } },
	{ VENC_VS_INT_STOP_Y_VS_EXT_START_X, 	{ 0x01AC0024, 0x01AF0000 } },
	{ VENC_VS_EXT_STOP_X_VS_EXT_START_Y, 	{ 0x020D01AC, 0x000101AF } },
	{ VENC_VS_EXT_STOP_Y, 					{ 0x00000006, 0x00000025 } },
	{ VENC_AVID_START_STOP_X, 				{ 0x03480078, 0x03530083 } },
	{ VENC_AVID_START_STOP_Y, 				{ 0x02060024, 0x026C002E } },
	{ VENC_FID_INT_START_X_FID_INT_START_Y, { 0x0001008A, 0x0001008A } },
	{ VENC_FID_INT_OFFSET_Y_FID_EXT_START_X,{ 0x01AC0106, 0x002E0138 } },
	{ VENC_FID_EXT_START_Y_FID_EXT_OFFSET_Y,{ 0x01060006, 0x01380001 } },
	{ VENC_TVDETGP_INT_START_STOP_X, 		{ 0x00140001, 0x00140001 } },
	{ VENC_TVDETGP_INT_START_STOP_Y, 		{ 0x00010001, 0x00010001 } },
	{ VENC_GEN_CTRL, 						{ 0x00F90000, 0x00FF0000 } },
	{ VENC_OUTPUT_CONTROL, 					{ 0x0000000D, 0x0000000D } },	// s-video
	//{ VENC_OUTPUT_CONTROL, 				{ 0x0000000A, 0x0000000A } },	// composite
	{ VENC_OUTPUT_TEST, 					{ 0x00000000, 0x00000000 } },

	// S15.5.8.3 "The DSS.VENC_F_CONTROL and DSS.VENC_SYNC_CTRL registers must be
	//            the last ones to be changed by software."
	//{ VENC_F_CONTROL, 		{ 0x00000000, 0x00000000 } },
	{ VENC_SYNC_CTRL,	 					{ 0x00008040, 0x00000040 } },
	{ -1 }
};


// ~~~~~~~~~~ STATICS ~~~~~~~~~~~
static inline void Write32(void *base, unsigned int reg, unsigned int v) {
	*((volatile unsigned int *)((unsigned int)base+reg)) = v;
}

static inline uint32 Read32(void *base, unsigned int reg) {
	return *((volatile unsigned int *)((unsigned int)base+reg));
}

static inline void Set32(void *base, unsigned int reg, unsigned int m, unsigned int v) {
	unsigned int o;

	o = *((volatile unsigned int *)((unsigned int)base+reg));
	o &= ~m;
	o |= v;
	*((volatile unsigned int *)((unsigned int)base+reg)) = o;
}


// ~~~~~~~~~~ PUBLIC ~~~~~~~~~~
void HalDisplayDriver::video_init(void) {
	Write32(DISPC_BASE, DISPC_IRQENABLE, 0x00000);
	Write32(DISPC_BASE, DISPC_IRQSTATUS, 0x1ffff);

	omap_clock_init();
	omap_dss_init();

	omap_venc_init(VENC_MODE_PAL);
	omap_dispc_init();

	omap_set_lcd_mode(1024, 768, 16);
}

// set a bitmap on the given video source
// vid 0 = gfx, 1 = vid1, 2 = vid2
void HalDisplayDriver::omap_attach_framebuffer(int id, struct BitMap *bm) {
	void *DISPC = DISPC_BASE;

	// FIXME: other formats than RGB16 taken from bitmap
	// Centre graphics on display for now
	uint32 vsize = Read32(DISPC, DISPC_SIZE_LCD);
	int pv = ((vsize >> 16) + 1 - bm->height) / 2;
	int ph = ((vsize & 0xffff) + 1 - bm->width) / 2;

	ph = ph < 0 ? 0 : ph;
	pv = pv < 0 ? 0 : pv;

	uint32 gsize = ((bm->height-1)<<16) | (bm->width-1);

	switch (id) {
	case 0:
		Write32(DISPC, DISPC_GFX_BA0, (uint32)bm->data);
		Write32(DISPC, DISPC_GFX_BA1, (uint32)bm->data);
		Write32(DISPC, DISPC_GFX_POSITION, (pv<<16) | ph);
		Write32(DISPC, DISPC_GFX_SIZE, gsize);
		Write32(DISPC, DISPC_GFX_FIFO_THRESHOLD, (0x3ff << 16) | 0x3c0);
		Write32(DISPC, DISPC_GFX_ROW_INC, 1);
		Write32(DISPC, DISPC_GFX_PIXEL_INC, 1);
		Write32(DISPC, DISPC_GFX_WINDOW_SKIP, 0);
		Write32(DISPC, DISPC_GFX_ATTRIBUTES,
			DISPC_GFXFORMAT_RGB16
			| DISPC_GFXBURSTSIZE_16x32
			| DISPC_GFXENABLE);
		break;
	case 1:	// TODO: video scaling? or use another function probably
		Write32(DISPC, DISPC_VID1_BA0, (uint32)bm->data);
		Write32(DISPC, DISPC_VID1_BA1, (uint32)bm->data);
		Write32(DISPC, DISPC_VID1_POSITION, (pv<<16) | ph);
		Write32(DISPC, DISPC_VID1_SIZE, gsize);
		Write32(DISPC, DISPC_VID1_PICTURE_SIZE, gsize);
		Write32(DISPC, DISPC_VID1_FIFO_THRESHOLD, (0x3ff << 16) | 0x3c0);
		Write32(DISPC, DISPC_VID1_ROW_INC, 1);
		Write32(DISPC, DISPC_VID1_PIXEL_INC, 1);

		Write32(DISPC, DISPC_VID1_ATTRIBUTES,
			//DISPC_VIDFORMAT_RGB16
			DISPC_VIDFORMAT_UYVY
			| DISPC_VIDBURSTSIZE_16x32
			| DISPC_VIDENABLE);
		break;
	case 2:
		Write32(DISPC, DISPC_VID2_BA0, (uint32)bm->data);
		Write32(DISPC, DISPC_VID2_BA1, (uint32)bm->data);
		Write32(DISPC, DISPC_VID2_POSITION, (pv<<16) | ph);
		Write32(DISPC, DISPC_VID2_SIZE, gsize);
		Write32(DISPC, DISPC_VID2_PICTURE_SIZE, gsize);
		Write32(DISPC, DISPC_VID2_FIFO_THRESHOLD, (0x3ff << 16) | 0x3c0);
		Write32(DISPC, DISPC_VID2_ROW_INC, 1);
		Write32(DISPC, DISPC_VID2_PIXEL_INC, 1);
		Write32(DISPC, DISPC_VID2_ATTRIBUTES,
			//DISPC_VIDFORMAT_RGB16
			DISPC_VIDFORMAT_ARGB16
			| DISPC_VIDBURSTSIZE_16x32
			| DISPC_VIDENABLE);
		break;
	}

	// Tell hardware to update, and wait for it
	Set32(DISPC, DISPC_CONTROL,
	      DISPC_GOLCD,
	      DISPC_GOLCD);

	while ((Read32(DISPC, DISPC_CONTROL) & DISPC_GOLCD))
		;
}


// ~~~~~~~~~~ PRIVATE ~~~~~~~~~~

// init video encoder.
// by default just show test pattern
// This doesn't work
void HalDisplayDriver::omap_venc_init(int mode) {
	void *VENC = VENC_BASE;
	int i;

	Write32(VENC, VENC_F_CONTROL, VENC_RESET);
	while (Read32(VENC, VENC_F_CONTROL) & VENC_RESET)

	for (i = 0; venc_setup[i].reg != -1; i++)
		Write32(VENC, venc_setup[i].reg, venc_setup[i].mode[mode]);

	// set a test pattern only
	Write32(VENC, VENC_F_CONTROL, VENC_SVDS_COLOURBAR | (7<<2));
}

// init beagle gpio for video
void HalDisplayDriver::omap_beagle_init(void) {
	// setup GPIO stuff, i can't find any references to these
	Write32(GPIO1_BASE, GPIO_OE, 0xfefffedf);
	Write32(GPIO1_BASE, GPIO_SETDATAOUT, 0x01000120);
	// DVI-D is enabled by GPIO 170?
}

void HalDisplayDriver::omap_clock_init(void) {
	// sets pixel clock to 72MHz

	// sys_clk = 26.0 Mhz
	// DPLL4 = sys_clk * 432 / 13 = 864
	// DSS1_ALWON_FCLK = 864 / 6 = 144
	// Pixel clock (DISPC_DIVISOR) = 144 / 2 = 72Mhz
	// and also VENC clock = 864 / 16 = 54MHz

	// The clock multiplier/divider cannot be changed
	// without affecting other system clocks - so don't.

	// pll4 clock multiplier/divider
	Write32(CM_CLOCK_BASE, CM_CLKSEL2_PLL, (432 << 8) | 12);
	// tv clock divider, dss1 alwon fclk divider
	//Write32(CM_DSS_BASE, CM_CLKSEL_DSS, (16 << 8) | 6);
	Write32(CM_DSS_BASE, CM_CLKSEL_DSS, (16 << 8) | 7);
	// core/peripheral PLL to 1MHz
	Write32(CM_CLOCK_BASE, CM_CLKEN_PLL, 0x00370037);
}

void HalDisplayDriver::omap_dss_init(void) {
	Write32(DSS_BASE, DSS_SYSCONFIG, DSS_AUTOIDLE);
	// Select DSS1 ALWON as clock source
	Write32(DSS_BASE, DSS_CONTROL, DSS_VENC_OUT_SEL | DSS_DAC_POWERDN_BGZ | DSS_DAC_DEMEN | DSS_VENC_CLOCK_4X_ENABLE);
}

void HalDisplayDriver::omap_dispc_init(void) {
	void *DISPC = DISPC_BASE;

	Write32(DISPC, DISPC_SYSCONFIG,
		DISPC_MIDLEMODE_SMART
		| DISPC_SIDLEMODE_SMART
		| DISPC_ENWAKEUP
		| DISPC_AUTOIDLE);

	Write32(DISPC, DISPC_CONFIG, DISPC_LOADMODE_FRAME);

	// LCD default = CBM blue
	Write32(DISPC, DISPC_DEFAULT_COLOR0, 0x7c70da);
	// digital default = black
	Write32(DISPC, DISPC_DEFAULT_COLOR1, 0x000000);

	Write32(DISPC, DISPC_TRANS_COLOR0, 0x000000);
	Write32(DISPC, DISPC_TRANS_COLOR1, 0x000000);

	Write32(DISPC, DISPC_POL_FREQ,
		DISPC_POL_IPC
		| DISPC_POL_IHS
		| DISPC_POL_IVS
		| (2<<DISPCB_POL_ACBI)
		| (8<<DISPCB_POL_ACB));

	// Set pixel clock divisor = 2
	Write32(DISPC, DISPC_DIVISOR,
		(1<<DISPCB_DIVISOR_LCD)
		| (2<<DISPCB_DIVISOR_PCD));

	// Set digital size (used for tv out)
	Write32(DISPC, DISPC_SIZE_DIG,
		(286 << 16) | 719);

	// Disable graphical output
	Write32(DISPC, DISPC_GFX_ATTRIBUTES, 0);

	// Set palette / gamma table address ??
	//Write32(DISPC, DISPC_GFX_TABLE_BA, FB_ADDRESS);

	// Set colour conversion coefficients for YUV modes
	// this is BT.601-5, see Table 15-47  S 15.5.3.3
	Write32(DISPC, DISPC_VID1_CONV_COEF0, 296 | (409 << 16));
	Write32(DISPC, DISPC_VID1_CONV_COEF1, 0 | (298 << 16));
	Write32(DISPC, DISPC_VID1_CONV_COEF2, ((-208) & 0xffff) | (-100 << 16));
	Write32(DISPC, DISPC_VID1_CONV_COEF3, 298 | (0<<16));
	Write32(DISPC, DISPC_VID1_CONV_COEF4, 517);

	Write32(DISPC, DISPC_VID2_CONV_COEF0, 296 | (409 << 16));
	Write32(DISPC, DISPC_VID2_CONV_COEF1, 0 | (298 << 16));
	Write32(DISPC, DISPC_VID2_CONV_COEF2, ((-208) & 0xffff) | (-100 << 16));
	Write32(DISPC, DISPC_VID2_CONV_COEF3, 298 | (0<<16));
	Write32(DISPC, DISPC_VID2_CONV_COEF4, 517);

	// Turn on the LCD data
	Write32(DISPC, DISPC_CONTROL,
		DISPC_GPOUT1
		| DISPC_GPOUT0
		| DISPC_TFTDATALINES_24
		| DISPC_STDITHERENABLE
		| DISPC_GOLCD
		| DISPC_STNTFT
		| DISPC_LCDENABLE
		);

	while ((Read32(DISPC, DISPC_CONTROL) & DISPC_GOLCD))
		;
}

void HalDisplayDriver::omap_disable_display(int vid) {
	switch (vid) {
	case 0:
		Set32(DISPC_BASE, DISPC_GFX_ATTRIBUTES, DISPC_GFXENABLE, 0);
		break;
	case 1:
		Set32(DISPC_BASE, DISPC_VID1_ATTRIBUTES, DISPC_VIDENABLE, 0);
		break;
	case 2:
		Set32(DISPC_BASE, DISPC_VID2_ATTRIBUTES, DISPC_VIDENABLE, 0);
		break;
	}
}

void HalDisplayDriver::omap_set_lcd_mode(int w, int h, int d) {
	void *DISPC = DISPC_BASE;
	int i;
	struct video_mode *m;

	for (i=0;i<sizeof(modes)/sizeof(modes[0]);i++) {
		if (w <= modes[i].width 
		    && h <= modes[i].height)
		goto found;
	}
	i -= 1;
found:
	m = &modes[i];

	Write32(DISPC, DISPC_SIZE_LCD, m->dispc_size);
	Write32(DISPC, DISPC_TIMING_H, m->dispc_timing_h);
	Write32(DISPC, DISPC_TIMING_V, m->dispc_timing_v);

	Set32(DISPC, DISPC_DIVISOR, 0xffff, m->dispc_divisor);
	Set32(CM_DSS_BASE, CM_CLKSEL_DSS, 0xffff, m->dss_divisor);

	// Tell hardware to update, and wait for it
	Set32(DISPC, DISPC_CONTROL,
	      DISPC_GOLCD,
	      DISPC_GOLCD);

	while ((Read32(DISPC, DISPC_CONTROL) & DISPC_GOLCD))
		;
}
