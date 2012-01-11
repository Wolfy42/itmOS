#include "Service-API/LED/LED.h"

int _main() {

	switchLEDOff(LED1);
	int i=0;
	while (1)  {
		i=0;
		while (i<800000)  {
			i++;
		}
		toggleLED(LED2);
	}
	return 0;
}
