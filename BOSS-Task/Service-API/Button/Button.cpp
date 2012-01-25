#include "Button.h"
extern unsigned int messagesStart;

void waitForButtonPress() {
    int params[] = {BUTTON_SERVICE_REGISTER};
    performServiceCall(BUTTON_SERVICE_ID, 1, params);
    MemoryManager* memoryManager = (MemoryManager*)&messagesStart;
    MessageQueue* messagesQueue = memoryManager->getMessageQueue();

    //enterSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
    while (messagesQueue->isEmpty()) {
        //exitSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
        //performSystemCall(SUSPEND);
        //enterSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
    }
    params[0] = BUTTON_SERVICE_UNREGISTER;
    performServiceCall(BUTTON_SERVICE_ID, 1, params);

    Message* message = messagesQueue->popMessage();
    memoryManager->remove(message, true);
    //exitSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
}
