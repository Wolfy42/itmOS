
#include <stdio.h>

#include "TaskManagement/TaskManager.h"



void task1() {

	for (int i = 0; i < 5; i++) {
		
		printf("task1\n");	
		swift();
	}	
}

void task2() {

	for (int i = 0; i < 5; i++) {
		
		printf("task2\n");	
		swift();
	}	
}

int main_() {
	// create some tasks
	TaskManager* manager = new TaskManager();
	manager->createTask(task1);
	manager->createTask(task2);
	
	manager->scheduleTask();
	
	return 0;
}

