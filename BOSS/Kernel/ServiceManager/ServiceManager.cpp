#include "ServiceManager.h"

ServiceManager::ServiceManager(TaskManager* taskManager, Loader* loader)  {
	_taskManager = taskManager;
	_loader = loader;
}

ServiceManager::~ServiceManager() {}

void ServiceManager::startServices()  {

	LedBytes ld;
	CodeBytes* cb = ld.getCodeBytes();
	SerialBytes serialBytes;
	CodeBytes* cb_serial = serialBytes.getCodeBytes();
	LEDConfig* lc = new LEDConfig();
	startService("LED", LED_SERVICE_ID, cb, lc);
	SerialConfig* sc = new SerialConfig();
	startService("Serial", SERIAL_SERVICE_ID, cb_serial, sc);
	delete cb;
	delete lc;
}

void ServiceManager::startService(char* serviceName, int serviceId, CodeBytes* codeBytes, ServiceConfig* config) {

	Task* task = _taskManager->create(serviceName, false, 100);
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
