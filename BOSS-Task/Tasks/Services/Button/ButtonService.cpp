
#include "ButtonService.h"

ButtonService::ButtonService() {
    for (int i = 0; i < MAX_LISTENERS; ++i) {
        _listeningTasks[i] = -1;
    }
}

ButtonService::~ButtonService() {
}

bool ButtonService::isTaskListening(int taskId) {
    bool result = false;
    for (int i = 0; (i < MAX_LISTENERS) && (result == false); i++) {
        result = (_listeningTasks[i] == taskId);
    }
    return result;
}

int ButtonService::findFreeSlot() {
    return findTaskId(-1);
}

int ButtonService::findTaskId(int taskId) {
    int result = -1;
    for (int i = 0; (i < MAX_LISTENERS) && (result < 0); ++i) {
        if (_listeningTasks[i] == taskId) {
            result = i;
        }
    }
    return result;
}
void ButtonService::run() {
    bool wasPressed = false;
    while(1) {
        // wait a while and check for messages
        for (int i = 0; i < 1000; i++) {
            if (!(_messagesQueue->isEmpty())) {
                Message* message = _messagesQueue->popMessage();
                executeMessage(message);
        
                _memoryManager->remove(message, true);
            }
        }
        
        // check if button status changed
        if (!wasPressed) {
            if (_buttonDriver.isPressed()) {
                fireEvent();
                wasPressed = true;
            }
        } else {
            wasPressed = _buttonDriver.isPressed();
        }
    }
}

void ButtonService::fireEvent() {
    int response[] = {true};
    for (int i = 0; i < MAX_LISTENERS; ++i) {
        if (_listeningTasks[i] >= 0)  {
            writeResponse(_listeningTasks[i], 1, response);
        }
    }
}
void ButtonService::executeMessage(Message* message) {
    int taskId = message->getTaskId();
    ButtonServiceCommand command = (ButtonServiceCommand)message->getParams()[0];
    int index = -1;
    switch (command) {
        case BUTTON_SERVICE_REGISTER:
            if (!isTaskListening(taskId)) {
                index = findFreeSlot();
                if (index >= 0) {
                    _listeningTasks[index] = taskId;
                }
            }            
            break;
        case BUTTON_SERVICE_UNREGISTER:
            index = findTaskId(taskId);
            if (index >= 0) {
                _listeningTasks[index] = -1;
            }
            break;
        default:
            break;
    }
}
