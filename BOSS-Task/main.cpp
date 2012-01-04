#include "Service-API/LED/LED.h"

int main() {

	switchLEDOff(LED1);
	int i=0;
	while (1)  {
		i=0;
		while (i<80000)  {
			i++;
		}
		toggleLED(LED2);
	}
	return 0;
}
