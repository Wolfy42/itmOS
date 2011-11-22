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

void LEDService::execute(int params[]) {
    
    LED led = (LED)params[1];
    LEDServiceCommand command = (LEDServiceCommand)params[2];
    switch (command) {
        case SERVICE_SWITCH_LED_OFF:
            switchLEDOff(led);
            break;
        case SERVICE_SWITCH_LED_ON:
            switchLEDOn(led);
            break;
        case SERVICE_TOGGLE_LED:
            toggleLED(led);
            break;
        case SERVICE_GET_LED_STATUS:
            LEDState state = getLEDState(led);
            byte result[] = {led, state};
            writeResponse(result);
            break;
    }
}
void LEDService::start() {
	_running = true;
//	while (_running);
}
bool LEDService::stop() {
	_running = false;
	// TODO interrupt reading
	return true;
}

int LEDService::getServiceId()  {
	return LED_SERVICE_CALL;
}

