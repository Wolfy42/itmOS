#include "Service-API/Display/Display.h"
#include <string.h>

extern volatile unsigned int messagesStart;

bool hasScreen() {
    int params[] = {SERVICE_HAS_TASK_SCREEN};
    performServiceCall(DISPLAY_SERVICE_ID, 1, params);
    
    MemoryManager* memoryManager = (MemoryManager*)&messagesStart;
    MessageQueue* messagesQueue = memoryManager->getMessageQueue();

    Message* message = messagesQueue->popMessage();
    bool result = message->getParams()[0];
    memoryManager->remove(message, true);
    return result;
}

void setColor(unsigned int rgb) {
	int params[] = {SERVICE_SET_COLOR, rgb};
	performServiceCall(DISPLAY_SERVICE_ID, 2, params);
    
}

void moveTo(int x, int y) {
	int params[] = {SERVICE_MOVE_TO, x, y};
	performServiceCall(DISPLAY_SERVICE_ID, 3, params);
    
    
}

void drawPixel() {
	int params[] = {SERVICE_DRAW_PIXEL};
	performServiceCall(DISPLAY_SERVICE_ID, 1, params);
    
    
}

void drawRect(int w, int h) {
	int params[] = {SERVICE_DRAW_RECT, w, h};
	performServiceCall(DISPLAY_SERVICE_ID, 3, params);
    
}

void drawChar(unsigned int c, int scale) {
	int params[] = {SERVICE_DRAW_CHAR, c, scale};
	performServiceCall(DISPLAY_SERVICE_ID, 3, params);
    
}

void drawString(const char* s, int scale) {
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
    
}

void switchTask() {
    int params[] = {SERVICE_SWITCH_TASK, 0};
    performServiceCall(DISPLAY_SERVICE_ID, 2, params);
}
