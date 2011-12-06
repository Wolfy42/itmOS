#ifndef TASKMANAGER_H_
#define TASKMANAGER_H_

/*
 * Change if you wanna hav mor fun (tasks)
 */
#define MAX_TASKS 256

/*
 *	Typedefs for TaskManagement
 */
typedef int TID_t;
enum Status { Ready, Running, Blocked }; 

/*
 *	This struct is a solid Task - everyone is solid @ Task Library
 * 	- Task: Task itself
 * 	- TCB: Task Control Block
 */
struct TCB {
	
	// all registers
	int CPSR;
	int restartAddress;
	int R0;
	int R1;
	int R2;
	int R3;
	int R4;
	int R5;
	int R6;
	int R7;
	int R8;
	int R9;
	int R10;
	int R11;
	int R12;
	int R13;
	int R14;
};

typedef struct {
	
	// id of task
	TID_t id;
	// name of task
	char* name;
	// status of task
	Status status;
	// priority of task (from 0 to 20 -> higher = more important)
	int priority;
	// registers
	TCB tcb;

} Task;




/*
 * 	TaskManager Class
 */
class TaskManager {
private:
	Task* _tasks[MAX_TASKS];
	int _activeTask;
	
	int getNextFreeSlot();

public:
	TaskManager();
	virtual ~TaskManager();

	// get a Task Struct/Object by TaskID (TID_t)
	Task* getTaskFor(int taskId);
	
	// create a new Task
	TID_t create(char* name, int priority, int initAddress);
	
	// delete a Task by TaskID (TID_t)
	void kill(int taskId);
	
	// schedule next Task
	// this means that a method call of schedule changes the _activeTask member
	void schedule();
	
	// get active Task
	Task* getActiveTask();
	
	// get list of all Tasks
	Task** getTaskList();
};

#endif /* TASKMANAGER_H_ */
