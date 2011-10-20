#include "Service.h"

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
