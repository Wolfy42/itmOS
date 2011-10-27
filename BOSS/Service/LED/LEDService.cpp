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

void LEDService::start() {
	_running = true;
	while (_running) {
		byte* cmd = readCommand(LED_SERVICE_CALL);
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
				byte result[] = {led, state};
				writeResponse(result);
				break;
		}
	}
}
bool LEDService::stop() {
	_running = false;
	// TODO interrupt reading
	return true;
}

