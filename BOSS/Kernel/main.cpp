#include "Kernel/Kernel.h"
#include "Service/LED/LEDService.h"
#include "API/LED.h"
#include "Kernel/Interrupt/SWI/swiHandler.h"

//#include "Kernel/SoftwareInterrupts/swiHandler.h"


int _main(int argc, char **argv) {

	//TODO: start already in kernel-mode
	asm("	CPS   0x13");

	Kernel* kernel = new Kernel();
	SWIExecutor* swiExecutor = new SWIExecutor(kernel);

	swi_setSWIExecutor(swiExecutor);

	LEDService* ledService = new LEDService();
	kernel->startService(ledService);

	// up to user-mode
	//asm("	CPS   0x10");

	switchLEDOff(LED1);

	kernel->executeServiceCalls();

	// TODO: should be called by a scheduler
	ledService->run();

	return 0;
}
