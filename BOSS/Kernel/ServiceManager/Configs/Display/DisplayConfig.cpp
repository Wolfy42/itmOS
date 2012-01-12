
#include "DisplayConfig.h"

DisplayConfig::DisplayConfig()  {
	initRegistersForMmuMapping();
}

DisplayConfig::~DisplayConfig()  {}

void DisplayConfig::initRegistersForMmuMapping(void) {

	_registersForMmuMapping->push_back(DISPC_BASE);
	_registersForMmuMapping->push_back(CM_DSS_BASE);
    
    for (int i = 0; i < 768; i++) {
        _registersForMmuMapping->push_back((address)((int)0x01FFFD00) + ((int)0x1000) * i);
    }
}
