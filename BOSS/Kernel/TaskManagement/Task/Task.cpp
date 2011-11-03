#include "Task.h"

Task::Task(TID_t id_, std::string name_)
{
	id = id_;
<<<<<<< HEAD
	stackPointer = 0x8200B000 + id * 0x00010000;
=======
	name = name_;
	stackPointer = id * 64 + 12;
>>>>>>> dc1a0a5ed8599c5144a57ed02e061c450abc3f04
	hasBeenStarted = false;
}

Task::~Task()
{
}
