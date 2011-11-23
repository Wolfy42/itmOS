
#ifndef SERVICECALL_H_
#define SERVICECALL_H_

#include "Service/Service.h"

class ServiceCall {

private:

	Service* _service;
	int* _params;

public:

	ServiceCall(Service* service, int* params);
	virtual ~ServiceCall();

	Service* getService();
	int* getParams();
};


#endif /* SERVICECALL_H_ */
