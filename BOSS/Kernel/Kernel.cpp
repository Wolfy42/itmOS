
#include "Kernel.h"

Kernel::Kernel() {

	LEDService ledService;
	registerService(&ledService);
}

Kernel::~Kernel() {
}

void Kernel::registerService(Service* service)  {


}
