
#include "Kernel.h"

Kernel::Kernel() {

	_kernel = this;

	LEDService ledService;
	registerService(&ledService);
}

Kernel::~Kernel() {
}

void Kernel::registerService(Service* service)  {
	_serviceMapping.insert(std::pair<int, Service*>(service->getServiceId(), service));
	mmu_prepagePagesFor(service);
}

void Kernel::callService(int params[])  {

	Service* service = _serviceMapping.find(params[0])->second;
	address parameterAddress = mmu_parameterAddressFor(service);
	//TODO:
	// * check if parameters of service are free (service is not busy)
	// * if free: write parameters to address
	// * if not free: save parameters for servie
	// * if service long time not responding: restart
	// * high priority for service

	service->execute(params);
}
