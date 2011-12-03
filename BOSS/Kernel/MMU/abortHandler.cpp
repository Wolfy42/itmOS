#include "mmu.h"

void handlePageFault() {
    
}
#pragma INTERRUPT (PABT) ;
extern "C" void c_intPABT() {
    MMU::getInstance()->handlePrefetchAbort();
}

#pragma INTERRUPT (DABT) ;
extern "C" void c_intDABT() {
    MMU::getInstance()->handleDataAbort();
}