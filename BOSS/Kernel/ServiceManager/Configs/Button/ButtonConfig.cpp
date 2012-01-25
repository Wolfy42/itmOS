#include "ButtonConfig.h"

ButtonConfig::ButtonConfig() : ServiceConfig() {
	initRegistersForMmuMapping();
}

ButtonConfig::~ButtonConfig() {}

void ButtonConfig::initRegistersForMmuMapping(void) {

    _registersForMmuMapping->push_back((address)0x48004C00);
	_registersForMmuMapping->push_back(BUTTON_CONTROL_GPIO_BASE);
	_registersForMmuMapping->push_back(BUTTON_GPIO_BASE);
}
