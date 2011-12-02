#include <stdio.h>
#include "LEDService.h"

LEDService::LEDService(): UserModeTask()  {}
LEDService::~LEDService()  {}

MessageQueue* LEDService::getQueue()  {
	return *(MessageQueue**)0x820F0000;
}

void LEDService::executeMessage(Message* message)  {

	int* params = message->getParams();
	LED led = (LED)params[0];
	LEDServiceCommand command = (LEDServiceCommand)params[1];

	switch (command) {
		case SERVICE_SWITCH_LED_OFF:
			_driver.ledOff(led);
			break;
		case SERVICE_SWITCH_LED_ON:
			_driver.ledOn(led);
			break;
		case SERVICE_TOGGLE_LED:
			_driver.toggle(led);
			break;
		case SERVICE_GET_LED_STATUS:
			int response[2];
			response[0] = params[2]; // write Back caller-Id
			response[1] = _driver.isOn(led);
			writeResponse(response);
			break;
	}
}
