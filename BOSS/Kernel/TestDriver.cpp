
#include <stdio.h>

#include "HAL/Timer/HalTimerDriver.h"
#include "Kernel/Interrupt/IRQHandler.h"
#include "Kernel/TaskManagement/Tasks.h"



void task1function() {
printf("task1\n");
	int j = 31;
	int k = 40;
	for (int i = 0; i < 2; i++) {
		
		printf("task1 %d %d %d\n",i,j,k);
	//	swi();
	}	
}

void task2function() {

	int j = 99;
	int k = 70;
	for (int i = 0; i < 5; i++) {
		
		printf("task2 %d %d %d\n",i,j,k);	
	//	swi();
	}	
}

void task3function() {

	for (int i = 0; i < 5; i++) {

		printf("task3\n");
		task1function();
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

	hand.registerHandler(38, dummy);

	HalTimerDriver timer;
	timer.init(GPTIMER2, 10000000);
	timer.start(GPTIMER2, GPT_IRQMODE_MATCH);

	_enable_interrupts( ) ;
}


int main() {

	// init few necessary tasks
	initTasks();
	createTask("task 1\0", 100, (int)task3function);
	createTask("task 2\0", 100, (int)task2function);
	
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



