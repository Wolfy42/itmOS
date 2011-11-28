#ifndef GPT_H_
#define GPT_H_

#include "API/dataTypes.h"


enum Timer {
	GPTIMER1 = 1,
	GPTIMER2 = 2,
	GPTIMER3 = 3,
	GPTIMER4 = 4,
	GPTIMER5 = 5,
	GPTIMER6 = 6,
	GPTIMER7 = 7,
	GPTIMER8 = 8,
	GPTIMER9 = 9,
	GPTIMER10 = 10,
	GPTIMER11 = 11
};


// 32kHz Clock Frequence
#define CLK_FREQUENCE 32.768


// 1ms Value
#define ONE_MS_VALUE 0xFFFFFFE0


// Timer base adresses
#define GPTIMER1_BASE (address)0x48318000
#define GPTIMER2_BASE (address)0x49032000
#define GPTIMER3_BASE (address)0x49034000
#define GPTIMER4_BASE (address)0x49036000
#define GPTIMER5_BASE (address)0x49038000
#define GPTIMER6_BASE (address)0x4903A000
#define GPTIMER7_BASE (address)0x4903C000
#define GPTIMER8_BASE (address)0x4903E000
#define GPTIMER9_BASE (address)0x49040000
#define GPTIMER10_BASE (address)0x48086000
#define GPTIMER11_BASE (address)0x48088000


// Registers to enable and set up GPTIMER1
#define CM_FCLKEN_WKUP (address) 0x48004C00		// Controls the modules functional clock activity
#define CM_ICLKEN_WKUP (address) 0x48004C10		// Controls the modules interface clock activity.
#define EN_GPT1					0				// GPTIMER1 clock control


#define CM_IDLEST_WKUP (address) 0x48004C20		// WAKEUP domain modules access monitoring.This register is read only and automatically updated.
#define ST_GPT1					0				// GPTIMER 1 idle status | 0x0: GPTIMER 1 can be accessed. | 0x1: GPTIMER 1 cannot be accessed. Any access may return an error.


#define TIOCP_CFG_GPT1 (address) 0x48318010		// This register controls the various parameters of the GP timer L4 interface.
#define SOFTRESET				1				// Software reset. This bit is automatically reset by the hardware. During reads, it always returns 0. | 0x0: Normal mode. | 0x1: The module is reset.


#define TISTAT_GPT1 (address) 0x48318014		// 
#define RESETDONE 				0				// Internal reset monitoring. | 0x0: Internal module reset is ongoing. | 0x1: Reset completed.


#define CM_CLKSEL_WKUP (address) 0x48004C40		// WAKEUP domain modules source clock selection. (GPT1 = BitNo. 0)
#define CLKSEL_GPT1_32K_FCLK	0 				// source is 32K_FCLK
#define CLKSEL_GPT1_SYS_CLK		1				// source is SYS_CLK
// ~~~~~ Registers to enable and set up GPTIMER1 ~~~~~ 


// Timer offset adresses
#define GPT_TIER_OFFSET 0x1C	// This register controls (enable/disable) the interrupt events
#define GPT_TISR_OFFSET 0x18	// This register shows which interrupt events are pending inside the module
#define GPT_TCLR_OFFSET 0x24	// This register controls optional features specific to the timer functionality
#define GPT_TCRR_OFFSET 0x28	// This register holds the value of the internal counter
#define GPT_TLDR_OFFSET 0x2C	// This register holds the timer load values
#define GPT_TTGR_OFFSET 0x30	// This register triggers a counter reload of timer by writing any value in it
#define GPT_TMAR_OFFSET 0x38	// This register holds the value to be compared with the counter value (TCRR)
#define GPT_TPIR_OFFSET 0x48	// This register is used for 1 ms tick generation. The TPIR register holds the value of the positive increment. 
#define GPT_TNIR_OFFSET 0x4C	// This register is used for 1 ms tick generation. The TNIR register holds the value of the negative increment.
#define GPT_TOCR_OFFSET 0x54	// This register is used to mask the tick interrupt for a selected number of ticks.
#define GPT_TOWR_OFFSET 0x58	// This register holds the number of masked overflow interrupts.


// Timer IRQ Numbers (Offset only)
#define GPT_MPU_IRQ_ID_START 37		// The first MPU-IRQ for the timer module (-> GPTIMER1)
#define GPT_MPU_IRQ_ID_END 47		// The last MPU-IRQ for the timer module (-> GPTIMER11)


// TIER Fields 
enum GptInterruptMode {
	GPT_IRQMODE_CAPTURE = 2,		// Enable capture Interrupt
	GPT_IRQMODE_OVERFLOW = 1,		// Enable overflow Interrupt
	GPT_IRQMODE_MATCH = 0			// Enable match Interrupt
};


// TISR Fields 
#define GPT_PENDING_CAPTURE  	2	// Pending capture interrupt status
#define GPT_PENDING_OVERFLOW	1	// Pending overflow interrupt status
#define GPT_PENDING_MATCH 		0	// Pending match interrupt status


// TCLR Fields
#define GPT_TCLR_TRG_OVF_MAT	11	// Trigger Overflow and Match
#define GPT_TCLR_TRG_OVF    	10	// Trigger Overflow
#define GPT_TCLR_COMPARE 		6	// Compare enable
#define GPT_TCLR_AUTORELOAD 	1	// Autoreload mode
#define GPT_TCLR_START 			0	// Start/stop timer control


// PER domain modules source clock selection for GPT2 to GPT9
#define CM_CLKSEL_PER   (address) 0x48005040    // Clock Selection Register
#define CM_CLKSEL_GPT2  0						// 0x0: source is 32K_FCLK | 0x1: source is SYS_CLK
#define CM_CLKSEL_GPT3  1
#define CM_CLKSEL_GPT4  2
#define CM_CLKSEL_GPT5  3
#define CM_CLKSEL_GPT6  4
#define CM_CLKSEL_GPT7  5
#define CM_CLKSEL_GPT8  6
#define CM_CLKSEL_GPT9  7


#endif /*GPT_H_*/
