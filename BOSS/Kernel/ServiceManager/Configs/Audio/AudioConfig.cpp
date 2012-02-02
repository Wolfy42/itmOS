
#include "AudioConfig.h"

AudioConfig::AudioConfig() : ServiceConfig()  {
	initRegistersForMmuMapping();
}

AudioConfig::~AudioConfig()  {}

void AudioConfig::initRegistersForMmuMapping(void) {

	_registersForMmuMapping->push_back(CONTROL_GENERAL_BASE);
	_registersForMmuMapping->push_back(PER_CM_BASE);
	_registersForMmuMapping->push_back(MCBSP1_BASE);
	_registersForMmuMapping->push_back(MCBSP2_BASE);
	_registersForMmuMapping->push_back(I2C1_BASE);
}
