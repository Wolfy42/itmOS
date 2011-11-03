#ifndef TASK_H_
#define TASK_H_

#define REG_LENGTH 16

#include "../../../API/dataTypes.h"
#include <string>

typedef int TID_t;

enum Status { Ready, Blocked, Running };

class Task {
public:
	// empty Constructors
	Task(TID_t id);
	virtual ~Task();

	
	// do we need a code segment?
	// if not here's at least a link to the start function
	void(*initAddr)(void);

	// id of task
	TID_t id;
	// name of task
	std::string name;
	// status of task
	Status status;
	// priority of task (from 0 to 20 -> higher = more important)
	int priority;
	
	// stackpointer
	int stackPointer;
		
	// return address
	int returnAddress;
	
	// already started
	bool hasBeenStarted;
};

#endif /*TASK_H_*/
