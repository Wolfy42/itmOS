#include "ServiceManager.h"

#include "Kernel/Kernel.h"

#include "Kernel/Task/TaskManager.h"
#include "Tasks/Services/LED/LEDService.h"

ServiceManager::ServiceManager(Kernel* kernel) : _kernel(kernel) {}

ServiceManager::~ServiceManager() {}

void ServiceManager::startService(int service) {    
	switch (service) {
		case LED_SERVICE:
			_kernel->getTaskManager()->create(LEDService::CONFIG.getServiceName(), 100, LEDService::CONFIG.getInitAddress(), false);
			break;
			
		default:
			break;
	}
}
