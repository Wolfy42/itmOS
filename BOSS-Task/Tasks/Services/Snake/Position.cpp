#include "Position.h"

Position::Position(int x, int y) : 	
	_x(x), 
	_y(y)
{
}

Position::~Position() {}

int Position::getX(void) {
	return _x;
}

int Position::getY(void) {
	return _y;
}
