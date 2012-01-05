
#include "Service-API/LED/LED.h"

extern volatile unsigned int messagesStart;

void toggleLED(LED led) {
    performServiceCall(LED_SERVICE_ID, led, SERVICE_TOGGLE_LED);
}
void switchLEDOn(LED led) {
    performServiceCall(LED_SERVICE_ID, led, SERVICE_SWITCH_LED_ON);
}
void switchLEDOff(LED led) {
    performServiceCall(LED_SERVICE_ID, led, SERVICE_SWITCH_LED_OFF);
}
bool getLEDState(LED led) {

    performServiceCall(LED_SERVICE_ID, led, SERVICE_GET_LED_STATUS);
	MemoryManager* memoryManager = (MemoryManager*)&messagesStart;
	MessageQueue* messagesQueue = memoryManager->getMessageQueue();

	if (messagesQueue->isEmpty()) {
		performSystemCall(SUSPEND);
	}

	while (messagesQueue->isEmpty())  {

	}
	Message* message = messagesQueue->popMessage();
	bool state = message->getParams()[0];
	memoryManager->remove(message, true);

    return state;
}
