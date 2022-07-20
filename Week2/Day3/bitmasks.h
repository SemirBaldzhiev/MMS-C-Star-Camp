#ifndef __BITMASKS_H__
#define __BITMASKS_H__

#include <stdint.h>

void setBit(uint32_t *mask, int bit);
void clearBit(uint32_t *mask, int bit);
int checkBit(uint32_t *mask, int bit);
void flipBit(uint32_t *mask, int bit);

#endif