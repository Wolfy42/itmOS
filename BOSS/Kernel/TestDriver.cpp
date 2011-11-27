
#include <stdio.h>

#include "HAL/Timer/HalTimerDriver.h"
#include "Kernel/Interrupt/IRQHandler.h"
#include "Kernel/TaskManagement/Tasks.h"
#include "HAL/LED/HalLedDriver.h"


void ledOff(void) {

	HalLedDriver::ledOff(LED1);
	HalLedDriver::ledOff(LED2);
}

void initScheduler() {

	IRQHandler hand;
	srand_(time_());
	hand.registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER2), ledOff);

	HalTimerDriver::init(GPTIMER2, GPT_IRQMODE_OVERFLOW, 50000000);
	HalTimerDriver::start(GPTIMER2);

}

void dummy()  {

	initScheduler();
	_enable_interrupts();
	asm("\t CPS 0x10");
	int i;
	while(1)  {
		HalLedDriver::ledOn(LED1);
		HalLedDriver::ledOn(LED2);
	}
}

void task1function() {
	
	int i = 0;
	for (i = 0; i < 10000; i++) {
		HalLedDriver::toggle(LED1);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}
	while(1);
}

void task2function() {

	int i = 0;
	for (i = 0; i < 1000; i++) {
		HalLedDriver::toggle(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}	
	while(1);
}


void shell() {

	while (1) {
		
		// get input data?
	}
}

void initShell() {

	createTask("shell\0", 100, (int)shell);	
}





int main() {

	// init few necessary tasks
	initTasks();

	createTask("task 1\0", 0, (int)dummy);
	createTask("task 1\0", 20, (int)task1function);
	createTask("task 2\0", 20, (int)task2function);


	dummy();

	while(1) {
		HalLedDriver::toggle(LED1);
		HalLedDriver::toggle(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}

	return 0;
}



