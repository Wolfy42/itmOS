#include "Service-API/LED/LED.h"
#include "Service-API/Display/Display.h"

int main________________() {

	switchLEDOff(LED1);
	int i=0;
	int j=0;
	
	while (1)  {
		i = 0;
		while (i < 80000)  {
			i++;
		}
		toggleLED(LED1);

		if (setColor(0x0000FF)) {
    		moveTo((500 + j*50), 400);
    		drawRect(20, 20);
    		j = (j + 1) % 5;
    		setColor(0x00FFFF);
    		moveTo((500 + j*50), 400);
    		drawRect(20, 20);
        }
	}
}
