
#include "Service-API/LED/LED.h"

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
    //TODO: go to readMessage to obtain the answer
    return false;
}
