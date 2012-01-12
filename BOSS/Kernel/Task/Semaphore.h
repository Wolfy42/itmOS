#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#include "TaskManager.h"

class Semaphore {
    private:
        Task* _waitingTasks[MAX_TASKS];
        int _counter;
        int _start;
        int _end;
        
        void push(Task* task);
        Task* pull();
    public:
    	Semaphore();
    	virtual ~Semaphore();
        
        bool enter(Task* task);
        void exit();
};

#endif /*SEMAPHORE_H_*/
