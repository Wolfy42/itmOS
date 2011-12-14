#include "LEDConfig.h"
#include "Tasks/Services/LED/LEDService.h"

LEDConfig::LEDConfig() : ServiceConfig() {}
LEDConfig::~LEDConfig() {}

char* LEDConfig::getServiceName(void) {
	return "LED_Service\0";
}

int LEDConfig::getInitAddress(void) {
	return (int)LEDService::main;
}

void LEDConfig::initRegistersForMmuMapping(void) {
	// Control registers
	_registersForMmuMapping.push_back(CONTROL_GPIO_149);
	_registersForMmuMapping.push_back(CONTROL_GPIO_150);
	
	// GPIO registers
	_registersForMmuMapping.push_back(GPIO_OE_GPIO5);
	_registersForMmuMapping.push_back(GPIO_DATAOUT_GPIO5);
	_registersForMmuMapping.push_back(GPIO_CLEARDATAOUT_GPIO5);
	_registersForMmuMapping.push_back(GPIO_SETDATAOUT_GPIO5);
}
