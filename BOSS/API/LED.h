#ifndef LED_H_
#define LED_H_

enum LED {
    LED1 = 0,
    LED2 = 1
};

enum LEDServiceCommand {
    SERVICE_TOGGLE_LED,
    SERVICE_SWITCH_LED_ON,
    SERVICE_SWITCH_LED_OFF,
    SERVICE_GET_LED_STATUS
};

void toggleLED(LED led);
void switchLEDOn(LED led);
void switchLEDOff(LED led);

bool getLEDState(LED led);

#endif /*LED_H_*/
