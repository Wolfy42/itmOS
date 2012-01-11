
#include "Service-API/LED/LED.h"

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
    //performServiceCall(LED_SERVICE_ID, led, SERVICE_GET_LED_STATUS);
    //TODO: go to readMessage to obtain the answer
    return false;
}
