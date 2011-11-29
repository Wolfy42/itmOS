
#include "ServiceCall.h"

ServiceCall::ServiceCall(int* serviceCallParams) {

	_serviceId = serviceCallParams[0];
	_paramsLength = serviceCallParams[1];

	// copy service-parameters into _params
	_params = new int[_paramsLength];
	memcpy(_params, &serviceCallParams[2], _paramsLength * sizeof(int));
}

ServiceCall::~ServiceCall() {
	delete _params;
}

int ServiceCall::getServiceId()  {
	return _serviceId;
}

int ServiceCall::getParamsLength()  {
	return _paramsLength;
}

int* ServiceCall::getParams()  {
	return _params;
}
