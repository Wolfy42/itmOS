
#include <stdio.h>

#include "TaskManagement/TaskManager.h"

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

	// create some tasks
	TaskManager* manager = new TaskManager();
	Task* task1 = manager->createTask(task1function);
	Task* task2 = manager->createTask(task2function);
	Task* task3 = manager->createTask(task3function);
	Task* task4 = manager->createTask(task4function);

	// TODO: LOL!!!LO!LO!L!O!LOLOOOOLOLOL es löscht alles?
	//manager->deleteTask(task3);
	
	manager->run();

	return 0;
}

