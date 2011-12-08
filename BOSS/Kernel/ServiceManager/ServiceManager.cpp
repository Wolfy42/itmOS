#include "ServiceManager.h"

#include "Kernel/Kernel.h"
#include "Tasks/Services/LED/LEDService.h"

ServiceManager::ServiceManager(Kernel* kernel, TaskManager* taskManager) : _kernel(kernel), _taskManager(taskManager) {}

ServiceManager::~ServiceManager() {}

void ServiceManager::registerService(int service) {
	//TODO: change this!
	MessageQueue* queue = new MessageQueue();
	*(address)0x820F0000 = (unsigned int)queue;
	_kernel->getMessageQueues().insert(std::pair<int, MessageQueue*>(service, queue));
}

void ServiceManager::startService(int service) {  
	TID_t taskId;
	  
	switch (service) {
		case LED_SERVICE:
			taskId = _taskManager->create(LEDService::CONFIG.getServiceName(), 100, LEDService::CONFIG.getInitAddress(), false);
			break;
			
		default:
			return;
	}
	
	_taskIdMapping.insert(std::pair<int, int>(service, taskId));
}

// TODO: Untested
void ServiceManager::stopService(int service) {
	TID_t taskId = getTaskIdForService(service);
	_taskIdMapping.erase(service);
	_taskManager->kill(taskId);
}

// TODO: Untested
void ServiceManager::restartService(int service) {
	stopService(service);
	startService(service);
}

TID_t ServiceManager::getTaskIdForService(int service) {
	return _taskIdMapping.find(service)->second;
}
