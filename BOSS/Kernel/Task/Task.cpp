#include "Task.h"
#include "Semaphore.h"

Task::Task()  {
	status = Ready;
	priority = 0;
	masterTableAddress = 0x0;
	memoryManager = 0x0;
    taskRegisters = 0x0;
    semaphore = new Semaphore();
}

Task::~Task() {
}
