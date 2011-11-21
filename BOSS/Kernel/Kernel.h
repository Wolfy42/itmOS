
#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>

#include "Service/Service.h"
#include "Service/LED/LEDService.h"

class Kernel {
private:
	// Mapping from service-id to service
	std::map<int, Service*> _serviceMapping;

	void registerService(Service* service);

public:
	Kernel();
	virtual ~Kernel();
};

#endif /* KERNEL_H_ */
