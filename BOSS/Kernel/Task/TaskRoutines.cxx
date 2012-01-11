#include "TaskRoutines.h"

#include "API/systemCalls.h"

static TaskManager* _TaskManager;

/*
 * 	set TaskManager to a TaskManager which should be the used TaskManager,
 * 	because it will use some of its variables.
 * 
 * 	ATTENTION: This could cause Problems in further version
 */
void initTaskRoutines(TaskManager* tm) {
	
	_TaskManager = tm;
}

/*
 * exit Point for Tasks
 */
void exitTask() {
	
    int params[] = {(int)&_TaskManager->getActiveTask()->id};
	performSystemCall(EXIT, 1, params);
}
