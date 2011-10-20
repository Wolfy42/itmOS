#ifndef GPT_H_
#define GPT_H_

#include "../API/dataTypes.h"

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
#define GPTIMER_TIER_OFFSET 0x01C	// Enable Interrupt
#define GPTIMER_TCLR_OFFSET 0x024	// Optional features
#define GPTIMER_TCRR_OFFSET 0x028	// Internal Counter
#define GPTIMER_TLDR_OFFSET 0x02C	// Timer load values
#define GPTIMER_TMAR_OFFSET 0x038	// Value to be compared with TCRR

#endif /*GPT_H_*/
