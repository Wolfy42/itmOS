#ifndef TASK_H_
#define TASK_H_

#define REG_LENGTH 16
#define STACK_POINTER 13
#define PROGRAM_COUNTER 15

#include <string>

typedef int TID_t;

enum Status { Ready, Blocked, Running };

class Task {
public:
	// empty Constructors
	Task(TID_t id, std::string name, void(*initAddr)(void));
	virtual ~Task();

	// id of task
	TID_t id;
	// name of task
	std::string name;
	// status of task
	Status status;
	// priority of task (from 0 to 20 -> higher = more important)
	int priority;
	
	// registers
	int registers[REG_LENGTH];
		
	// already started
	bool hasBeenStarted;
};

#endif /*TASK_H_*/
