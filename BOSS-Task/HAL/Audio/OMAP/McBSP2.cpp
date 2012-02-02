/*
 * McBSP2.cpp
 *
 *  Created on: Dec 2, 2011
 *      Author: stefan
 */
#include "HAL/Audio/OMAP/McBSP2.h"
#include "HAL/Audio/OMAP/PRCM.h"
#include "Lib/bitOperations.h"

McBSP2::McBSP2() {}
McBSP2::~McBSP2() {}

/*
 * sets the registers of the McBSP2 module
 */
void McBSP2::init_mcbsp2() {
// Programming Model page 2049
// Clocks
	// set the McBSP2 clock -> using functional clock -> page 1998, 708 (register overview)
	unsetBit( (address) (CONTROL_GENERAL_BASE + CONTROL_DEVCONF0), MCBSP2_CLKS_BIT);

	// Power-Domain Clock Control Registers
	// CM_FCLKEN_PER (Functional Clock Enable Register - domain peripherals set)
	// CM_ICLKEN_PER (Interface Clock Enable Register - domain peripherals set)
	// Because a module may or may not be able to function without its IC of FC
	// it requires consistent programming of CM_FCLKEN and CM_ICLKEN registers!
	// Therefore we turn both clocks on -> Uhrenvergleich! :)
	// page 299 - 301
	setBit( (address) (PER_CM_BASE + CM_FCLKEN_PER), EN_MCBSP2);
	setBit( (address) (PER_CM_BASE + CM_ICLKEN_PER), EN_MCBSP2);

// Hardware and Software Reset
	// McBSP2,3 and 4 belong to the PER Domain and their reset signal is the PER_RST from the RRCM module
	// set the transmitter in reset mode (needed to configure) page 2083
	unsetBit( (address) (MCBSP2_BASE + MCBSPLP_SPCR2_REG), MCBSP_FRST_BIT);
	unsetBit( (address) (MCBSP2_BASE + MCBSPLP_SPCR2_REG), MCBSP_XRST_BIT);
	// set the receiver in reset mode (needed to configure) page 2086
	unsetBit( (address) (MCBSP2_BASE + MCBSPLP_SPCR1_REG), MCBSP_RRST_BIT);

// disable gpio-mode
	setBit( (address) (MCBSP2_BASE + MCBSPLP_PCR_REG), 0);

// xmit format page 2088
	// XCR1
	setBit( (address) (MCBSP2_BASE + MCBSPLP_XCR1_REG), MCBSP_WDLEN_16_BIT); 	// 16-bit word length for phase 1
	setBit( (address) (MCBSP2_BASE + MCBSPLP_XCR1_REG), RFRLEN2_BIT);			// framelength = 1 word

	// XCR2
	setBit( (address) (MCBSP2_BASE + MCBSPLP_XCR2_REG), RPHASE_DUAL_BIT); 		// 2 phase
	setBit( (address) (MCBSP2_BASE + MCBSPLP_XCR2_REG), RDATDLY_ONE_BIT);		// delay of 1 ms for i2s page
	unsetBit( (address) (MCBSP2_BASE + MCBSPLP_XCR2_REG), RFRLEN2_BIT);			// framelength = 1 word
	setBit( (address) (MCBSP2_BASE + MCBSPLP_XCR2_REG), MCBSP_WDLEN_16_BIT);	// 16-bit word length for phase 2

// receive format
	//	RCR1
	setBit( (address) (MCBSP2_BASE + MCBSPLP_RCR1_REG), MCBSP_WDLEN_16_BIT); 	// 16-bit word length for phase 1
	setBit( (address) (MCBSP2_BASE + MCBSPLP_RCR1_REG), RFRLEN2_BIT);			// framelength = 1 word

	// RCR2
	setBit( (address) (MCBSP2_BASE + MCBSPLP_RCR2_REG), RPHASE_DUAL_BIT); 		// 2 phase
	setBit( (address) (MCBSP2_BASE + MCBSPLP_RCR2_REG), RDATDLY_ONE_BIT);		// delay of 1 ms for i2s page
	unsetBit( (address) (MCBSP2_BASE + MCBSPLP_RCR2_REG), RFRLEN2_BIT);			// framelength = 1 word
	setBit( (address) (MCBSP2_BASE + MCBSPLP_RCR2_REG), MCBSP_WDLEN_16_BIT);	// 16-bit word length for phase 2

// disable DMA
	//setBit( (address) (MCBSP1_BASE + MCBSPLP_XCCR_REG), XDISABLE_BIT);

// clock polarity
	// receiver
	setBit( (address) (MCBSP1_BASE + MCBSPLP_PCR_REG), MCBSP_CLKRP_BIT); // rising edge
	setBit( (address) (MCBSP1_BASE + MCBSPLP_PCR_REG), MCBSP_CLKXP_BIT); // falling edge

	// Delay to allow settings to sync (hopefully 2 SRG clock cycles)
	for (int loop=0; loop < 0XFF; loop++);

// wake up!
	// wake up the transmitter of reset mode (needed to configure) page 2083
	setBit( (address) (MCBSP2_BASE + MCBSPLP_SPCR2_REG), MCBSP_FRST_BIT);
	setBit( (address) (MCBSP2_BASE + MCBSPLP_SPCR2_REG), MCBSP_XRST_BIT);
	// wake up the receiver of reset mode (needed to configure) page 2086
	setBit( (address) (MCBSP2_BASE + MCBSPLP_SPCR1_REG), MCBSP_RRST_BIT);
}
