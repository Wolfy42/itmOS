#include "Kernel/Kernel.h"
#include "Kernel/ServiceManager/ServiceManager.h"
#include "HAL/Audio/OMAP/McBSP2.h"
#include "HAL/Audio/TPS65950/TPS65950.h"
#include "HAL/I2C/I2C.h"
#include "API/systemCalls.h"

void leerlauf(void)  {
	while(1);
}

int main() {
	_disable_interrupts();

	// Audio Test -> don't touch this -> "i kill you!"
	McBSP2* mcbsp2 = new McBSP2();
	mcbsp2->init_mcbsp2();

	TPS65950* tps = new TPS65950();
	tps->init_tps65950();




//	Kernel* kernel = new Kernel();
//	ServiceManager* serviceManager = kernel->getServiceManager();
//
//
//	// Dummy Task
//	Task* leerlaufTask = kernel->getTaskManager()->create("leerlauf\0", false);
//	leerlaufTask->codeLocation = (address)((void*)leerlauf);
//	leerlaufTask->pageCount = 1;
//
//	// Start Services
//	kernel->getServiceManager()->startServices();
//
//	// Init
//	_enable_interrupts();
//	asm("\t CPS 0x10");
//	leerlauf();
//
//	while(1);
}
