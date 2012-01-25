
#include "ButtonService.h"

ButtonService::ButtonService() {
}

ButtonService::~ButtonService() {
}


void ButtonService::executeMessage(Message* message) {
	int response[] = {_buttonDriver.isPressed()};
    writeResponse(message->getTaskId(), 1, response);
}
