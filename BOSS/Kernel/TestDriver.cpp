
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

void task3() {

	for (int i = 0; i < 5; i++) {

		printf("task3\n");
		swi();
	}
}

void task4() {

	for (int i = 0; i < 5; i++) {

		printf("task4\n");
		swi();
	}
}

int main() {
	TID_t task1Id = 0;
	TID_t task2Id = 0;
	TID_t task3Id = 0;
	TID_t task4Id = 0;

	// create some tasks
	TaskManager* manager = new TaskManager();
	task1Id = manager->createTask(task1);
	task2Id = manager->createTask(task2);
	task3Id = manager->createTask(task3);
	task4Id = manager->createTask(task4);

	manager->deleteTask(task3Id);
	
	//manager->scheduleTask();
	
	return 0;
}

