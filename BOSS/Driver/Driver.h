#ifndef DRIVER_H_
#define DRIVER_H_

#include "../API/dataTypes.h"

class Driver {
public:
	Driver();
	virtual ~Driver();
	
	virtual void init() = 0;
	virtual void write(byte value[]) = 0;
	virtual byte* read(byte position[]) = 0;
	
};

#endif /*DRIVER_H_*/
