#ifndef TASK_H_
#define TASK_H_

#define REG_LENGTH 16

#include <string>

using namespace std;

typedef int TID_t;

enum Status { Ready, Blocked, Running };

class Task {
public:
	// empty Constructors
	Task();
	virtual ~Task();

	
	// do we need a code segment?
	// if not here's at least a link to the start function
	void(*initAddr)(void);

	// id of task
	TID_t id;
	// name of task
	string name;
	// status of task
	Status status;
	// priority of task (from 0 to 20 -> higher = more important)
	int priority;
		
	// registers
	int registers[REG_LENGTH];
};

#endif /*TASK_H_*/
