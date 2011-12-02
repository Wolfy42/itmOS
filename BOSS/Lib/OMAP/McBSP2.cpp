/*
 * McBSP2.cpp
 *
 *  Created on: Dec 2, 2011
 *      Author: stefan
 */
#include "Lib/OMAP/McBSP2.h"
#include "Lib/bitOperations.h"

McBSP2::McBSP2() {}
McBSP2::~McBSP2() {}

/*
 * sets the registers of the McBSP2 module
 */
void McBSP2::init_mcbsp2() {
	// set the McBSP2 clock -> using functional clock (CLKS on the 6th bit) -> page 1998, 708 (register overview)
	setBit( (address) (CONTROL_GENERAL_BASE + CONTROL_DEVCONF0), 6);

}
