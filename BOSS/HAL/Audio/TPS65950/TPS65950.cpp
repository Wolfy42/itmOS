/*
 * TPS65950.cpp
 *
 *  Created on: Dec 21, 2011
 *      Author: stefan
 */

#include "HAL/Audio/TPS65950/TPS65950.h"
#include "HAL/Audio/TPS65950/TPS65950SCD.h"
#include "HAL/I2C/I2C.h"
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









}
