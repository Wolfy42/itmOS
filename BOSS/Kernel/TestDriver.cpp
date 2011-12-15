#include <stdio.h>
#include <string.h>

#include "HAL/Timer/HalTimerDriver.h"
#include "Kernel/Task/TaskManager.h"
#include "Kernel/Interrupt/Handler/IRQHandler.h"
#include "Kernel/Interrupt/Handler/SWIHandler.h"
#include "Kernel/SystemCalls/SystemCallExec.h"

#include "Apps/Shell/Shell.h"

#include "Lib/Rand.h"
#include "Lib/Time.h"

#include "Apps/Shell/Shell.h"

#include "Kernel/Kernel.h"

#include "API/serviceCalls.h"

#include "OMAP-Lib/OMAP/McBSP2.h"

#include "Kernel/Task/Task.h"
#include "MMU/mmu.h"

#include "Loader/Loader.h"
#include "Messaging/MemoryManager/MemoryManager.h"
#include "Messaging/MessageQueue/MessageQueue.h"
#include "Messaging/Message/Message.h"

Kernel* kernel;

void ledOff(void) {
//	HalLedDriver driver;
//	driver.ledOff(LED1);
//	driver.ledOff(LED2);
}

void initScheduler(IRQHandler* hand) {
	srand_(time_());
	hand->registerHandler(HalTimerDriver::irqNumberForTimer(GPTIMER2), ledOff);

	HalTimerDriver::init(GPTIMER2, GPT_IRQMODE_OVERFLOW, 100);
	HalTimerDriver::start(GPTIMER2);

}

void dummy(IRQHandler* hand)  {
	initScheduler(hand);
	_enable_interrupts();
	asm("\t CPS 0x10");
	while(1);
}

void task1function() {
	int i = 0;
	for (i = 0; i < 10000; i++) {
//		HalLedDriver driver;
//		driver.toggle(LED1);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}
}

void task2function() {
	int i = 0;
	for (i = 0; i < 100; i++) {
//		HalLedDriver driver;
//		driver.toggle(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}	
}

void shellstart() {
	shell(kernel->getTaskManager());
}

void init_kernel() {
	kernel = new Kernel();
}

void audio_test() {
	McBSP2* mcbsp2 = new McBSP2();
	mcbsp2->init_mcbsp2();
}

void shell_test() {
	TaskManager* taskmanager = kernel->getTaskManager();
	taskmanager->create("shell\0", 100, (int)shellstart, false);
}

void tasks_test() {
	TaskManager* taskmanager = kernel->getTaskManager();
	
	// Register and start LED Service
	kernel->startService(LED_SERVICE);

	taskmanager->create("dummy\0", 0, (int)dummy, false);
	taskmanager->create("led 1\0", 70, (int)task1function, false);
	taskmanager->create("led 2\0", 30, (int)task2function, false);
	
	// Start User-Test-Task
//	taskmanager->create("User-Test-Task\0", 100, (int)userTask_main, false);
	
	// Shell-Tests
	shell_test();
	
	dummy(kernel->getHandlerManager()->getIrqHandler());
}

int main() {

	int a[2];
	a[0] = 1;
	a[1] = 2;

	address addr = (address)0x81000000;
	MemoryManager* mm = MemoryManager::getInstanceAt(addr);
	MessageQueue* mq = mm->getMessageQueue();
	Message* m1 = mm->createMessage(1, 2, a);
	Message* m2 = mm->createMessage(1, 2, a);

	mm->remove(m1);
	Message* m3 = mm->createMessage(1, 2, a);

	// Init the kernel
	init_kernel();
	
	// Stefans Audio-Tests
	//audio_test();

	// Task-Tests
	//tasks_test();

	while(1) {
		for (int z = 0; z < 80000;) {
			z++;
		}
	}
	//return 0;
}
