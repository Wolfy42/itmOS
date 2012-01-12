#include "Semaphore.h"
#include "Task.h"

Semaphore::Semaphore() : _counter(-1), _start(0), _end(0) {
}

Semaphore::~Semaphore() {
}

void Semaphore::push(Task* task) {
    _waitingTasks[_end] = task;
    if (_end + 1 >= MAX_TASKS) {
        _end = 0;
    } else {
        _end++;
    }
}

Task* Semaphore::pull() {
    Task* result = _waitingTasks[_start];
    _waitingTasks[_start] = NULL;
    if (result != NULL) { 
        if (_start + 1 >= MAX_TASKS) {
            _start = 0;
        } else {
            _start++;
        }
    }
    return result;
}

bool Semaphore::enter(Task* task) {
    _counter++;
    bool result = true;
    if (_counter > 0) {
        task->status = Blocked;
        
        // Counter is > 0, so take counter - 1 to start with 0
        push(task);
        result = false;
    }
    return result;
}
void Semaphore::exit() {
    _counter--;
    if ((_start != _end) || (_waitingTasks[_start] != NULL)) {
        Task* next = pull();
        next->status = Ready;
    }
}
