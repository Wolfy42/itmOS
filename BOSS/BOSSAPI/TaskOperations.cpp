
#include "TaskOperations.h"
#include "systemCalls.h"

void yield() {
    performSyscall(YIELD, (int*)0x0);
}
void exit(int state) {
    int params[] = {state};
    performSyscall(EXIT, params);
}
void kill(int pid) {
    int params[] = {pid};
    performSyscall(KILL, params);
}
int fork() {
    performSyscall(FORK, (int*)0x0);
    return 0;
}
