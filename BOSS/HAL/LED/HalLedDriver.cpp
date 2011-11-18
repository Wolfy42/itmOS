#include "HalLedDriver.h"

#include "HAL/gpio.h"

#define LED1_REG 21
#define LED2_REG 22

HalLedDriver HalLedDriver::LED_DRIVER = HalLedDriver();

HalLedDriver::HalLedDriver(): m_led1(149), m_led2(150) {
}

HalLedDriver::~HalLedDriver() {
}

LEDClass HalLedDriver::ledClassForEnum(LED ledEnum) {
	switch (ledEnum) {
		case LED1:
			return m_led1;
		case LED2:
			return m_led2;
		default:
			return m_led1;
	}
}


void HalLedDriver::init() {
}

void HalLedDriver::ledOn(LED led) {
	HalLedDriver::LED_DRIVER.ledClassForEnum(led).switchOn();
}

void HalLedDriver::ledOff(LED led) {
	HalLedDriver::LED_DRIVER.ledClassForEnum(led).switchOff();
}
void HalLedDriver::toggle(LED led) {
	HalLedDriver::LED_DRIVER.ledClassForEnum(led).toggle();
}
bool HalLedDriver::isOn(LED led) {
	return HalLedDriver::LED_DRIVER.ledClassForEnum(led).isOn();
}
