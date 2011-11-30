#ifndef SYSTEMCALLS_H_
#define SYSTEMCALLS_H_

#include "API/dataTypes.h"

#define EXIT                0x1
#define KILL                0x2
#define EXEC                0x3
#define FORK                0x4
#define YIELD               0x5
#define WRITE				0x6

#define SERVICE_CALL        0x7
#define SERVICE_RESPONSE    0x8

void performSyscall(int syscallId, int parameters[]);

#endif /*SYSTEMCALLS_H_*/
