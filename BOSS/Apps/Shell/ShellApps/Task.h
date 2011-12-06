#ifndef TASKSHOW_H_
#define TASKSHOW_H_

#include "Kernel/Task/TaskManager.h"
#include "Apps/Shell/ShellApps/Echo.h"

#include <string.h>
#include <stdio.h>



void showTasks(TaskManager* tm) {

	
	echo("Id \t\tName \t\tPrio \t\tStatus\r\n");

	int i = 0;
	char* buffer;
	for (i = 0; i < MAX_TASKS; i++) {
	
		if (tm->getTaskList()[i] != NULL) {
		
			buffer = "";
			sprintf(buffer, "%d", tm->getTaskList()[i]->id);
			echo(buffer);
			echo("\t\t");
			echo(tm->getTaskList()[i]->name);
			echo("\t\t");
			
			buffer = "";
			sprintf(buffer, "%d", tm->getTaskList()[i]->priority);
			echo(buffer);
			echo("\t\t");
			
			buffer = "";
			sprintf(buffer, "%d", tm->getTaskList()[i]->status);
			echo(buffer);
			echo("\r\n");
		}	
	}
}

#endif /*TASKSHOW_H_*/
