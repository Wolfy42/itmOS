#include "ServiceManager.h"

#include "Kernel/ServiceManager/Configs/LED/LEDConfig.h"

ServiceManager::ServiceManager(TaskManager* taskManager, Loader* loader)  {
	_taskManager = taskManager;
	_loader = loader;
}

ServiceManager::~ServiceManager() {}

void ServiceManager::startServices()  {

	CodeBytes* cb = new CodeBytes;
	cb->byte0 = test_byte_0;
	cb->byte1 = test_byte_1;
	cb->byte2 = test_byte_2;
	cb->byte3 = test_byte_3;
	startService("LED", LED_SERVICE_ID, cb, new LEDConfig());
	delete cb;
}

void ServiceManager::startService(char* serviceName, int serviceId, CodeBytes* codeBytes, ServiceConfig* config) {

	Task* task = _taskManager->create(serviceName, false);
	_serviceTaskMapping.insert(std::pair<int, Task*>(serviceId, task));

	_loader->loadServiceCode(task, codeBytes, config);
}

void ServiceManager::stopService(int serviceId) {
	_taskManager->kill(getTaskForService(serviceId)->id);
	_serviceTaskMapping.erase(serviceId);
}

Task* ServiceManager::getTaskForService(int serviceId) {
	return _serviceTaskMapping.find(serviceId)->second;
}
