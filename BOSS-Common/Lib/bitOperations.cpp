#include "bitOperations.h"

void setBit(address number, int bitOffset) {
    *(number) |= (1 << bitOffset);
}

void unsetBit(address number, int bitOffset) {
    *(number) &= ~(1 << bitOffset);
}

void toggleBit(address number, int bitOffset) {
    *(number) ^= (1 << bitOffset);
}

bool readBit(address number, int bitOffset) {
    return (*(number) & (1 << bitOffset));
}

void reg32w(address base, address reg, int value) {

}
