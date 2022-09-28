#include "rounding.h"
#include "masking.h"
#include <assert.h>
#include <stdio.h>


uint32_t nearest_even(uint32_t val, uint8_t place) { 
  uint32_t to_remove = mask((uint32_t)place - 1, 0);
  uint32_t to_keep = mask(31, (uint32_t)place + 1);
  uint32_t lower = val & to_remove;
  printf("lower: %d\n", lower);
  uint32_t lower_midpoint = (uint32_t)(1 << place);
  printf("lower_midpoint: %d\n", lower_midpoint);
  if (lower > lower_midpoint) {
    printf(" branch a \n");
    return (val & to_keep) + (1 << place); 
  } else if (lower < lower_midpoint) {
    printf(" branch b \n");
    return (val & to_keep) | (1 << (place + 1));
  } else if (lower == lower_midpoint) {
    printf(" branch c \n");
    if (((val & to_keep) % 2) == 0) {
      return val & to_keep; 
    } else { 
      return (val & to_keep) - 1; 
    }
  }

  assert(0 && "unreachable!"); 
  return -1;
}
