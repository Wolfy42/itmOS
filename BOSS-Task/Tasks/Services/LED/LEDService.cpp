#include <stdio.h>
#include "LEDService.h"


// ~~~~~~~~~~~~~~~~~~~~ CONFIG & STARTUP ~~~~~~~~~~~~~~~~~~~~
LEDConfig LEDService::CONFIG = LEDConfig();

// Static main method for this service
void LEDService::main(void) {
	LEDService service;
	service.run();
}
// ~~~~~~~~~~~~~~~~~~~~ CONFIG & STARTUP ~~~~~~~~~~~~~~~~~~~~


LEDService::LEDService(): Service()  {}
LEDService::~LEDService()  {}

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
