#include "ServiceManager.h"

#include "Kernel/ServiceManager/Configs/LED/LEDConfig.h"

ServiceManager::ServiceManager(TaskManager* taskManager, Loader* loader)  {
	_taskManager = taskManager;
	_loader = loader;
}

ServiceManager::~ServiceManager() {}

void ServiceManager::startServices()  {

	startService("LED", LED_SERVICE_ID, led, new LEDConfig());
}

void ServiceManager::startService(char* serviceName, int serviceId, char* serviceCode, ServiceConfig* config) {

	Task* task = _taskManager->create(serviceName, false);
	_serviceTaskMapping.insert(std::pair<int, Task*>(serviceId, task));

	_loader->loadServiceCode(task, serviceCode, config);
}

void ServiceManager::stopService(int serviceId) {
	_taskManager->kill(getTaskForService(serviceId)->id);
	_serviceTaskMapping.erase(serviceId);
}

Task* ServiceManager::getTaskForService(int serviceId) {
	return _serviceTaskMapping.find(serviceId)->second;
}
