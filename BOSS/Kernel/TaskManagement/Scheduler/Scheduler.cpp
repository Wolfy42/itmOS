#include "Scheduler.h"

Scheduler::Scheduler()
{
}

/*
 * getNextTask(std::list<Task*> tasks)
 * returns the index of the task, which should be done next
 */
Task* Scheduler::getNextTask(std::list<Task*> tasks) {

	// TODO: probably we should do some logic here :)
	return tasks.front();
}

Scheduler::~Scheduler()
{
}
