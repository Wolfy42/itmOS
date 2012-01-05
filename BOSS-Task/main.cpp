#include "Service-API/LED/LED.h"

int _main() {

	switchLEDOff(LED1);
	int i=0;
	while (1)  {
		i=0;
		while (i<800000)  {
			i++;
		}
		if (getLEDState(LED2))  {
			switchLEDOff(LED2);
			switchLEDOn(LED1);
		}  else  {
			switchLEDOn(LED2);
			switchLEDOff(LED1);
		}
	}
	return 0;
}
