
#include "ButtonService.h"

ButtonService::ButtonService() {
}

ButtonService::~ButtonService() {
}


void ButtonService::execute(int params[]) {
	HalButtonDriver buttonDriver;
	bool isPressed = buttonDriver.isPressed();

	while (!isPressed);
}
