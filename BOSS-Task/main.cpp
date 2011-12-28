#include "Service-API/LED/LED.h"
#include "HAL/LED/HalLedDriver.h"

int _main() {

	HalLedDriver dr;
	dr.ledOff(LED2);
	int i=0;
	while (1)  {
		i=0;
		while (i<80000)  {
			i++;
		}
		dr.toggle(LED1);
	}
	return 0;
}
