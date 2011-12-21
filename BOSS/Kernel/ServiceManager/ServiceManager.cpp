#include "ServiceManager.h"

ServiceManager::ServiceManager(TaskManager* taskManager) : _taskManager(taskManager) {}

ServiceManager::~ServiceManager() {}

void ServiceManager::startServices()  {

	startService(LED_SERVICE_ID);
}

void ServiceManager::startService(int serviceId) {

	Task* task = _taskManager->create("", 50, 0, true);

//			taskId = _taskManager->create(LEDService::CONFIG.getServiceName(), 100, LEDService::CONFIG.getInitAddress(), false);
	
	_serviceTaskMapping.insert(std::pair<int, Task*>(serviceId, task));
}

void ServiceManager::stopService(int serviceId) {
	_taskManager->kill(getTaskForService(serviceId)->id);
}

void ServiceManager::restartService(int serviceId) {
	stopService(serviceId);
	startService(serviceId);
}

Task* ServiceManager::getTaskForService(int serviceId) {
	return _serviceTaskMapping.find(serviceId)->second;
}
