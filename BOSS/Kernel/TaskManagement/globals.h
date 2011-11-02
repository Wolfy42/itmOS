#ifndef GLOBALS_H_
#define GLOBALS_H_

// load and save registers
#define SAVEREG 	asm ("\t push {r0,r1,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15}");
#define LOADREG		asm ("\t pop {r0,r1,r3,r4,r5,r6,r7,r8,r9,r10,r11,r12,r13,r14,r15}");

// maximum number of tasks
#define MAX_TASKS 256

// save stackPointer of a task
extern int stackPointer;
asm("\t .bss _stackPointer, 4");
asm("\t .global _stackPointer");
asm("stackPointer_a .field 32");

#endif /*GLOBALS_H_*/
