
#ifndef KERNEL_H_
#define KERNEL_H_

#include <map>

#include "Kernel/MMU/mmu.h"
#include "Service/Service.h"

class Kernel {
private:
	// Mapping from service-id to service
	std::map<int, Service*> _serviceMapping;

public:
	Kernel();
	virtual ~Kernel();

	void startService(Service* service);
	void callService(int params[]);
};

#endif /* KERNEL_H_ */
