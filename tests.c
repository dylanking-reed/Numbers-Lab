#include "masking.h"
#include "negation.h"
#include "overflow.h"
#include <assert.h>
#include <stdio.h>
#include <stdint.h>

void masking_test() {
  printf("Running test: masking_test ... ");
  assert(mask(31, 0) == 0xFFFFFFFF);
  assert(mask( 7, 0) == 0x000000FF);
  assert(mask(15, 8) == 0x0000FF00);
  printf("PASSED\n");
}

void negation_test() {
  printf("Running test: negation_test ... ");
  assert(negate(10) == -10);
  assert(negate(-1) == 1);  
  assert(negate(1) == -1);  
  printf("PASSED\n");
}

void overflow_test() {
  printf("Running test: overflow_test ... ");
  assert(safe_add(INT32_MAX, 1) == (int64_t)INT32_MAX + (int64_t)1);
  assert(safe_add(INT32_MIN, -1) == (int64_t)INT32_MIN + (int64_t)-1);
  assert(safe_add(INT32_MAX, 400) == (int64_t)INT32_MAX + (int64_t)400);
  assert(safe_add(INT32_MIN, -400) == (int64_t)INT32_MIN + (int64_t)-400);
  printf("PASSED\n");
}	

int main(void) {
  printf("Testing...\n");
  masking_test();
  negation_test();
  overflow_test();
  printf("Tests passed.\n");
  return 0;
}
