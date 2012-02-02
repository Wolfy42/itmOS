#include "Semaphore.h"
#include "Task.h"

Semaphore::Semaphore() : _counter(-1) {
    for (int i = 0; i < 20; ++i) {
        _blockedTasks[i] = NULL;
    }
}

Semaphore::~Semaphore() {
}

void Semaphore::wait(Task* task) {
    exit();
    task->status = Blocked;
    bool found = false;
    for (int i = 0; (i < 20) && (!found); ++i) {
        if (_blockedTasks[i] == NULL) {
            _blockedTasks[i] = task;
            found = true;
        }
    }
}

void Semaphore::notifyAll() {
    for (int i = 0; i < 20; ++i) {
        if (_blockedTasks[i] != NULL) {
            Task* task = _blockedTasks[i];
            if (task->status == Blocked) {
                task->status = Ready;
                _blockedTasks[i] = NULL;
                enter(task);
            }
        }
    }
}

bool Semaphore::enter(Task* task) {
    _counter++;
    bool result = true;
    if (_counter > 0) {
        task->status = WaitForSemaphore;
        
        _waitingTasks.push(task);
        result = false;
    }
    return result;
}
void Semaphore::exit() {
    _counter--;
    if (!_waitingTasks.empty()) {
        Task* next = _waitingTasks.front();
        _waitingTasks.pop();
        next->status = Ready;
    }
}
