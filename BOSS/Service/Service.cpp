#include <stdio.h>
#include "Service.h"

#include "LED/LEDService.h"


Service::Service() {
}

Service::~Service() {
}

bool Service::run() {
	// TODO new process
	start();
	return true;
}

bool Service::restart() {
	stop();
	return run();
}

byte* Service::readCommand(int commandId) {
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

void Service::writeResponse(byte command[]) {
	// Dummy output
	printf("State of LED%i: %i\n", command[0]+1, command[1]);
}
