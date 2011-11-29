
#ifndef SERVICECALL_H_
#define SERVICECALL_H_

#include <string.h>

class ServiceCall {

private:

	int _serviceId;
	int _paramsLength;
	int* _params;

public:

	ServiceCall(int* serviceCallParams);
	virtual ~ServiceCall();

	int getServiceId();
	int getParamsLength();
	int* getParams();
};

#endif /* SERVICECALL_H_ */
