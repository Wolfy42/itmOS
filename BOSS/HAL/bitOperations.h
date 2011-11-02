#ifndef BITOPERATIONS_H_
#define BITOPERATIONS_H_

#include "../API/dataTypes.h"

void setBit(address number, int bitOffset);

void unsetBit(address number, int bitOffset);

void toggleBit(address number, int bitOffset);

bool readBit(address number, int bitOffset);

#endif /*BITOPERATIONS_H_*/
