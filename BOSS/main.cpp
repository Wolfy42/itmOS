#include <stdio.h>
#include "HAL/Timer/HalTimerDriver.h"
#include "HAL/LED/HalLedDriver.h"

void handler(int id) {
	printf("bla %i", id);
	HalLedDriver led;
	led.ledOff(LED2);	
}

int main_t()
{
	printf("Hello main!");
	
	address targe2t = (address)0x4820004C;
	
	address target = (address)0x4831801C;//m_baseAddress + GPTIMER_TIER_OFFSET;
	*(target) &= 1; 
	
	int i = 1;
	
	/*HalLedDriver led;
	led.ledOff(LED1);	
	
	*(void**) 0x4020FFF8 = &handler;
	HalTimerDriver dr;
	
	int i = 0;
	while (i < 10000000);*/
	
	return 0;
}
