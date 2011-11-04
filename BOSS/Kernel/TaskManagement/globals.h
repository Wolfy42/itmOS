#ifndef GLOBALS_H_
#define GLOBALS_H_

// load and save registers
#define SAVEREG 	asm ("\t push {r0,r1,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r14}")
#define LOADREG		asm ("\t pop {r0,r1,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r14}")

// maximum number of tasks
#define MAX_TASKS 256

// save stackPointer of a task
extern int registers[16];
extern int kernelRegisters[16];
extern int returnAddress;
extern int hasStarted;

#endif /*GLOBALS_H_*/
