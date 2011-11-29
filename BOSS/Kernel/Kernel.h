
#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>
#include <list>

#include <string.h>

#include "Kernel/MMU/mmu.h"
#include "Service/Service.h"
#include "Kernel/ServiceCall/ServiceCall.h"

class Kernel {
private:

	// Mapping from service-id to service
	// TODO: replace this map
	std::map<int, Service*> _serviceMapping;

	//Queue of pending service calls
	std::list<ServiceCall*> _serviceCalls;

public:
	Kernel();
	virtual ~Kernel();

	void startService(Service* service);
	void callService(int params[]);

	void executeServiceCalls();
};

#endif /* KERNEL_H_ */
