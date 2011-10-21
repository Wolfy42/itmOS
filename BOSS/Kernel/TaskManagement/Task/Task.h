#ifndef TASK_H_
#define TASK_H_

#include <string>

#include "TaskControlBlock.h"

typedef int TID_t;

enum taskStatus { Ready, Blocked, Running };

class Task
{
public:
	// empty Constructors
	Task();
	virtual ~Task();
	
/* probably this should be private and use getter and setter */

	// id of task
	TID_t id;
	// name of task
	std::string name;
	// status of task
	taskStatus status;
	// priority of task (from 0 to 20 -> higher = more important)
	int priority;
	
	// a task always have a Task Control Block
	TaskControlBlock* tcb;
	
	// do we need a code segment?
	// if not here's at least a link to the start function
	void(*execute)(void);
};

#endif /*TASK_H_*/
