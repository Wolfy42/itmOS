#ifndef SYSTEMCALLS_H_
#define SYSTEMCALLS_H_

#include "API/dataTypes.h"

//--------------------------------System - Calls ----------------------
#define EXIT                0x1
#define KILL                0x2
#define EXEC                0x3
#define FORK                0x4
#define YIELD               0x5

#define WRITE               0x6
#define WRITE_RESPONE       0x7

#define SUSPEND	            0x8

//--------------------------------Service- IDs--------------------------
#define TIMER_SERVICE_ID 0x60
#define BUTTON_SERVICE_ID 0xB
#define LED_SERVICE_ID 0xED
#define SERIAL_SERVICE_ID 0x11

//--------------------------------SWI to Kernel------------------------
#pragma SWI_ALIAS(0);
void swi(int swiNumber, int para1, int para2, int para3, int para4, int para5, int para6, int para7);

void performSystemCall(int systemCallId);
void performSystemCall(int systemCallId, int para1);
void performServiceCall(int serviceId, int para1, int para2);

#endif /*SYSTEMCALLS_H_*/
