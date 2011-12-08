#include "HandlerManager.h"
#include "Kernel/Kernel.h"

HandlerManager::HandlerManager(Kernel* kernel) : _kernel(kernel) {
	_irqHandler = new IRQHandler();
	_swiHandler = new SWIHandler(_kernel->getExecutor());
}

HandlerManager::~HandlerManager() {
	delete _irqHandler;
	delete _swiHandler;
}

IRQHandler* HandlerManager::getIrqHandler(void) {
	return _irqHandler;
}

SWIHandler* HandlerManager::getSwiHandler(void) {
	return _swiHandler;
}
