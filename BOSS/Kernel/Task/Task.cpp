#include "Task.h"

Task::Task(): messageQueueAddress((address)0x0), masterTableAddress((address)0x0),
              id(0), name((char*)0x0), status(Ready), priority(0), tcb(),
              parent((Task*)0x0), child((Task*)0x0) {

}

Task::~Task() {
}
