#include "SerialConfig.h"
#include "Tasks/Services/Serial/SerialService.h"

SerialConfig::SerialConfig() : ServiceConfig() {}
SerialConfig::~SerialConfig() {}

char* SerialConfig::getServiceName(void) {
	return "Serial_Service\0";
}

int SerialConfig::getInitAddress(void) {
	return (int)SerialService::main;
}

void SerialConfig::initRegistersForMmuMapping(void) {
	// Control registers

	
	// GPIO registers

}
