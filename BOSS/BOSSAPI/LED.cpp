
#include "API/LED.h"
#include "serviceCalls.h"

void toggleLED(LED led) {
    int params[] = {LED_SERVICE_CALL, 2, led, SERVICE_TOGGLE_LED};
    performServiceCall(params);
}
void switchLEDOn(LED led) {
    int params[] = {LED_SERVICE_CALL, 2, led, SERVICE_SWITCH_LED_ON};
    performServiceCall(params);
}
void switchLEDOff(LED led) {
    int params[] = {LED_SERVICE_CALL, 2, led, SERVICE_SWITCH_LED_OFF};
    performServiceCall(params);
}

bool getLEDState(LED led) {
    int params[] = {LED_SERVICE_CALL, 2, led, SERVICE_GET_LED_STATUS};
    performServiceCall(params);
    return false;
}
