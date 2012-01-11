
#include "Service-API/LED/LED.h"

extern volatile unsigned int messagesStart;

void toggleLED(LED led) {
    int params[] = {led, SERVICE_TOGGLE_LED};
    performServiceCall(LED_SERVICE_ID, 2, params);
}
void switchLEDOn(LED led) {
    int params[] = {led, SERVICE_SWITCH_LED_ON};
    performServiceCall(LED_SERVICE_ID, 2, params);
}
void switchLEDOff(LED led) {
    int params[] = {led, SERVICE_SWITCH_LED_OFF};
    performServiceCall(LED_SERVICE_ID, 2, params);
}
bool getLEDState(LED led) {

	int params[] = {led, SERVICE_GET_LED_STATUS};
	performServiceCall(LED_SERVICE_ID, 2, params);

	MemoryManager* memoryManager = (MemoryManager*)&messagesStart;
	MessageQueue* messagesQueue = memoryManager->getMessageQueue();

//	if (messagesQueue->isEmpty()) {
//		performSystemCall(SUSPEND);
//	}

	while (messagesQueue->isEmpty())  {

	}

	Message* message = messagesQueue->popMessage();
	bool state = message->getParams()[0];
	memoryManager->remove(message, true);
	return state;
}
