#include <stdio.h>
#include "HAL/Timer/HalTimerDriver.h"
#include "HAL/LED/HalLedDriver.h"
#include "API/dataTypes.h"
#include "API/systemCalls.h"
#include "Kernel/Interrupt/IRQHandler.h"

void led1Toggler(void)  {
	HalTimerDriver::clearPendingInterrupts(GPTIMER2);

	HalLedDriver dr;
	dr.toggle(LED1);

	HalTimerDriver::resetInternalCounter(GPTIMER2);
}

void led2Toggler(void)  {
	HalTimerDriver::clearPendingInterrupts(GPTIMER3);

	HalLedDriver dr;
	dr.toggle(LED2);
}


int main_()  {
	IRQHandler hand;

	hand.registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER2), led1Toggler);
	hand.registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER3), led2Toggler);

	//_enable_interrupts( ) ;
	
    performSyscall(0x0, NULL);
    
	HalTimerDriver::init(GPTIMER2, GPT_IRQMODE_MATCH, 5000000);
	HalTimerDriver::start(GPTIMER2);

	HalTimerDriver::init(GPTIMER3, GPT_IRQMODE_OVERFLOW, 10000000);
	HalTimerDriver::start(GPTIMER3);
	
	_enable_interrupts( ) ;
	// --> (*0x482000B8) --> man sieht dass bit auf 1 springt und somit sollte der Interrupt ausgelöst werden

	int i = 0;
	while (i<1){}

	_disable_interrupts();
	printf("end\n");
	
	return 0;
}

//----------------------------Timer step by step--------------------------------
/*address target = (address)0x4903201C;//m_baseAddress + GPTIMER_TIER_OFFSET;
*(target) &= 0; // set 0 to disable interrupts
address target2 = (address)0x49032024;//m_baseAddress + GPTIMER_TCLR_OFFSET;
*(target2) &= 0; 	// set 0 to stop timer
address target3 = (address)0x49032028;//m_baseAddress + GPTIMER_TCRR_OFFSET;
*(target3) &= 0; // set 0 to set internal counter
address target4 = (address)0x4903202C;//m_baseAddress + GPTIMER_TLDR_OFFSET;
*(target4) &= 0; // set 0 to set timer load values
address target5 = (address)0x49032038;//m_baseAddress + GPTIMER_TMAR_OFFSET;
*(target5) &= 0; // set 0
*(target5) |= 100; // set 500 to set compare values
address target6 = (address)0x4903201C;//m_baseAddress + GPTIMER_TIER_OFFSET;
*(target6) |= 0x1; // set 1 to enable interrupt
address target7 = (address)0x49032024;//m_baseAddress + GPTIMER_TCLR_OFFSET;
*(target7) |= 0x43; 	// set 0100 0011 to start timer with opt features //2B ist default?*/

//--------------------Test ob Moduel Power on hat (ist on)-------------------------
// PM_PWSTST_PER   0x4830 70E4   POWERSTATEST
// -> GPTIMER 2 hängt an PER
// -> 0x1: PER domain logic is ON
// -> 0x3: Power domain is ON
// ---> Modul hat Power ON

//---------------------HowTo Interrupts-----------------------------------------------------------
// 1. Program the MPU_INTC.INTCPS_SYSCONFIG register: If necessary, enable the interface clock
//    autogating by setting the AUTOIDLE bit.

//2. Program the MPU_INTC.INTCPS_IDLE register: If necessary, disable functional clock autogating or
//   enable synchronizer autogating by setting the FUNCIDLE bit or TURBO bit accordingly.

//3. Program the MPU_INTC.INTCPS_ILRm register for each interrupt line: Assign a priority level and set
//   the FIQNFIQ bit for an FIQ interrupt (by default, interrupts are mapped to IRQ and priority is 0x0
//   [highest]).

//4. Program the MPU_INTC.INTCPS_MIRn register: Enable interrupts (by default, all interrupt lines are
//   masked).
