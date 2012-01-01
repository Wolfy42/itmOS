#include "Kernel/Kernel.h"
#include "API/systemCalls.h"

void leerlauf(void)  {
	while(1);
}

int main() {
	_disable_interrupts();

	Kernel* kernel = new Kernel(); 

	// Dummy Task
	Task* leerlaufTask = kernel->getTaskManager()->create("leerlauf\0", false);
	leerlaufTask->codeLocation = (address)((void*)leerlauf);
	leerlaufTask->pageCount = 1;
	
	// Start Services
	kernel->getServiceManager()->startServices();

	// Init
	_enable_interrupts();
	asm("\t CPS 0x10");
	leerlauf();
	
	while(1);
}
