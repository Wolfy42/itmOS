#include "LEDConfig.h"

LEDConfig::LEDConfig() : ServiceConfig() {
	initRegistersForMmuMapping();
}

LEDConfig::~LEDConfig() {}

void LEDConfig::initRegistersForMmuMapping(void) {

	_registersForMmuMapping->push_back(CONTROL_GPIO_BASE);
	_registersForMmuMapping->push_back(GPIO_BASE);
}
