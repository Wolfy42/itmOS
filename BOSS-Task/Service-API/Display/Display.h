#ifndef DISPLAY_H_
#define DISPLAY_H_

#include "API/systemCalls.h"

#include "Messaging/MemoryManager/MemoryManager.h"
#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"

enum DisplayServiceCommand {
    SERVICE_SET_COLOR,
    SERVICE_MOVE_TO,
    SERVICE_DRAW_PIXEL,
    SERVICE_DRAW_RECT,
    SERVICE_DRAW_CHAR,
    SERVICE_DRAW_STRING,
    SERVICE_SWITCH_TASK = 398
};

bool setColor(unsigned int rgb);
bool moveTo(int x, int y);
bool drawPixel();
bool drawRect(int w, int h);
bool drawChar(unsigned int c, int scale);
bool drawString(const char* s, int scale);
void switchTask();

#endif /*DISPLAY_H_*/
