/*  omap3-video.h: OMAP3 Video registers

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
#ifndef VIDEO_H_
#define VIDEO_H_

/* OMAP video related registers */

/* ********************************************************************** */
/* GPIO registers - to be moved elsewhere */
#define GPIO1_BASE 		((void*)0x48310000)
#define GPIO_OE 		0x034
#define GPIO_DATAOUT 	0x03C
#define GPIO_SETDATAOUT 0x094

/* ********************************************************************** */
/* Clock management registers - to be moved elsewhere */
#define CM_DSS_BASE 		((void *)0x48004E00)
#define CM_CLKSEL_DSS 		0x00000040

#define CM_CLOCK_BASE 		((void *)0x48004D00)
#define CM_CLKEN_PLL 		0x00000000
#define CM_CLKSEL2_PLL 		0x00000044

/* ********************************************************************** */
/* S 1.7.2 Display Subsystem & SDI Registers */

#define DSS_BASE 		((void *)0x48050000)
#define DSS_SYSCONFIG 	0x010
#define DSS_CONTROL 	0x040

///* SYSCONFIG bits */
#define DSS_AUTOIDLE 	1
#define DSS_SOFTRESET 	2

///* CONTROL bits */
#define DSS_VENC_OUT_SEL 			(1<<6)	/* set s-video */
#define DSS_DAC_POWERDN_BGZ 		(1<<5)
#define DSS_DAC_DEMEN 				(1<<4)
#define DSS_VENC_CLOCK_4X_ENABLE 	(1<<3)

/* ********************************************************************** */
/* S 1.7.3 Display controller */

#define DISPC_BASE ((void *)0x48050400)
#define DISPC_SYSCONFIG 0x010
#define DISPC_IRQSTATUS 0x018
#define DISPC_IRQENABLE 0x01C
#define DISPC_CONTROL 0x040
#define DISPC_CONFIG 0x044
#define DISPC_DEFAULT_COLOR0 0x04c
#define DISPC_DEFAULT_COLOR1 0x050
#define DISPC_TRANS_COLOR0 0x54
#define DISPC_TRANS_COLOR1 0x58
#define DISPC_TIMING_H 0x064
#define DISPC_TIMING_V 0x068
#define DISPC_POL_FREQ 0x06C
#define DISPC_DIVISOR 0x070
#define DISPC_SIZE_DIG 0x078
#define DISPC_SIZE_LCD 0x07C

#define DISPC_GFX_BA0 0x080
#define DISPC_GFX_BA1 0x084
#define DISPC_GFX_POSITION 0x088
#define DISPC_GFX_SIZE 0x08C
#define DISPC_GFX_ATTRIBUTES 0x0A0
#define DISPC_GFX_FIFO_THRESHOLD 0x0A4
#define DISPC_GFX_ROW_INC 0x0AC
#define DISPC_GFX_PIXEL_INC 0x0B0
#define DISPC_GFX_WINDOW_SKIP 0x0B4

#define DISPC_VID1_BA0 0x0BC
#define DISPC_VID1_BA1 0x0C0
#define DISPC_VID2_BA0 0x14C
#define DISPC_VID2_BA1 0x150

#define DISPC_VID1_POSITION 0x0C4
#define DISPC_VID2_POSITION (0x0C4+0x90)
#define DISPC_VID1_SIZE 0x0C8
#define DISPC_VID2_SIZE (0x0C8+0x90)
#define DISPC_VID1_ATTRIBUTES 0x0CC
#define DISPC_VID2_ATTRIBUTES (0x0CC+0x90)

#define DISPC_VID1_FIFO_THRESHOLD 0x0D0
#define DISPC_VID2_FIFO_THRESHOLD (0x0D0+0x90)
#define DISPC_VID1_ROW_INC 0x0D8
#define DISPC_VID2_ROW_INC (0x0D8+0x90)
#define DISPC_VID1_PIXEL_INC 0x0DC
#define DISPC_VID2_PIXEL_INC (0x0DC+0x90)

#define DISPC_VID1_PICTURE_SIZE 0x0E4
#define DISPC_VID2_PICTURE_SIZE (0x0E4+0x90)

#define DISPC_VID1_CONV_COEF0 0x130
#define DISPC_VID2_CONV_COEF0 (0x130+0x90)
#define DISPC_VID1_CONV_COEF1 0x134
#define DISPC_VID2_CONV_COEF1 (0x134+0x90)
#define DISPC_VID1_CONV_COEF2 0x138
#define DISPC_VID2_CONV_COEF2 (0x138+0x90)
#define DISPC_VID1_CONV_COEF3 0x13C
#define DISPC_VID2_CONV_COEF3 (0x13C+0x90)
#define DISPC_VID1_CONV_COEF4 0x140
#define DISPC_VID2_CONV_COEF4 (0x140+0x90)

