#include "Semaphore.h"
#include "Task.h"

Semaphore::Semaphore() : _counter(-1) {
}

Semaphore::~Semaphore() {
}

bool Semaphore::enter(Task* task) {
    _counter++;
    bool result = true;
    if (_counter > 0) {
        task->status = Blocked;
        
        _waitingTasks.push(task);
        result = false;
    }
    return result;
}
void Semaphore::exit() {
    _counter--;
    if (_counter > 0) {
        Task* next = _waitingTasks.front();
        _waitingTasks.pop();
        next->status = Ready;
    }
}
