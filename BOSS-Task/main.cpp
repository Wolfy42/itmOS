#include "Service-API/LED/LED.h"
#include "HAL/LED/HalLedDriver.h"

int main() {

	HalLedDriver dr;
	dr.ledOff(LED1);

	return 0;
}
