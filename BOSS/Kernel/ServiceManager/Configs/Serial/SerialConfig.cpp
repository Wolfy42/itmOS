#include "SerialConfig.h"

SerialConfig::SerialConfig() : ServiceConfig() {
	initRegistersForMmuMapping();
}

SerialConfig::~SerialConfig() {}

void SerialConfig::initRegistersForMmuMapping(void) {
	// Control registers
	_registersForMmuMapping->push_back((address)UART1);
	_registersForMmuMapping->push_back((address)UART2);
	_registersForMmuMapping->push_back((address)UART3);

}
