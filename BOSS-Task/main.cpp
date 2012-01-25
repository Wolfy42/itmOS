#include "Service-API/LED/LED.h"
#include "Service-API/Display/Display.h"

int main__() {

    bool hasScreen = moveTo(0, 0);
    if (hasScreen) {
        drawRect(1023, 767);
    }
	switchLEDOff(LED1);
	int i=0;
	
	while (1)  {
		i = 0;
		while (i < 800000)  {
			i++;
		}
		
		if (getLEDState(LED2))  {
			switchLEDOff(LED2);
			switchLEDOn(LED1);
			
			// Set LED1 On
            if (hasScreen) {
    			setColor(0x0000FF);
    			moveTo(580, 200);
    			drawChar('1', 5);
                
    			// Set LED2 Off
    			setColor(0xFF0000);
    			moveTo(640, 200);
    			drawChar('2', 5);
            }
		}  else  {
			switchLEDOn(LED2);
			switchLEDOff(LED1);
			
            if (hasScreen) {
    			// Set LED1 On
    			setColor(0xFF0000);
    			moveTo(580, 200);
    			drawChar('1', 5);
    			
    			// Set LED2 On
    			setColor(0x0000FF);
    			moveTo(640, 200);
    			drawChar('2', 5);
            }
			
		}
	}
}
