#include "Task.h"

Task::Task(TID_t id_, std::string name_, void(*initAddr)(void))
{
	id = id_;
	// init empty registers
	for (int i = 0; i < 16; i++) {
		registers[i] = 0;	
	}
	// stack pointer
	registers[STACK_POINTER] = 0x8200B000 + (id + 1) * 0x00010000;
	// program counter
	registers[PROGRAM_COUNTER] = (int)initAddr;
	returnAddress = (int)initAddr;
	name = name_;
	hasBeenStarted = false;
}

Task::~Task()
{
}
