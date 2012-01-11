
#include "TaskOperations.h"
#include "API/systemCalls.h"

void yield() {
    performSystemCall(YIELD);
}
void exit(int state) {
    int params[] = {state};
    performSystemCall(EXIT, 1, params);
}
void kill(int pid) {
    int params[] = {pid};
    performSystemCall(KILL, 1, params);
}
int fork() {
	performSystemCall(FORK);
    return 0;
}
