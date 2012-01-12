#include "LEDService.h"

LEDService::LEDService() : Service() {}
LEDService::~LEDService() {}

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
			int response[] = {_driver.isOn(led)};
			writeResponse(message->getTaskId(), 1, response);
			break;
	}
}
