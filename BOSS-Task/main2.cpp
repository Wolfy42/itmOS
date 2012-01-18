#include "Service-API/LED/LED.h"
#include "Service-API/Display/Display.h"

int main() {

	switchLEDOff(LED1);
	int i=0;
	
	while (1)  {
		i = 0;
		while (i < 80000)  {
			i++;
		}
		toggleLED(LED1);
	}
}
