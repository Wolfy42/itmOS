
#include "TaskOperations.h"
#include "API/systemCalls.h"

void yield() {
    performSystemCall(YIELD);
}
void exit(int state) {
    performSystemCall(EXIT, state);
}
void kill(int pid) {
    performSystemCall(KILL, pid);
}
int fork() {
	performSystemCall(FORK);
    return 0;
}
