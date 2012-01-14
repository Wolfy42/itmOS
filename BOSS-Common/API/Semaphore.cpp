
#include "API/systemCalls.h"
#include "Semaphore.h"

void enterSemaphore(int semaphoreType, int id) {
    int params[] = {0, semaphoreType, id};
    performSystemCall(SEMAPHORE, 3, params);
}
void exitSemaphore(int semaphoreType, int id) {
    int params[] = {1, semaphoreType, id};
    performSystemCall(SEMAPHORE, 3, params);
}
