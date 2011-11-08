
#include <stdio.h>

#include "TaskManagement/Tasks.h"

void task1function() {
	printf("start task1\n");
	int j = 31;
	int k = 40;
	for (int i = 0; i < 2; i++) {
		swi();
		printf("task1 %d %d %d\n",i,j,k);
	}	
}

void task2function() {
	printf("start task2\n");
	int j = 99;
	int k = 70;
	for (int i = 0; i < 5; i++) {
		swi();
		printf("task2 %d %d %d\n",i,j,k);	
	}	
}

void task3function() {
	printf("start task3\n");
	for (int i = 0; i < 5; i++) {
		swi();
		printf("task3\n");
	}
}

void task4function() {
	printf("start task4\n");
	for (int i = 0; i < 5; i++) {
		swi();
		printf("task4\n");
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

