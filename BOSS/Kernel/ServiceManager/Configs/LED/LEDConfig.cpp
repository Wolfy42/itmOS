#include "LEDConfig.h"

LEDConfig::LEDConfig() : ServiceConfig() {
	initRegistersForMmuMapping();
}

LEDConfig::~LEDConfig() {}

void LEDConfig::initRegistersForMmuMapping(void) {
	// Control registers
	_registersForMmuMapping->push_back(CONTROL_GPIO_149);
	_registersForMmuMapping->push_back(CONTROL_GPIO_150);
	
	// GPIO registers
	_registersForMmuMapping->push_back(GPIO_OE_GPIO5);
	_registersForMmuMapping->push_back(GPIO_DATAOUT_GPIO5);
	_registersForMmuMapping->push_back(GPIO_CLEARDATAOUT_GPIO5);
	_registersForMmuMapping->push_back(GPIO_SETDATAOUT_GPIO5);
}
