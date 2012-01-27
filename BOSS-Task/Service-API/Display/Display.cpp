#include "Service-API/Display/Display.h"
#include <string.h>

extern volatile unsigned int messagesStart;

bool hasScreen() {
    MemoryManager* memoryManager = (MemoryManager*)&messagesStart;
    MessageQueue* messagesQueue = memoryManager->getMessageQueue();

    Message* message = messagesQueue->popMessage();
    bool result = message->getParams()[0];
    memoryManager->remove(message, true);
    return result;
}

bool setColor(unsigned int rgb) {
	int params[] = {SERVICE_SET_COLOR, rgb};
	performServiceCall(DISPLAY_SERVICE_ID, 2, params);
    
    return hasScreen();
}

bool moveTo(int x, int y) {
	int params[] = {SERVICE_MOVE_TO, x, y};
	performServiceCall(DISPLAY_SERVICE_ID, 3, params);
    
    return hasScreen();
}

bool drawPixel() {
	int params[] = {SERVICE_DRAW_PIXEL};
	performServiceCall(DISPLAY_SERVICE_ID, 1, params);
    
    return hasScreen();
}

bool drawRect(int w, int h) {
	int params[] = {SERVICE_DRAW_RECT, w, h};
	performServiceCall(DISPLAY_SERVICE_ID, 3, params);
    return hasScreen();
}

bool drawChar(unsigned int c, int scale) {
	int params[] = {SERVICE_DRAW_CHAR, c, scale};
	performServiceCall(DISPLAY_SERVICE_ID, 3, params);
    return hasScreen();
}

bool drawString(const char* s, int scale) {
	int stringLength = strlen(s);
    
    int paramsLength = stringLength / 4 + 2;
    if (stringLength % 4 != 0) {
        paramsLength++;
    }
	int* params = new int[paramsLength];
	
	params[0] = SERVICE_DRAW_STRING;
	params[1] = scale;
	std::memcpy(&(params[2]), s, stringLength);
	
	performServiceCall(DISPLAY_SERVICE_ID, paramsLength, params);
    return hasScreen();
}

void switchTask() {
    int params[] = {SERVICE_SWITCH_TASK, 0};
    performServiceCall(DISPLAY_SERVICE_ID, 2, params);
}
