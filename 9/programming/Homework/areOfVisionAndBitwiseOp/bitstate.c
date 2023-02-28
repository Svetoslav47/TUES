#include <stdio.h>

static int bitstate = 0;

void setBit(int bit) {
    if (0 > bit || 31 < bit) {
        return;
    }

    bitstate |= (1 << bit);
}

void unsetBit(int bit) {
    if (0 > bit || 31 < bit) {
        return;
    }

    bitstate &= ~(1 << bit);
}

void toggleBit(int bit) {
    if (0 > bit || 31 < bit) {
        return;
    }

    bitstate ^= (1 << bit);
}

int isBitSet(int bit) {
    if (0 > bit || 31 < bit) {
        return -1;
    }

    return bitstate & (1 << bit) ? 1 : 0;
}

int getBitState() {
    return bitstate;
}

void test() {
    int a = 0;
}