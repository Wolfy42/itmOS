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
    SERVICE_DRAW_STRING
};

void setColor(unsigned int rgb);
void moveTo(int x, int y);
void drawPixel();
void drawRect(int w, int h);
void drawChar(unsigned int c, int scale);
void drawString(const char* s, int scale);

#endif /*DISPLAY_H_*/
