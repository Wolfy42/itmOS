#include "Service-API/Display/Display.h"
#include <string.h>

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
	int params[] = {SERVICE_MOVE_TO, w, h};
	performServiceCall(SERVICE_DRAW_RECT, 3, params);
}

void drawChar(unsigned int c, int scale) {
	int params[] = {SERVICE_DRAW_CHAR, c, scale};
	performServiceCall(DISPLAY_SERVICE_ID, 3, params);
}

void drawString(const char* s, int scale) {
	int stringLength = strlen(s);
	int* params = new int[stringLength / 4 + 2];
	
	params[0] = SERVICE_DRAW_STRING;
	params[1] = scale;
	memcpy(params + 2, s, stringLength);
	
	performServiceCall(DISPLAY_SERVICE_ID, stringLength / 4 + 2, params);
}
