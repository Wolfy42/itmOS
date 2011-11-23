#include "Kernel/Kernel.h"
#include "Service/LED/LEDService.h"
#include "API/LED.h"
#include "Kernel/SoftwareInterrupts/swiHandler.h"

int _main(int argc, char **argv) {

	//TODO: start already in kernel-mode
	asm("	CPS   0x13");

	Kernel kernel;
	swi_setKernel(&kernel);

	LEDService ledService;
	kernel.startService(&ledService);

	// up to user-mode
	asm("	CPS   0x10");

	switchLEDOff(LED1);

	return 0;
}
