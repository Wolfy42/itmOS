#include <stdio.h>
#include "LEDService.h"

LEDService::LEDService(): Service(), _running(false) {
}

LEDService::~LEDService() {
}
void LEDService::switchLEDOn(LED led) {
	byte value[] = {led, SWITCH_LED_ON};
	_driver.write(value);
}

void LEDService::switchLEDOff(LED led) {
	byte value[] = {led, SWITCH_LED_OFF};
	_driver.write(value);
}
void LEDService::toggleLED(LED led) {
	byte value[] = {led, TOGGLE_LED};
	_driver.write(value);
}

LEDState LEDService::getLEDState(LED led) {
	byte position[] = {led};
	return (LEDState)_driver.read(position)[0];
}

byte* LEDService::readInput() {
	// Dummy wait for input
	static int run = 0;
	byte result[2];
	for (int i = 0; i < 100000; i++);
	switch (run) {
		case 0:
			result[0] = (byte)LED1;
			result[1] = (byte)SERVICE_GET_LED_STATUS;
			break;
		case 1:
			result[0] = (byte)LED1;
			result[1] = (byte)SERVICE_TOGGLE_LED;
			break;
		case 2:
			result[0] = (byte)LED1;
			result[1] = (byte)SERVICE_GET_LED_STATUS;
			break;
		case 3:
			result[0] = (byte)LED1;
			result[1] = (byte)SERVICE_SWITCH_LED_OFF;
			break;
		case 4:
			result[0] = (byte)LED1;
			result[1] = (byte)SERVICE_GET_LED_STATUS;
			break;
		case 5:
			result[0] = (byte)LED2;
			result[1] = (byte)SERVICE_GET_LED_STATUS;
			break;
		case 6:
			result[0] = (byte)LED2;
			result[1] = (byte)SERVICE_SWITCH_LED_ON;
			break;
		case 7:
			result[0] = (byte)LED2;
			result[1] = (byte)SERVICE_GET_LED_STATUS;
			break;
		case 8:
			result[0] = (byte)LED2;
			result[1] = (byte)SERVICE_SWITCH_LED_OFF;
			break;
		default:
			result[0] = (byte)LED2;
			result[1] = (byte)SERVICE_GET_LED_STATUS;
			run = -1;
			break;
	}
	run++;
	byte* pointer = result;
	return pointer;
}
void LEDService::start() {
	_running = true;
	while (_running) {
		byte* cmd = readInput();
		LED led = (LED)cmd[0];
		LEDServiceCommand command = (LEDServiceCommand)cmd[1];
		switch (command) {
			case SERVICE_SWITCH_LED_OFF:
				printf("Switch LED%i off\n", led+1);
				switchLEDOff(led);
				break;
			case SERVICE_SWITCH_LED_ON:
				printf("Switch LED%i on\n", led+1);
				switchLEDOn(led);
				break;
			case SERVICE_TOGGLE_LED:
				printf("Toggle LED%i\n", led+1);
				toggleLED(led);
				break;
			case SERVICE_GET_LED_STATUS:
				LEDState state = getLEDState(led);
				// TODO give state back
				printf("State of LED%i: %i\n", led+1, state);
				break;
		}
	}
}
bool LEDService::stop() {
	_running = false;
	// TODO interrupt wait for input
	return true;
}

