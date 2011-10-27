#include <stdio.h>
#include "HAL/Timer/HalTimerDriver.h"
#include "HAL/LED/HalLedDriver.h"
#include "API/dataTypes.h"

void handler(int id) {
	printf("bla %i", id);
	HalLedDriver led;
	led.ledOff(LED2);
}

void  irqHandler()  {
	printf("irq occured");
	HalLedDriver led;
	led.ledOff(LED2);
}


void swiHandler()  {
	printf("swi occured");
}

//void __irq IRQ_Handler(void) {
//	short vectNum;
//	vectNum = NIVECSR >> 16;// determine highest pending normal interrupt
//	vect_IRQ[vectNum](); // find the pointer to correct ISR in the look up table
//}

int main()
{
	printf("Hello main!");
	
    //switch off led1 for testing
	HalLedDriver led;
	led.ledOff(LED1);

    //register SWI-Handler
   // *(unsigned int volatile *)0x4020FFE8= (unsigned int)&swiHandler;

    //try to make an SWI
    //asm("  SWI 12 ");

	printf("%x", *(unsigned int volatile *)0x00000000);

	// *(unsigned int volatile *)0x4020FFF8= (unsigned int)&irqHandler;
	// *(unsigned int volatile *)0xFFFF0018 = (unsigned int)&irqHandler;
	// *(unsigned int volatile *)0x4020FFDC = (unsigned int)&irqHandler;

	// *(unsigned int volatile *)0x00000018 = (unsigned int)&irqHandler;


	// Try to register interrupt handler
	//*(void**) 0x4020FFF8 = &handler;
	//*(unsigned int volatile *)0x4020FFF8 = (unsigned int)&handler;

	//*(unsigned int volatile *)0x00000008 = (unsigned int)&swiHandler;


	//asm(
	//	"  SWI 12 ;"
	//);

	//Start the timer
	HalTimerDriver dr;

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
