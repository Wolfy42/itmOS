#include "TestTask.h"

void userTask_main(void) {
	TestTask task;
	task.start();
}

TestTask::TestTask() : UserModeTask()  {}

TestTask::~TestTask()  {}

MessageQueue* TestTask::getQueue()  {
	return *(MessageQueue**)0x82100000;
}

void TestTask::start()  {
	while(1)  {
		toggleLED(LED1);
		for (int z = 0; z < 80000;) {
			z++;
		}
		toggleLED(LED2);
		for (int z = 0; z < 80000;) {
			z++;
		}
	}
}

void TestTask::executeMessage(Message* message)  {


}
