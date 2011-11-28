
#include "ServiceCall.h"

ServiceCall::ServiceCall(Service* service, int* params) {
	_service = service;
	_params = params;
}

ServiceCall::~ServiceCall() {}

Service* ServiceCall::getService()  {
	return _service;
}

int* ServiceCall::getParams()  {
	return _params;
}

