#include "ServiceManager.h"

ServiceManager::ServiceManager(TaskManager* taskManager, Loader* loader)  {
	_taskManager = taskManager;
	_loader = loader;
}

ServiceManager::~ServiceManager() {}

void ServiceManager::startServices()  {

	startService("LED", LED_SERVICE_ID, led);
}

void ServiceManager::startService(char* serviceName, int serviceId, char* serviceCode) {

	Task* task = _taskManager->create(serviceName, false);
	_serviceTaskMapping.insert(std::pair<int, Task*>(serviceId, task));

	_loader->loadCode(task, serviceCode);
}

void ServiceManager::stopService(int serviceId) {
	_taskManager->kill(getTaskForService(serviceId)->id);
}

Task* ServiceManager::getTaskForService(int serviceId) {
	return _serviceTaskMapping.find(serviceId)->second;
}
