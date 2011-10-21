#include <stdio.h>
#include "HAL/Timer/HalTimerDriver.h"
#include "HAL/LED/HalLedDriver.h"
#include "API/dataTypes.h"

void handler(int id) {
	printf("bla %i", id);
	HalLedDriver led;
	led.ledOff(LED2);	
}

int main()
{
	printf("Hello main!");
	
	// 1. Program the MPU_INTC.INTCPS_SYSCONFIG register: If necessary, enable the interface clock
	//    autogating by setting the AUTOIDLE bit.

	//2. Program the MPU_INTC.INTCPS_IDLE register: If necessary, disable functional clock autogating or
	//   enable synchronizer autogating by setting the FUNCIDLE bit or TURBO bit accordingly.

	//3. Program the MPU_INTC.INTCPS_ILRm register for each interrupt line: Assign a priority level and set
	//   the FIQNFIQ bit for an FIQ interrupt (by default, interrupts are mapped to IRQ and priority is 0x0
	//   [highest]).

	//4. Program the MPU_INTC.INTCPS_MIRn register: Enable interrupts (by default, all interrupt lines are
	//   masked).

	//address mirn = (address)0x48200000;

	address psqr = (address)0x600001D0;

	printf("before: %x\n", *psqr);
	//*psqr |= 0x1F;
	//printf("after: %x\n", *psqr);



	//printf("binary: %x\n",0b10000);

	//*(volatile unsigned int*)0x48200000 = 0xFFFFFFFF;
	//address prio = (address)0x4820004C;
	//printf("prio: %x\n", *prio);

//	printf("reset: %x\n", *mirn);

	//*mirn |= 1;
	//*mirn |= (1 << 2);

	//printf("test: %x\n", *mirn);

	//*mirn &= (0 << 7);
	//int i = 0;
	//while (i< 32)  {
	//	*mirn &= ~(1 << i);
	//	i++;
	//}

	//printf("register: %x\n", *mirn);


	//address targe2t = (address)0x4820004C;
	//printf("test: %x\n", *targe2t);
	
	//address target = (address)0x4831801C;//m_baseAddress + GPTIMER_TIER_OFFSET;
	//*(target) &= 1;
	
	//i = 1;
	
	/*HalLedDriver led;
	led.ledOff(LED1);	
	
	*(void**) 0x4020FFF8 = &handler;
	HalTimerDriver dr;
	
	int i = 0;
	while (i < 10000000);*/
	
	return 0;
}
