#include "Service-API/LED/LED.h"
#include "Service-API/Display/Display.h"

int main() {

	switchLEDOff(LED1);
	int i=0;
	
	moveTo(580, 100);
	drawChar(51, 5);
	
	setColor(0x0000FF);
	moveTo(640, 100);
	drawChar(52, 5);
	
	while (1)  {
		i = 0;
		while (i < 800000)  {
			i++;
		}
		
		if (i % 2) {
			setColor(0x0000FF);
			moveTo(480, 200);
			drawChar(49, 5);
			
			setColor(0xFF0000);
			moveTo(540, 200);
			drawChar(50, 5);
		} else {
			setColor(0xFF0000);
			moveTo(480, 200);
			drawChar(49, 5);
			
			setColor(0x0000FF);
			moveTo(540, 200);
			drawChar(50, 5);
		}
		
		if (getLEDState(LED2))  {
			switchLEDOff(LED2);
			switchLEDOn(LED1);
			
			// Set LED1 On
			setColor(0x0000FF);
			moveTo(580, 200);
			drawChar(49, 5);
			
//			setColor(0x0000FF);
//			moveTo(580, 200);
//			drawRect(50, 50);

			// Set LED2 Off
//			setColor(0xFF007F);
//			moveTo(680, 200);
//			drawRect(50, 50);			
		}  else  {
			switchLEDOn(LED2);
			switchLEDOff(LED1);
			
			// Set LED1 On
//			setColor(0xFF007F);
//			moveTo(580, 200);
//			drawRect(50, 50);
			
			// Set LED2 On
			setColor(0xFF0000);
			moveTo(640, 200);
			drawChar(50, 5);
//			moveTo(680, 200);
//			drawRect(50, 50);
			
		}
	}
}
