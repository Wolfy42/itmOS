#ifndef TASKS_H_
#define TASKS_H_

#define MAX_TASKS 256

#include "HAL/Timer/HalTimerDriver.h"
#include "API/systemCalls.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef int TID_t;
enum Status { Ready, Running, Blocked };

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
	int stackPointer;
	// entry
	int initAddr;
	// entry
	int returnAddr;
	// already started
	bool hasBeenStarted;
} Task;

// logic variables
extern Task* _tasks[MAX_TASKS];
extern int activeTask;


// create Task
TID_t createTask(char* name, int priority, int initAddress);

// delete Task
void deleteTask(TID_t taskId);

// Scheduler - get next Task to Run
void scheduleNextTask();

// init Task Array with NULL
void initTasks();

// returns the next free task id
int getNextTaskId();

void exitTask();




//
//#pragma TASK
//#pragma INTERRUPT (IRQ)
//extern "C"  void c_intIRQ() {
//
//	// Determine Nr. of IRQ (e.g. GPTIMER2 is IRQ_38 --> irqNr = 38)
//	int irqNr = *(INTCPS_SIR_IRQ);
//
//
//
//
//
///***************** end schedule *****************/
//
//	// Reset IRQ output and enable new IRQ generation.
//	*(INTCPS_CONTROL) |= 0x1;
//}



















//
//// Interrupt Handler
////#pragma TASK
////#pragma INTERRUPT (SWI) ;
//void scheduleInterrupt()  {
//	
//	// TODO HANDLE INTERRUPT
//	// TODO when starting a new process, what's the return register?
//
//	// we are now in the supervisor mode 0x13
//	// we must save the return address of the supervisor mode
//	// (lr) to return to the user process
//
//	// then we save all registers on the process stack
//	// then we schedule the next process
//
//	// if the scheduled process hasn't been started yet
//	// 		start the process
//	// otherwise
//	//		restore the context of the process (registers)
//
//	// the stack frame looks like this:
//	// TOP OF STACK 		return address
//	// TOP OF STACK -1		cpsr
//	// IN BETWEEN			r0 - r11
//	// BOTTOM OF STACK		r12
//	
//	// store the return address
//	asm("\t PUSH {r0} \n" \
//		"\t LDR r0, return_address \n" \
//		"\t STR lr, [r0] \n" \
//		"\t POP {r0} \n");
//
//	// to save the process context we can switch in the system
//	// mode, because system mode has the same stack
//	asm("\t CPS 0x1F");
//	
//	if(activeTask != -1) {
//	
//		// now save all registers inclusive CPSR
//		asm("\t STMFD sp!, {r0-r12} \n" \
//			"\t MRS r5, cpsr \n" \
//			"\t STMFD sp!, {r5}");
//	
//		// save the new return address
//		asm("\t LDR r0, return_address \n" \
//			"\t LDR r0, [r0] \n" \
//			"\t STMFD sp!, {r0}");
//	
//		// the new stack pointer of the process has to be saved
//		// to restore the process
//		asm("\t LDR r0, stack_pointer_interrupted \n" \
//			"\t STR sp, [r0]");
//	
//		// the register r0 to r12 and the cpsr plus the new return address
//		// are now on the process stack
//		
//		// load the context of the task manager
//		// TODO load the cpsr register?
//		asm("\t LDR sp, stack_pointer_task_manager \n" \
//			"\t LDR sp, [sp] \n" \
//			"\t LDMFD sp!, {r0-r12}");
//
//		// save the new stack pointer of the interrupted task
//		_tasks[activeTask]->stackPointer = stack_pointer_interrupted;
//	}
//	
//	// schedule next task
//	scheduleNextTask();
//
//	// check if the task has been started
//	if(_tasks[activeTask]->hasBeenStarted == false) {
//		_tasks[activeTask]->hasBeenStarted = true;
//		
//		// the process hasn't been started yet
//		// we have to start the process in the user mode
//		// therefore we can't just call the function pointer
//		// and we have to leave the interrupt handler correctly
//		// (either with return or with the LDMFD assembler instruction
//
//		// to start the process we simply set the return address
//		// of the handler to the process start (function pointer address)
//
//		function_pointer = _tasks[activeTask]->initAddr;
//
//		// the new process has its own stack and we have to set
//		// the stack pointer of it
//		stack_pointer_interrupted = _tasks[activeTask]->stackPointer;
//		
//		// set return address to exit point of tasks
//		return_address = (int)exitTask;
//		
//		// TODO set the return address to a done function
//		asm("\t LDR lr, return_address \n" \
//			"\t LDR lr, [lr]");
//		
//		// save taskmanager context
//		asm("\t STMFD sp!, {r0-r12} \n" \
//			"\t LDR r0, stack_pointer_task_manager \n" \
//			"\t STR sp, [r0, #0]");
//		
//		
//		// switch to task stack
//		asm("\t LDR sp, stack_pointer_interrupted \n" \
//			"\t LDR sp, [sp]");
//
//		// switch back to the interrupt handler
//		asm("\t CPS 0x13");
//
//		// set the new return address
//		asm("\t LDR lr, function_pointer \n" \
//			"\t LDR lr, [lr]");
//
//	} else {
//
//		// restore the context of the next process
//		// to restore the context we have to switch to the
//		// process stack
//		// therefore we set the stack pointer of the process
//		stack_pointer_restored = _tasks[activeTask]->stackPointer;
//		
//		
//		// save taskmanager context
//		asm("\t STMFD sp!, {r0-r12} \n" \
//			"\t LDR r0, stack_pointer_task_manager \n" \
//			"\t STR sp, [r0, #0]");
//		
//		
//		// switch to task stack
//		asm("\t LDR sp, stack_pointer_restored \n" \
//			"\t LDR sp, [sp]");
//
//		// the return address is at the top of the stack so we need
//		// to read it first
//		asm("\t LDR r0, function_pointer \n" \
//			"\t LDR r1, [sp, #0] \n" \
//			"\t STR r1, [r0, #0] \n" \
//			// move stack pointer to the register r0-r12
//			"\t ADD sp, sp, #4");
//
//		// now read the cpsr register
//		asm("\t LDMFD sp!, {r0} \n" \
//			"\t MSR SPSR_cxsf, r0");
//
//		// now read the registers r0-r12
//		asm("\t LDMFD sp!, {r0-r12}");
//
//		// switch back to the interrupt handler
//		asm("\t CPS 0x13");
//
//		// set the new return address
//		asm("\t LDR lr, function_pointer \n" \
//			"\t LDR lr, [lr]");
//	}
//	
//	
//}


#endif /*TASKS_H_*/
