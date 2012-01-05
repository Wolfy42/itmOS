#ifndef LED_H_
#define LED_H_

#include "API/systemCalls.h"
#include "Messaging/MemoryManager/MemoryManager.h"
#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"

enum LED {
    LED1,
    LED2
};

enum LEDServiceCommand {
    SERVICE_TOGGLE_LED = 0,
    SERVICE_SWITCH_LED_ON = 1,
    SERVICE_SWITCH_LED_OFF = 2,
    SERVICE_GET_LED_STATUS = 3
};

void toggleLED(LED led);
void switchLEDOn(LED led);
void switchLEDOff(LED led);

bool getLEDState(LED led);

#endif /*LED_H_*/
