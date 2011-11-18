#include <stdlib.h>

#include "LEDDriver.h"

LEDDriver::LEDDriver(): Driver() {
}

LEDDriver::~LEDDriver() {
}

void LEDDriver::init() {
	
}
void LEDDriver::write(byte value[]) {
	LED led = (LED)value[0];
	LEDCommand cmd = (LEDCommand)value[1];
	switch (cmd) {
		case SWITCH_LED_ON:
			HalLedDriver::ledOn(led);
			break;
		case SWITCH_LED_OFF:
			HalLedDriver::ledOff(led);
			break;
		case TOGGLE_LED:
			HalLedDriver::toggle(led);
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
	if (HalLedDriver::isOn(led)) {
		result[0] = (byte)LED_ON;
	} else {
		result[0] = (byte)LED_OFF;
	}
	return pointer;
}
