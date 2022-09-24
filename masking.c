#include "masking.h"
#include <assert.h>
#include <stdio.h>

uint32_t mask(uint8_t first, uint8_t last) {
  assert(first > last);
  assert(first < 32);
  assert(last < 32);
  uint32_t o = 0xFFFFFFFF;
  uint32_t a = o << last;
  o >>= (32 - first);
  a &= 0x7FFFFFFF;
  o &= a;
  uint32_t b = 0x00000001 << first;
  assert((o | b) == (o ^ b));
  return o | b;
}

