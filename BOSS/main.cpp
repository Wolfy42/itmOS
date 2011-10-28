#include <stdio.h>
#include "HAL/Timer/HalTimerDriver.h"
#include "HAL/LED/HalLedDriver.h"
#include "API/dataTypes.h"


#pragma INTERRUPT (SWI) ;
extern "C" void c_intSWI()  {
	printf("swi");
}


#pragma INTERRUPT (IRQ) ;
extern "C"  void c_intIRQ()  {
	printf("irq");
}

#pragma SWI_ALIAS(48);
int swi ();


int main()
{
	printf("Hello main!");
	
	swi();

	printf("swi finished!");


	//_enable_interrupts( ) ;
	//_disable_interrupts( ) ;


	//Start the timer
	//HalTimerDriver dr;

	//Enable the interrupt for the timer
	//address res = (address)0x482000C8;
	//*res |= (1 << 6);
	
	//loop to wait for interrupt
	//int i=10;
	//while (1){}

	//while (i<1) {
	//	i = 0;
	//}
	
	return 0;
}


// 1. Program the MPU_INTC.INTCPS_SYSCONFIG register: If necessary, enable the interface clock
//    autogating by setting the AUTOIDLE bit.

//2. Program the MPU_INTC.INTCPS_IDLE register: If necessary, disable functional clock autogating or
//   enable synchronizer autogating by setting the FUNCIDLE bit or TURBO bit accordingly.

//3. Program the MPU_INTC.INTCPS_ILRm register for each interrupt line: Assign a priority level and set
//   the FIQNFIQ bit for an FIQ interrupt (by default, interrupts are mapped to IRQ and priority is 0x0
//   [highest]).

//4. Program the MPU_INTC.INTCPS_MIRn register: Enable interrupts (by default, all interrupt lines are
//   masked).
