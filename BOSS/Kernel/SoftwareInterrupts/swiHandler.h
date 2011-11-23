
#ifndef SWIHANDLER_H_
#define SWIHANDLER_H_

#include "API/dataTypes.h"
#include "Lib/bitOperations.h"
#include "BOSSAPI/systemCalls.h"
#include "Service/Service.h"
#include "Kernel/MMU/mmu.h"
#include "Kernel/TaskManagement/Tasks.h"
#include "Kernel/Kernel.h"

	void swi_setKernel(void* kernel);

#endif /* SWIHANDLER_H_ */
