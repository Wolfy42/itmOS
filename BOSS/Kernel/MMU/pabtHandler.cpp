#include "mmu.h"

void handlePageFault() {
    MMU::getInstance()->handlePageFault();
}
#pragma INTERRUPT (PABT) ;
extern "C" void c_intPABT() {
    _disable_interrupts();
    handlePageFault();
    _enable_interrupts();
}

