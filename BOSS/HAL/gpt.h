#ifndef GPT_H_
#define GPT_H_

#include "API/dataTypes.h"

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


// Timer offset adresses
#define GPT_TIER_OFFSET 0x1C	// This register controls (enable/disable) the interrupt events
#define GPT_TISR_OFFSET 0x18	// This register shows which interrupt events are pending inside the module
#define GPT_TCLR_OFFSET 0x24	// This register controls optional features specific to the timer functionality
#define GPT_TCRR_OFFSET 0x28	// This register holds the value of the internal counter
#define GPT_TLDR_OFFSET 0x2C	// This register holds the timer load values
#define GPT_TTGR_OFFSET 0x30	// This register triggers a counter reload of timer by writing any value in it
#define GPT_TMAR_OFFSET 0x38	// This register holds the value to be compared with the counter value (TCRR)


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
#define GPT_TCLR_COMPARE 	6	// Compare enable
#define GPT_TCLR_AUTORELOAD 1	// Autoreload mode
#define GPT_TCLR_START 		0	// Start/stop timer control




#endif /*GPT_H_*/
