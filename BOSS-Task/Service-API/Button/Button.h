#ifndef BUTTON_H_
#define BUTTON_H_

#include "API/systemCalls.h"
#include "Messaging/MemoryManager/MemoryManager.h"
#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"

enum ButtonServiceCommand {
    BUTTON_SERVICE_REGISTER,
    BUTTON_SERVICE_UNREGISTER
};

void waitForButtonPress();

#endif /*BUTTON_H_*/
