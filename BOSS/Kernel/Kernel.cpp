
#include "Kernel.h"

Kernel::Kernel() {}
Kernel::~Kernel() {}

void Kernel::startService(Service* service)  {
	_serviceMapping.insert(std::pair<int, Service*>(service->getServiceId(), service));
	mmu_prepagePagesFor(service);
}

void Kernel::callService(int params[])  {

	Service* service = _serviceMapping.find(params[0])->second;

	//TODO: determine size of array...
	int size = 3;
	int* servicePara = new int[size];
	int i;
	for (i=0; i < size; i++ )  {
		servicePara[0] = params[0];
	}

	ServiceCall* serviceCall = new ServiceCall(service, servicePara);
	_serviceCalls.push(serviceCall);
}

void Kernel::executeServiceCalls()  {

	//TODO:  iterate over all service calls
	ServiceCall* serviceCall = _serviceCalls.front();

	Service* service = serviceCall->getService();
	int* params = serviceCall->getParams();

	//TODO:
	// * check if parameters of service are free (service is not busy)
	// * if free: write parameters to address
	// * if not free: save parameters for servie
	// * if service long time not responding: restart
	// * high priority for service
	// * FREE MEMORY!

	service->execute(params);
}
