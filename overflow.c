#include "overflow.h"
#include <stdbool.h>

#define MSB_1 0x80000000;

/*
bool will_overflow(int32_t a, int32_t b) {
  if (a < 0 && b < 0) {
    for(int _p = 0; p < 31; p++) {
      a <<= 1;
      b <<= 1;
      
        
      if (((a & MSB_1) & (b & MSB_1)) == MSB_1) {
        return false;
      } else if () {
      
      }
    
    }
  } else if (a > 0 && b > 0) {

  } else {
    assert(false && "unreachable!");
  }
}
*/



int64_t safe_add(int32_t a, int32_t b) {
  int32_t wrapped_sum = a + b;
  if (a > 0 && b > 0) {
    return (int64_t)((uint32_t)wrapped_sum);
  } else if (a < 0 && b < 0) {
    int64_t x = 0xFFFFFFFF00000000;
    x |= (int64_t)((uint32_t)wrapped_sum);
    return x;
  } else {
    return (int64_t)wrapped_sum; 
  }
}
