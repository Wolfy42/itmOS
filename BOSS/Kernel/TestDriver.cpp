
#include <stdio.h>

#include "TaskManagement/Tasks.h"

void task1function() {

	int j = 31;
	int k = 40;
	for (int i = 0; i < 2; i++) {
		
		printf("task1 %d %d %d\n",i,j,k);
		swi();
	}	
}

void task2function() {

	int j = 99;
	int k = 70;
	for (int i = 0; i < 5; i++) {
		
		printf("task2 %d %d %d\n",i,j,k);	
		swi();
	}	
}

void task3function() {

	for (int i = 0; i < 5; i++) {

		printf("task3\n");
		swi();
	}
}

void task4function() {

	for (int i = 0; i < 5; i++) {

		printf("task4\n");
		swi();
	}
}

int main() {

	// init few necessary tasks
	initTasks();
	createTask("task 1\0", 100, (int)task1function);
	createTask("task 2\0", 100, (int)task2function);
	swi();

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

