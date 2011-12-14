#ifndef SERVICECALLS_H_
#define SERVICECALLS_H_

#include "API/dataTypes.h"

#define TIMER_SERVICE 0x60
#define BUTTON_SERVICE 0xB
#define LED_SERVICE 0xED
#define SERIAL_SERVICE 0x11

void performServiceCall(int params[]);

#endif /*SERVICECALLS_H_*/
