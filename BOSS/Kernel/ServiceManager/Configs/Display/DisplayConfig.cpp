
#include "DisplayConfig.h"

DisplayConfig::DisplayConfig()  {
	initRegistersForMmuMapping();
}

DisplayConfig::~DisplayConfig()  {}

void DisplayConfig::initRegistersForMmuMapping(void) {

	_registersForMmuMapping->push_back(DISPC_BASE);
	_registersForMmuMapping->push_back(CM_DSS_BASE);
}
