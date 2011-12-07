#include "ServiceManager.h"

#include "Kernel/TaskManagement/Tasks.h"
#include "Tasks/Services/LED/LEDService.h"

ServiceManager::ServiceManager() {}

ServiceManager::~ServiceManager() {}

void ServiceManager::startService(int service) {    
	switch (service) {
		case LED_SERVICE_CALL:
			createTask(LEDService::CONFIG.getServiceName(), 100, LEDService::CONFIG.getInitAddress());
			break;
			
		default:
			break;
	}
}
