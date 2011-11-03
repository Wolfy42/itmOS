
#ifndef CONFIG_H_
#define CONFIG_H_

#include "API/dataTypes.h"

// maximum number of different IRQ-Handlers
#define MAX_IRQ_HANDLERS 96

#define INTCPS_CONTROL (address) 0x48200048
#define INTCPS_SIR_IRQ (address) 0x48200040

#define INTCPS_MIR_SET_0 (address) 0x48200088
#define INTCPS_MIR_SET_1 (address) 0x482000A8
#define INTCPS_MIR_SET_2 (address) 0x482000C8

#endif /* CONFIG_H_ */
