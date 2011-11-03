#include "Task.h"

Task::Task(TID_t id_, std::string name_)
{
	id = id_;
	stackPointer = 0x8200B000 + id * 0x00010000;
	name = name_;
	hasBeenStarted = false;
}

Task::~Task()
{
}
