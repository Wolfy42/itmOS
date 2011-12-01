#include "Service.h"

Service::Service() {
	//TODO: this address will need a semaphore
	_parameterAddress = (int*)0x820F0000;
	_parameterAddress[0] = SERVICE_FREE;
}
Service::~Service() {}

void Service::run() {
	while (true)  {

		ServiceStatus status = (ServiceStatus)(_parameterAddress[0]);
		if (status == SERVICE_REQ)  {
			int* params = _parameterAddress + 1;
			execute(params);
		}
	}
}

void Service::writeResponse(int params[])  {
	int* response = _parameterAddress + 1;
	//TODO: para-length...
	int length = 2;
	_parameterAddress[0] = SERVICE_RESP;
	memcpy(response, params, length * sizeof(int));
}
