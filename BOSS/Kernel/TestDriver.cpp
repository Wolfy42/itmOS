
#include <stdio.h>

#include "HAL/Timer/HalTimerDriver.h"
#include "Kernel/Interrupt/IRQHandler.h"
#include "Kernel/TaskManagement/Tasks.h"
#include "HAL/LED/HalLedDriver.h"

void task1function() {
	
	int j = 31;
	int k = 40;
	int i = 0;
	for (i = 0; i < 100; i++) {

		HalLedDriver::toggle(LED1);
		for (int z = 0; z < 80000;) {
			z++;
		}
	//	printf("task1 %d %d %d\n",i,j,k);
	//	swi();
	}
	//printf("task1 %d %d %d\n",i,j,k);
}

void task2function() {

	int j = 99;
	int k = 70;
	int i = 0;
	for (i = 0; i < 100; i++) {

		HalLedDriver::toggle(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	//	printf("task2 %d %d %d\n",i,j,k);	
	//	swi();
	}	
}

void task3function() {

	for (int i = 0; i < 5000; i++) {

		printf("task3\n");
		//task1function();
	}
}

void task4function() {

	for (int i = 0; i < 5; i++) {

		printf("task4\n");
	//	swi();
	}
}

void shell() {

	while (1) {
		
		// get input data?
	}
}

void initShell() {

	createTask("shell\0", 100, (int)shell);	
}

void dummy(void) {
}

void initScheduler() {

	IRQHandler hand;
	srand_(time_());
	hand.registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER2), dummy);

	HalTimerDriver::init(GPTIMER2, GPT_IRQMODE_MATCH, 5000000);
	HalTimerDriver::start(GPTIMER2);

	_enable_interrupts( ) ;
}


int main() {

	// init few necessary tasks
	initTasks();
	createTask("task 1\0", 70, (int)task1function);
	createTask("task 2\0", 30, (int)task2function);

	// init scheduler
	initScheduler();

	while(1) {
	}
//	hasStarted = 0;
	// create some tasks
//	TaskManager* manager = new TaskManager();
//	Task* dummy = new Task(7, "dummy", NULL);
//	manager->createTask("task 1", task1function);
//	manager->createTask("task 2", task2function);
//	manager->createTask("task 3", task3function);
//	manager->createTask("task 4", task4function);
//
//	manager->showTasks();
//
//	// TODO: LOL!!!LO!LO!L!O!LOLOOOOLOLOL es l�scht alles?
////	manager->deleteTask(3);
//	
//	swi();
//	manager->run();

	return 0;
}



