/*
 * McBSP2.h
 *
 *  Created on: Dec 2, 2011
 *      Author: stefan
 */

#ifndef MCBSP2_H_
#define MCBSP2_H_

#include "HAL/Audio/OMAP/McBSP.h"
#include "HAL/Audio/OMAP/System.h"

class McBSP2 {
private:

public:
	McBSP2();
	virtual ~McBSP2();

	void init_mcbsp2();
};

#endif /* MCBSP2_H_ */
