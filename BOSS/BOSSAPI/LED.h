#ifndef LED_H_
#define LED_H_

#include "LEDConstants.h"

void toggleLED(LED led);
void switchLEDOn(LED led);
void switchLEDOff(LED led);

bool getLEDState(LED led);

#endif /*LED_H_*/
