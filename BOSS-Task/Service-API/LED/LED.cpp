#include "API/Semaphore.h"
#include "Service-API/LED/LED.h"

extern volatile unsigned int messagesStart;

void toggleLED(LED led) {
    int params[] = {led, SERVICE_TOGGLE_LED};
    //enterSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, LED_SERVICE_ID);
    performServiceCall(LED_SERVICE_ID, 2, params);
    //exitSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, LED_SERVICE_ID);
}
void switchLEDOn(LED led) {
    int params[] = {led, SERVICE_SWITCH_LED_ON};
    //enterSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, LED_SERVICE_ID);
    performServiceCall(LED_SERVICE_ID, 2, params);
    //exitSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, LED_SERVICE_ID);
}
void switchLEDOff(LED led) {
    int params[] = {led, SERVICE_SWITCH_LED_OFF};
    //enterSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, LED_SERVICE_ID);
    performServiceCall(LED_SERVICE_ID, 2, params);
    //exitSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, LED_SERVICE_ID);
}
bool getLEDState(LED led) {

	int params[] = {led, SERVICE_GET_LED_STATUS};
    //enterSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, LED_SERVICE_ID);
	performServiceCall(LED_SERVICE_ID, 2, params);
    //exitSemaphore(SEMAPHORE_SERVICE_MESSAGE_QUEUE, LED_SERVICE_ID);

	MemoryManager* memoryManager = (MemoryManager*)&messagesStart;
	MessageQueue* messagesQueue = memoryManager->getMessageQueue();

    //enterSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
	while (messagesQueue->isEmpty()) {
        //exitSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
		performSystemCall(SUSPEND);
        //enterSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
	}


	Message* message = messagesQueue->popMessage();
	bool state = message->getParams()[0];
	memoryManager->remove(message, true);
    //exitSemaphore(SEMAPHORE_OWN_MESAGE_QUEUE, 0);
	return state;
}
