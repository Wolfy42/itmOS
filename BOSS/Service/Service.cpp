#include <stdio.h>
#include "Service.h"
#include "BOSSAPI/systemCalls.h"
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

void Service::writeResponse(byte command[]) {
	// Dummy output
	//printf("State of LED%i: %i\n", command[0]+1, command[1]);
}
