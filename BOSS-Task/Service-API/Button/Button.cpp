#include "Button.h"
extern unsigned int messagesStart;

bool isPressed() {
    int params[] = {0};
    performServiceCall(BUTTON_SERVICE_ID, 0, params);
    MemoryManager* memoryManager = (MemoryManager*)&messagesStart;
    MessageQueue* messagesQueue = memoryManager->getMessageQueue();

    //enterSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
    while (messagesQueue->isEmpty()) {
        //exitSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
        //performSystemCall(SUSPEND);
        //enterSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
    }


    Message* message = messagesQueue->popMessage();
    bool result = message->getParams()[0];
    memoryManager->remove(message, true);
    //exitSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
    return result;
}
