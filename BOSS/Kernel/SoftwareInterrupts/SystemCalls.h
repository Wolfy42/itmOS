#ifndef SYSTEMCALLS_H_
#define SYSTEMCALLS_H_

#include <API/s#include "SoftwareInterrupt.h"erviceCalls.h>
#include <API/systemCalls.h>

#include "SoftwareInterrupt.h"

void performServiceCall(int params[]);

void performSyscall(int syscallId, int parameters[]);


#endif /*SYSTEMCALLS_H_*/
