
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
	manager->createTask("task 1", task1function);
	manager->createTask("task 2", task2function);
	manager->createTask("task 3", task3function);
	manager->createTask("task 4", task4function);

	manager->showTasks();

	// TODO: LOL!!!LO!LO!L!O!LOLOOOOLOLOL es l�scht alles?
//	manager->deleteTask(3);
	
	manager->run();

	return 0;
}

