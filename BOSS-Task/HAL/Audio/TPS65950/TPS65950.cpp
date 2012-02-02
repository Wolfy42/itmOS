/*
 * TPS65950.cpp
 *
 *  Created on: Dec 21, 2011
 *      Author: stefan
 */

#include "HAL/Audio/TPS65950/TPS65950.h"
#include "HAL/Audio/TPS65950/TPS65950SCD.h"
#include "HAL/Audio/I2C/I2C.h"
#include "Lib/bitOperations.h"

TPS65950::TPS65950() {}
TPS65950::~TPS65950() {}

// helper function to write audio registers
void TPS65950::audioRegW(uint32_t address, uint32_t value) {
	i2c_write8(I2C1_BASE, SCD_AUDIO_VOICE, address, value);
}

// registers
void TPS65950::init_tps65950() {

	// turn it off to configure
	audioRegW(AV_CODEC_MODE, 0);

	// page 725
	// Audio mode: Select sampling frequence (Fs) -> set to 8 kHz
	// Audio and voice option selection: Option 1: 2 RX and TX stereo audio paths
	audioRegW(AV_CODEC_MODE, APPL_RATE_8 | OPT_MODE);

	// Audio/voice digital filter power control
	audioRegW(AV_OPTION, ARXR2_EN | ARXL2_EN | ATXR1_EN | ATXL1_EN);

	// path selection
	audioRegW(AV_RX_PATH_SEL,  B_RXL1_SEL | B_RXR1_SEL);

	// set system clock speed and enable the local clock
	audioRegW(AV_APLL_CTL, APLL_EN | APLL_INFREQ_26);

	// left/right dacs enlabled
	audioRegW(AV_AVDAC_CTL, ADACL2_EN | ADACR2_EN);

	// turn on left and right output
	audioRegW(AV_ARXL2_APGA_CTL, ARX1_PDZ | ARX1_DA_EN | (0x06 << B_ARX1_GAIN_SET));
	audioRegW(AV_ARXR2_APGA_CTL, ARX1_PDZ | ARX1_DA_EN | (0x06 << B_ARX1_GAIN_SET));

	// headset output
	audioRegW(AV_HS_SEL, HSOL_AL2_EN | HSOR_AR2_EN);

	// set digital gain to 0db
	audioRegW(AV_ARXL2PGA, 0x30 | (3<<6));              /* 0dB */
	audioRegW(AV_ARXR2PGA, 0x30 | (3<<6));              /* 0dB */

	// set headset left/right gain (balance) to 0db each
	audioRegW(AV_HS_GAIN_SET, 0x0a);

	// audio interface.  master mode, i2s format, 16 bit data
	audioRegW(AV_AUDIO_IF, AIF_FORMAT_CODEC | DATA_WIDTH_16 | AIF_EN);

	// volume/effects
	// set base boost effect
	audioRegW(AV_BOOST_CTL, 0);
	// anti-pop paramters
	audioRegW(AV_HS_POPN_SET, VMID_EN | RAMP_DELAY_161ms | RAMP_EN);

	// tramsit settings (audio in)
	// left/right gain
	audioRegW(AV_ATXL1PGA, 0x0);
	audioRegW(AV_ATXR1PGA, 0x0);

	// left/right ADC, and choose as TXx1
	audioRegW(AV_AVADC_CTL, ADCL_EN | ADCR_EN);
	audioRegW(AV_ADCMICSEL, 0);

	// line in on beagle comes from AUX, also enable anti-pop and start
	audioRegW(AV_ANAMICL, 0x34 | AUXL_EN | OFFSET_CNCL_SEL_RXALL | CNCL_OFFSET_START);
	audioRegW(AV_ANAMICR, 0x14 | AUXR_EN);
	audioRegW(AV_ANAMIC_GAIN, (0<<3)|0);

	// now power it up, with sample rate and option 1 (2x stereo audio paths in and out)
	audioRegW(AV_CODEC_MODE, APPL_RATE_8 | 0 | OPT_MODE);
	audioRegW(AV_CODEC_MODE, APPL_RATE_48 | CODECPDZ | OPT_MODE);
}
