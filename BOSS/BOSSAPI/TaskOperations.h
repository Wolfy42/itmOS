#ifndef TASKOPERATIONS_H_
#define TASKOPERATIONS_H_

//TODO: The User will not call yield. He will call newTask(...)
//TODO: wenn newTask immer taskwechsel macht -> viel spass beim 100 tasks spawnen o_O
void yield();
void exit(int state);
void kill(int pid);
int fork();

#endif /*TASKOPERATIONS_H_*/
