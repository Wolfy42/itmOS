#include <stdio.h>
#include "LEDService.h"

LEDService::LEDService(): UserModeTask()  {}
LEDService::~LEDService()  {}

MessageQueue* LEDService::getQueue()  {
	return (MessageQueue*)0x820F0000;
}

void LEDService::executeMessage(Message* message)  {

	int* params = message->getParams();
	LED led = (LED)params[0];
	LEDServiceCommand command = (LEDServiceCommand)params[1];
	//TODO: who was the sending task?

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
	            int result[2];
	            result[0] = led;
	            result[1] = state;
	            //TODO: write back the result
	            break;
	    }
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
