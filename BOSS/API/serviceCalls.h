#ifndef SERVICECALLS_H_
#define SERVICECALLS_H_

#include "dataTypes.h"

#define TIMER_SERVICE_CALL 0x60
#define BUTTON_SERVICE_CALL 0xB
#define LED_SERVICE_CALL 0xED

void performServiceCall(int serviceCallId, byte params[]);

#endif /*SERVICECALLS_H_*/
