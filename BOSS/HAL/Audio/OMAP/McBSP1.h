
#ifndef MCBSP1_H_
#define MCBSP1_H_

#include "HAL/Audio/OMAP/McBSP.h"
#include "HAL/Audio/OMAP/System.h"

class McBSP1 {
private:

public:
	McBSP1();
	virtual ~McBSP1();

	void init_mcbsp1();
};

#endif /* MCBSP1_H_ */
