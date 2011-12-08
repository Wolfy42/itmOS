#include "HalLedDriver.h"

#include "HAL/gpio.h"

#define LED1_REG 21
#define LED2_REG 22

HalLedDriver::HalLedDriver(): _led1(149), _led2(150) {
}

HalLedDriver::~HalLedDriver() {
}

LEDClass HalLedDriver::ledClassForEnum(LED ledEnum) {
	switch (ledEnum) {
		case LED1:
			return _led1;
		case LED2:
			return _led2;
		default:
			return _led1;
	}
}


void HalLedDriver::init() {
}

void HalLedDriver::ledOn(LED led) {
	ledClassForEnum(led).switchOn();
}

void HalLedDriver::ledOff(LED led) {
	ledClassForEnum(led).switchOff();
}
void HalLedDriver::toggle(LED led) {
	ledClassForEnum(led).toggle();
}
bool HalLedDriver::isOn(LED led) {
	return ledClassForEnum(led).isOn();
}

