/*
 * System.h
 *
 *  Created on: Dec 2, 2011
 *      Author: stefan
 */

#ifndef SYSTEM_H_
#define SYSTEM_H_

/*
 * System Control Module Registers -> page 689
 *
 * (needed for McBSP configuration -> page 1993)
 */
// System Control Module and its register CONTROL_DEVCONF0[6]
#define CONTROL_GENERAL_BASE 	0x48002270

// DEVCONF0 of GENERAL BASE -> page 691
#define CONTROL_DEVCONF0		0x00000004

// CLKS
#define CONTROL_MCBSP2_CLKS 	(1<<6)

#endif /* SYSTEM_H_ */
