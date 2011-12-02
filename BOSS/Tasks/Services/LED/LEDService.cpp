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
	//TODO: who was the sending task?

	switch (command) {
	        case SERVICE_SWITCH_LED_OFF:
	        	HalLedDriver::ledOff(led);
	            break;
	        case SERVICE_SWITCH_LED_ON:
	        	HalLedDriver::ledOn(led);
	            break;
	        case SERVICE_TOGGLE_LED:
	        	HalLedDriver::toggle(led);
	            break;
	        case SERVICE_GET_LED_STATUS:
	            int response[2];
	            response[0] = params[2]; // write Back caller-Id
	            response[1] = HalLedDriver::isOn(led);
	            writeResponse(response);
	            break;
	    }
}
