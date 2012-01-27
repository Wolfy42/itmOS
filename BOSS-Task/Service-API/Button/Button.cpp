#include "Button.h"
extern unsigned int messagesStart;

void waitForButtonPress() {
    int params[] = {BUTTON_SERVICE_REGISTER};
    performServiceCall(BUTTON_SERVICE_ID, 1, params);
    
    MemoryManager* memoryManager = (MemoryManager*)&messagesStart;
    MessageQueue* messagesQueue = memoryManager->getMessageQueue();

    Message* message = messagesQueue->popMessage();
    memoryManager->remove(message, true);
    
    params[0] = BUTTON_SERVICE_UNREGISTER;
    performServiceCall(BUTTON_SERVICE_ID, 1, params);
}
