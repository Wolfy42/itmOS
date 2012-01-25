#include "ServiceManager.h"

ServiceManager::ServiceManager(TaskManager* taskManager, Loader* loader)  {
	_taskManager = taskManager;
	_loader = loader;
}

ServiceManager::~ServiceManager() {}

void ServiceManager::startServices()  {

	LedBytes ld;
	CodeBytes* cb_led = ld.getCodeBytes();
	LEDConfig* c_led = new LEDConfig();
	startService("LED", LED_SERVICE_ID, cb_led, c_led);
	delete cb_led;
	delete c_led;

	SerialBytes serialBytes;
	CodeBytes* cb_serial = serialBytes.getCodeBytes();
	SerialConfig* c_serial = new SerialConfig();
	startService("Serial", SERIAL_SERVICE_ID, cb_serial, c_serial);
	delete cb_serial;
	delete c_serial;

	DisplayBytes displayBytes;
	CodeBytes* cb_display = displayBytes.getCodeBytes();
	DisplayConfig* c_display = new DisplayConfig();
	startService("Display", DISPLAY_SERVICE_ID, cb_display, c_display, 100);
	delete cb_display;
	delete c_display;
	
	ShellBytes shellBytes;
	CodeBytes* cb_shell = shellBytes.getCodeBytes();
	ShellConfig* c_shell= new ShellConfig();
	startService("Shell", SHELL_SERVICE_ID, cb_shell, c_shell);
	delete cb_shell;
	delete c_shell;

    ButtonBytes buttonBytes;
    CodeBytes* cb_button = buttonBytes.getCodeBytes();
    ButtonConfig* c_button= new ButtonConfig();
    startService("Button", BUTTON_SERVICE_ID, cb_button, c_button);
    delete cb_button;
    delete c_button;
    
    Task* scSw = _taskManager->create("ScreenSwitcher", false);
    ScSwBytes sb;
    _loader->loadTaskCode(scSw, sb.getCodeBytes());

}

void ServiceManager::startService(char* serviceName, int serviceId, CodeBytes* codeBytes, ServiceConfig* config) {
    startService(serviceName, serviceId, codeBytes, config, 80);
}

void ServiceManager::startService(char* serviceName, int serviceId, CodeBytes* codeBytes, ServiceConfig* config, int priority) {
    
    Task* task = _taskManager->create(serviceName, false, priority);
    _serviceTaskMapping.insert(std::pair<int, Task*>(serviceId, task));

    _loader->loadServiceCode(task, codeBytes, config);
}


void ServiceManager::stopService(int serviceId) {
	_taskManager->kill(getTaskForService(serviceId)->id);
	_serviceTaskMapping.erase(serviceId);
}

Task* ServiceManager::getTaskForService(int serviceId) {
	if (_serviceTaskMapping.find(serviceId) == NULL)  {
		return NULL;
	}
	return _serviceTaskMapping.find(serviceId)->second;
}