/* DISPC_SYSCONFIG bits */
#define DISPC_MIDLEMODE_SMART (2<<12)
#define DISPC_SIDLEMODE_SMART (2<<3)
#define DISPC_ENWAKEUP (1<<2)
#define DISPC_AUTOIDLE (1<<0)

/* DISPC_CONTROL bits (incomplete) */
#define DISPC_GPOUT1 (1<<16)
#define DISPC_GPOUT0 (1<<15)
#define DISPC_TFTDATALINES_24 (3<<8)
#define DISPC_STDITHERENABLE (1<<7)
#define DISPC_GOLCD (1<<5)
#define DISPC_STNTFT (1<<3)
#define DISPC_LCDENABLE (1<<0)

/* DISPC_CONFIG bits */
#define DISPC_LOADMODE_FRAME (2<<1)

/* DISPC_TIMING_H bits and masks */
#define DISPCB_HBP 20
#define DISPCB_HFP 8
#define DISPCB_HSW 0

/* DISPC_TIMING_V bits and masks */
#define DISPCB_VBP 20
#define DISPCB_VFP 8
#define DISPCB_VSW 0

/* DISPC_POL_FREQ bits */
#define DISPC_POL_IPC (1<<14)
#define DISPC_POL_IHS (1<<13)
#define DISPC_POL_IVS (1<<12)
#define DISPCB_POL_ACBI 8
#define DISPCB_POL_ACB 0

/* DISPC_DIVISOR bits */
#define DISPCB_DIVISOR_LCD 16
#define DISPCB_DIVISOR_PCD 0

/* DISPC_GFX_ATTRIBUTES bits */
#define DISPC_GFXBURSTSIZE_16x32 (2<<6)
#define DISPC_GFXFORMAT_RGB16 (6<<1)
#define DISPC_GFXENABLE 1

/* DISPC_VIDn_ATTRIBUTES bits */
#define DISPC_VIDBURSTSIZE_16x32 (2<<14)

// Only VID2 supports the alpha formats
#define DISPC_VIDFORMAT_ARGB16 (5<<1)
#define DISPC_VIDFORMAT_UYVY (11<<1)
#define DISPC_VIDENABLE 1

/* TODO: video attributes, etc */

/* ********************************************************************** */
/* S 1.7.5 Video Encoder Registers */

#define VENC_BASE ((void *)0x48050c00)
#define VENC_STATUS 0x04
#define VENC_F_CONTROL 0x08
#define VENC_VIDOUT_CTRL 0x10
#define VENC_SYNC_CTRL 0x14
#define VENC_LLEN 0x1C
#define VENC_FLENS 0x20
#define VENC_HFLTR_CTRL 0x24
#define VENC_CC_CARR_WSS_CARR 0x28
#define VENC_C_PHASE 0x2C
#define VENC_GAIN_U 0x30
#define VENC_GAIN_V 0x34
#define VENC_GAIN_Y 0x38
#define VENC_BLACK_LEVEL 0x3C
#define VENC_BLANK_LEVEL 0x40
#define VENC_X_COLOR 0x44
#define VENC_M_CONTROL 0x48
#define VENC_BSTAMP_WSS_DATA 0x4C
#define VENC_S_CARR 0x50
#define VENC_LINE21 0x54
#define VENC_LN_SEL 0x58
#define VENC_L21_WC_CTL 0x5C
#define VENC_HTRIGGER_VTRIGGER 0x60
#define VENC_SAVID_EAVID 0x64
#define VENC_FLEN_FAL 0x68
#define VENC_LAL_PHASE_RESET 0x6C
#define VENC_HS_INT_START_STOP_X 0x70
#define VENC_HS_EXT_START_STOP_X 0x74
#define VENC_VS_INT_START_X 0x78
#define VENC_VS_INT_STOP_X_VS_INT_START_Y 0x7C
#define VENC_VS_INT_STOP_Y_VS_EXT_START_X 0x80
#define VENC_VS_EXT_STOP_X_VS_EXT_START_Y 0x84
#define VENC_VS_EXT_STOP_Y 0x88
#define VENC_AVID_START_STOP_X 0x90
#define VENC_AVID_START_STOP_Y 0x94
#define VENC_FID_INT_START_X_FID_INT_START_Y 0xA0
#define VENC_FID_INT_OFFSET_Y_FID_EXT_START_X 0xA4
#define VENC_FID_EXT_START_Y_FID_EXT_OFFSET_Y 0xA8
#define VENC_TVDETGP_INT_START_STOP_X 0xB0
#define VENC_TVDETGP_INT_START_STOP_Y 0xB4
#define VENC_GEN_CTRL 0xB8
#define VENC_OUTPUT_CONTROL 0xC4
#define VENC_OUTPUT_TEST 0xC8

/* VENC_F_CONTROL bits */
#define VENC_RESET (1<<8)
#define VENC_SVDS_COLOURBAR (1<<6)

#endif /*VIDEO_H_*/
