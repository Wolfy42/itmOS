
#include <stdio.h>
#include <string.h>

#include "HAL/Timer/HalTimerDriver.h"
#include "Kernel/Task/TaskManager.h"
#include "Kernel/Interrupt/Handler/IRQHandler.h"
#include "Kernel/Interrupt/Handler/SWIHandler.h"
#include "Kernel/SystemCalls/SystemCallExec.h"
#include "HAL/LED/HalLedDriver.h"

#include "Kernel/Interrupt/Interrupts.h"

#include "Apps/Shell/Shell.h"

#include "Lib/Rand.h"
#include "Lib/Time.h"

#include "Apps/Shell/Shell.h"

#include "Kernel/Kernel.h"

#include "API/LED.h"
#include "BOSSAPI/serviceCalls.h"

#include "Tasks/Services/LED/LEDService.h"
#include "Tasks/Services/LED/ledMain.h"
#include "Tasks/UserTasks/TestTask.h"
#include "Tasks/UserTasks/testTaskMain.h"

#include "Lib/OMAP/McBSP2.h"

TaskManager* taskmanager;

void ledOff(void) {

	HalLedDriver driver;
	driver.ledOff(LED1);
	driver.ledOff(LED2);
}

void initScheduler(IRQHandler* hand) {

	srand_(time_());
	hand->registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER2), ledOff);

	HalTimerDriver::init(GPTIMER2, GPT_IRQMODE_OVERFLOW, 100);
	HalTimerDriver::start(GPTIMER2);

}

void dummy(IRQHandler* hand)  {

	initScheduler(hand);
	_enable_interrupts();
	asm("\t CPS 0x10");
	while(1);
}

void task1function() {
	
	int i = 0;
	for (i = 0; i < 10000; i++) {
		HalLedDriver driver;
		driver.toggle(LED1);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}

}

void task2function() {

	int i = 0;
	for (i = 0; i < 100; i++) {
		HalLedDriver driver;
		driver.toggle(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}	

}

void shellstart() {
	
	shell(taskmanager);
}

int main() {


	McBSP2* mcbsp2 = new McBSP2();
	mcbsp2->init_mcbsp2();


	Kernel* kernel = new Kernel();
	taskmanager = new TaskManager();
	IRQHandler* irq = new IRQHandler();
	SystemCallExec* exec = new SystemCallExec(kernel, taskmanager);
	SWIHandler* swi = new SWIHandler(exec);
	
	initInterruptHandler(irq, swi, taskmanager);


//	int para[4];
//	para[0] = 0;
//	para[1] = 2;
//	para[2] = 0;
//	para[3] = 1;
//	MessageQueue* queue = new MessageQueue();
//	Message* message = new Message(para);
//	queue->addMessage(message);
//	*(address)0x820F0000 = (unsigned int)queue;
	kernel->registerService(LED_SERVICE_CALL);


	taskmanager->create("dummy\0", 0, (int)dummy, false);
	taskmanager->create("led 1\0", 70, (int)task1function, false);
	taskmanager->create("led 2\0", 30, (int)task2function, false);
//	createTask("task 1\0", 40, (int)task1function);
//	createTask("task 2\0", 40, (int)task2function);
//	createTask("task 1\0", 10, (int)task1function);
//	createTask("task 2\0", 90, (int)task2function);
//	taskmanager->create("LED-Service\0", 80, (int)led_main, false);
//	taskmanager->create("User-Test-Task\0", 100, (int)userTask_main, false);
	taskmanager->create("shell\0", 100, (int)shellstart, false);
	dummy(irq);

	while(1) {
		//HalLedDriver::toggle(LED1);
		//HalLedDriver::toggle(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}

	//return 0;
}



