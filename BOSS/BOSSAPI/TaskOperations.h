#ifndef TASKOPERATIONS_H_
#define TASKOPERATIONS_H_

void yield();
void exit(int state);
void kill(int pid);
int fork();

#endif /*TASKOPERATIONS_H_*/
