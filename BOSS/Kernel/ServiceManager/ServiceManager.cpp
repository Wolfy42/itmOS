#include "ServiceManager.h"

#include "Kernel/ServiceManager/Configs/LED/LEDConfig.h"

ServiceManager::ServiceManager(TaskManager* taskManager, Loader* loader)  {
	_taskManager = taskManager;
	_loader = loader;
}

ServiceManager::~ServiceManager() {}

void ServiceManager::startServices()  {

	CodeBytes* cb = new CodeBytes;
	cb->byte0 = led_byte_0;
	cb->byte1 = led_byte_1;
	cb->byte2 = led_byte_2;
	cb->byte3 = led_byte_3;
	LEDConfig* lc = new LEDConfig;
	startService("LED", LED_SERVICE_ID, cb, lc);
	delete cb;
	delete lc;
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
