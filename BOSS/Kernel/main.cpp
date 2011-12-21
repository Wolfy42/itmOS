#include "Kernel/Kernel.h"
#include "Kernel/ServiceManager/ServiceManager.h"


int main(int argc, char **argv) {

	_disable_interrupts();

	Kernel* kernel = new Kernel();
	ServiceManager* serviceManager = kernel->getServiceManager();

	serviceManager->startServices();

	_enable_interrupts();

	while(1);
}
