#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

#include <list>
#include "Task/Task.h"
#include "Scheduler/Scheduler.h"

#define SAVEREG 	asm ("\t push {r0,r1,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15}");
#define LOADREG		asm ("\t pop {r0,r1,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15}");

using namespace std;



extern "C" {
	
	//#pragma SWI_ALIAS(48);
	void swift ();
	
}
extern int registers[16];
extern int return_register;
extern int stack_pointer;



class TaskManager {
public:




	TaskManager();
	virtual ~TaskManager();
	
	// create a new Task
	TID_t createTask(void(*function)(void));
	
	// deletes an existing Task
	int deleteTask(TID_t id);
	
	// schedules the next task
	int scheduleTask();
	
	// getter/setter
	list<Task*> getTasks() const { return _tasks; }
	
	Scheduler* getScheduler() const { return _scheduler; }
	void setScheduler(Scheduler* scheduler) { _scheduler = scheduler; }
	
	Task* getActiveTask() const { return _activeTask; }
	void setActiveTask(Task* activeTask) { _activeTask = activeTask; }
	
private:
	// list of all tasks waiting to be executed
	list<Task*> _tasks;
	
	// Scheduler for deciding, which task is the CHOSEN ONE
	Scheduler* _scheduler;
	
	// this is the active Task - we need to save for later reuse
	Task* _activeTask;
};

#endif /*TASKMANAGER_H_*/
