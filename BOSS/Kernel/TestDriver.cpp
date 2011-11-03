
#include <stdio.h>

#include "TaskManagement/TaskManager.h"

void task1function() {

	int j = 0;
	int k = 7;
	for (int i = 0; i < 2; i++) {
		
		printf("task1\n");	
		//swi();
	}	
}

void task2function() {

	for (int i = 0; i < 5; i++) {
		
		printf("task2\n");	
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

	// create some tasks
	TaskManager* manager = new TaskManager();
	Task* task1 = manager->createTask(task1function);
	Task* task2 = manager->createTask(task2function);
	Task* task3 = manager->createTask(task3function);
	Task* task4 = manager->createTask(task4function);

	// TODO: LOL!!!LO!LO!L!O!LOLOOOOLOLOL es l�scht alles?
	manager->deleteTask(task3);
	
	manager->run();

	return 0;
}

