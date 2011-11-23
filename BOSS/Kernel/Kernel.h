
#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>
#include <queue>

#include "Kernel/MMU/mmu.h"
#include "Service/Service.h"
#include "Kernel/ServiceCall/ServiceCall.h"

class Kernel {
private:

	// Mapping from service-id to service
	std::map<int, Service*> _serviceMapping;

	//Queue of pending service calls
	std::queue<ServiceCall*> _serviceCalls;

public:
	Kernel();
	virtual ~Kernel();

	void startService(Service* service);
	void callService(int params[]);

	void executeServiceCalls();
};

#endif /* KERNEL_H_ */
