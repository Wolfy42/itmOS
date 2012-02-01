#include "SnakeConfig.h"

SnakeConfig::SnakeConfig() : ServiceConfig() {
	initRegistersForMmuMapping();
}

SnakeConfig::~SnakeConfig() {}

void SnakeConfig::initRegistersForMmuMapping(void) {}
