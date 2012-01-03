/*
 * TPS65950SCD.h
 *
 * TPS65950 System Companion Device
 *
 * TPS65950 OMAP™ Power Management and System Companion Device ES 1.2 TRM (Rev. G)
 * http://www.ti.com/product/tps65950
 *
 *  Created on: Dec 22, 2011
 *      Author: stefan
 */

#ifndef TPS65950SCD_H_
#define TPS65950SCD_H_

// I2C addresses of audio-voice
#define SCD_AUDIO_VOICE		0x49

// AUDIO_VOICE registers
#define AV_CODEC_MODE 		0x00000001
#define AV_OPTION 			0x00000002

// CODEC_MODE settings
#define APPL_RATE_8			(0<<4)
#define OPT_MODE			1

#endif /* TPS65950SCD_H_ */
