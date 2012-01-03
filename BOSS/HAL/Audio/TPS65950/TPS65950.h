/*
 * TPS65950.h
 *
 *  Created on: Dec 21, 2011
 *      Author: stefan
 */

#ifndef TPS65950_H_
#define TPS65950_H_

#include <stdint.h>

class TPS65950 {
private:
	void audioRegW(uint32_t address, uint32_t value);

public:
	TPS65950();
	virtual ~TPS65950();

	void init_tps65950();
};


#endif /* TPS65950_H_ */
