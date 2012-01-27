#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#include "TaskManager.h"
#include <queue>

class Semaphore {
    private:
        std::queue<Task*> _waitingTasks;
        int _counter;
        
    public:
    	Semaphore();
    	virtual ~Semaphore();
        
        bool enter(Task* task);
        void exit();
};

#endif /*SEMAPHORE_H_*/
