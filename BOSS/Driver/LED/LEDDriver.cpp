#include <stdlib.h>

#include "LEDDriver.h"

LEDDriver::LEDDriver() {
}

LEDDriver::~LEDDriver() {
}

void LEDDriver::write(byte value[]) {
	LED led = (LED)value[0];
	LEDCommand cmd = (LEDCommand)value[1];
	switch (cmd) {
		case SWITCH_LED_ON:
			m_driver.ledOn(led);
			break;
		case SWITCH_LED_OFF:
			m_driver.ledOff(led);
			break;
		case TOGGLE_LED:
			m_driver.toggle(led);
			break;
		default:
			break;
	}
}
byte* LEDDriver::read(byte position[]) {
	LED led = (LED)position[0];
	byte* pointer;
	byte result[1];
	pointer = result;
	if (m_driver.isOn(led)) {
		result[0] = (byte)LED_ON;
	} else {
		result[0] = (byte)LED_OFF;
	}
	return pointer;
}
