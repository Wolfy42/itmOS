#ifndef TASK_H_
#define TASK_H_

#include <string>
#include "TaskControlBlock.h"

using namespace std;

typedef int TID_t;

enum Status { Ready, Blocked, Running };

class Task {
public:
	// empty Constructors
	Task();
	virtual ~Task();
	
	// getter/setter
	TID_t getId() const { return _id; }
	void setId(TID_t id) { _id = id; }
	
	string getName() const { return _name; }
	void setName(string name) { _name = name; }
	
	Status getStatus() const { return _status; }
	void setStatus(Status status) { _status = status; }
	
	int getPriority() const { return _priority; }
	void setPriority(int priority) { _priority = priority; }
	
	TaskControlBlock* getTaskControlBlock() const { return _tcb; }
	void setTaskControlBlock(TaskControlBlock* tcb) { _tcb = tcb; }
	
	// do we need a code segment?
	// if not here's at least a link to the start function
	void(*execute)(void);
	
private:
	// id of task
	TID_t _id;
	// name of task
	string _name;
	// status of task
	Status _status;
	// priority of task (from 0 to 20 -> higher = more important)
	int _priority;
	// a task always have a Task Control Block
	TaskControlBlock* _tcb;
};

#endif /*TASK_H_*/
