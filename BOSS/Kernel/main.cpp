#include "Kernel/Kernel.h"
#include "API/LED.h"

int _main(int argc, char **argv) {

	//TODO: Start in Kernel-Mode

	Kernel kernel;

	switchLEDOff(LED1);

	return 0;
}
