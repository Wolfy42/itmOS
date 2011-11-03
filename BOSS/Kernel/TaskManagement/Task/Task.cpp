#include "Task.h"

Task::Task(TID_t id_, std::string name_)
{
	id = id_;
	name = name_;
	stackPointer = id * 64 + 12;
	hasBeenStarted = false;
}

Task::~Task()
{
}
