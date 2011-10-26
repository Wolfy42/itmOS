#ifndef SYSTEMCALLS_H_
#define SYSTEMCALLS_H_

#include "dataTypes.h"

#define EXIT                0x0
#define KILL                0x1
#define EXEC                0x2
#define FORK                0x3

#define SERVICE_CALL        0x4
#define SERVICE_RESPONSE    0x5

void performSyscall(int syscallId, byte parameters[]);

#endif /*SYSTEMCALLS_H_*/
