#include "Service-API/Display/Display.h"

void setColor(unsigned int rgb) {
	int params[] = {SERVICE_SET_COLOR, rgb};
}

void moveTo(int x, int y) {
}

void drawPixel() {
}

void drawRect(int w, int h) {
}

void drawChar(unsigned int c, int scale) {
}

void drawString(const char* s, int scale) {
}
