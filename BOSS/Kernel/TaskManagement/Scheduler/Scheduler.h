#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <list>

#include "../Task/Task.h"

class Scheduler {
public:
	Scheduler();
	virtual ~Scheduler();
	
	// get the next Task which should be done out of a list
	Task* getNextTask(std::list<Task*> tasks);
};

#endif /*SCHEDULER_H_*/
