
#include "Kernel.h"

Kernel::Kernel() {

	LEDService ledService;
	registerService(&ledService);

}

Kernel::~Kernel() {
	_kernel = this;
}

void Kernel::registerService(Service* service)  {
	_serviceMapping.insert(std::pair<int, Service*>(service->getServiceId(), service));
}

void Kernel::callService(int params[])  {

	Service* service = _serviceMapping.find(params[0])->second;
	service->execute(params);
}
