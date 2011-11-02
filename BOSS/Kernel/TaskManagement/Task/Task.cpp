#include "Task.h"

Task::Task(TID_t id_)
{
	id = id_;
	stackPointer = id * 64 + 12;
	hasBeenStarted = false;
}

Task::~Task()
{
}
