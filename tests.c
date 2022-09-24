#include "masking.h"
#include <assert.h>
#include <stdio.h>

void masking_test() {
    assert(mask(31, 0) == 0xFFFFFFFF);
    assert(mask( 7, 0) == 0x000000FF);
    assert(mask(15, 8) == 0x0000FF00);
}

int main(void) {
  printf("Testing...\n");
  masking_test();
  printf("Tests passed.\n");
  return 0;
}
