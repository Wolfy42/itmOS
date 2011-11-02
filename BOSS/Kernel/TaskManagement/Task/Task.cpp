#include "Task.h"

Task::Task(TID_t id)
{
	id = id;
	stackPointer = id * 64 + 12;
	hasBeenStarted = false;
}

Task::~Task()
{
}
