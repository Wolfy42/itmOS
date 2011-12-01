
#include <stdio.h>
#include <string.h>

#include "HAL/Timer/HalTimerDriver.h"
#include "Kernel/Interrupt/IRQHandler.h"
#include "Kernel/TaskManagement/Tasks.h"
#include "HAL/LED/HalLedDriver.h"
<<<<<<< HEAD
#include "Service/LED/main.h"

#include "Apps/Shell/Shell.h"


#include "Kernel/Kernel.h"
#include "Service/LED/LEDService.h"
#include "API/LED.h"
#include "Kernel/SoftwareInterrupts/SWIExecutor.h"
#include "Kernel/Interrupt/swiHandler/swiHandler.h"

=======
#include "Tasks/Services/LED/LEDService.h"
#include "Tasks/Services/LED/main.h"
>>>>>>> d4e7cef9d7f3d29be834e493fc764b66bbb56cda

void ledOff(void) {

	HalLedDriver::ledOff(LED1);
	HalLedDriver::ledOff(LED2);
}

void initScheduler() {

	IRQHandler hand;
	srand_(time_());
	hand.registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER2), ledOff);

	HalTimerDriver::init(GPTIMER2, GPT_IRQMODE_OVERFLOW, 100);
	HalTimerDriver::start(GPTIMER2);

}

void dummy()  {

	initScheduler();
	_enable_interrupts();
	asm("\t CPS 0x10");
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
	for (i = 0; i < 10000; i++) {
		
		HalLedDriver::toggle(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}	
	while(1);
}

void initShell() {

	createTask("shell\0", 100, (int)shell);	
}

int main() {



	Kernel* kernel = new Kernel();
	TaskManager* taskmanager = new TaskManager();
	SWIExecutor* swiExecutor = new SWIExecutor(kernel, taskmanager);

	swi_setSWIExecutor(swiExecutor);

	int para[4];
	para[0] = 0;
	para[1] = 2;
	para[2] = 0;
	para[3] = 1;
	MessageQueue* queue = new MessageQueue();
	Message* message = new Message(para);
	queue->addMessage(message);
	*(address)0x820F0000 = (unsigned int)queue;


	// init few necessary tasks
	initTasks();

	createTask("dummy\0", 0, (int)dummy);
	createTask("task 1\0", 70, (int)task1function);
	createTask("task 2\0", 30, (int)task2function);
//	createTask("task 1\0", 40, (int)task1function);
//	createTask("task 2\0", 40, (int)task2function);
//	createTask("task 1\0", 10, (int)task1function);
//	createTask("task 2\0", 90, (int)task2function);
	//createTask("LED-Service\0", 80, (int)led_main);
	createTask("shell\0", 100, (int)shell);	
	dummy();

	while(1) {
		HalLedDriver::toggle(LED1);
		HalLedDriver::toggle(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}

	//return 0;
}



