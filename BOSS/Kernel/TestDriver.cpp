
#include <stdio.h>

#include "TaskManagement/TaskManager.h"



void task1() {

	for (int i = 0; i < 5; i++) {
		
		printf("task1\n");	
		swi();
	}	
}

void task2() {

	for (int i = 0; i < 5; i++) {
		
		printf("task2\n");	
		swi();
	}	
}

int main() {
	// create some tasks
	TaskManager* manager = new TaskManager();
	manager->createTask(task1);
	manager->createTask(task2);
	
	manager->run();
	
	return 0;
}

