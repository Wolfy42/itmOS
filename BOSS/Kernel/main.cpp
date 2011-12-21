#include "Kernel/Kernel.h"
#include "Kernel/ServiceManager/ServiceManager.h"
#include "HAL/Timer/HalTimerDriver.h"
#include "Lib/Rand.h"
#include "Lib/Time.h"

void interrupted(void) {
	// Bla
}

void initScheduler(IRQHandler* hand) {
	srand_(time_());
	hand->registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER2), interrupted);

	HalTimerDriver::init(GPTIMER2, GPT_IRQMODE_OVERFLOW, 100);
	HalTimerDriver::start(GPTIMER2);
}

void dummy2(void)  {
	while(1);
}

int main() {

	_disable_interrupts();

	Kernel* kernel = new Kernel();
	ServiceManager* serviceManager = kernel->getServiceManager();

	initScheduler(kernel->getHandlerManager()->getIrqHandler());

	// Dummy Task
	Task* dummyTask = kernel->getTaskManager()->create("dummy2\0", false);
	dummyTask->codeLocation = (address)((void*)dummy2);
	dummyTask->pageCount = 1;
	
	// Start Services
	serviceManager->startServices();

	// Init
	_enable_interrupts();
	asm("\t CPS 0x10");
	dummy2();
	
	while(1);
}
