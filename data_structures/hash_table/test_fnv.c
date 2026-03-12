#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "fnv.h"

typedef struct {
  const char *input;
  uint32_t expected;
} TestCase;

int main() {
  TestCase tests[] = {
      {"", 0x811c9dc5},
      {"a", 0xe40c292c},
      {"abc", 0x1a47e90b},
      {"foobar", 0xbf9cf968},
  };

  int num_tests = sizeof(tests) / sizeof(tests[0]);
  int passed = 0;

  for (int i = 0; i < num_tests; i++) {
    uint32_t result = fnv1a_32(tests[i].input, strlen(tests[i].input));
    if (result == tests[i].expected) {
      printf("✅ PASS: '%s' -> 0x%08x\n", tests[i].input, result);
      passed++;
    } else {
      printf("❌ FAIL: '%s' | Expected: 0x%08x | Got: 0x%08x\n", tests[i].input,
             tests[i].expected, result);
    }
  }

  printf("\nResults: %d/%d passed.\n", passed, num_tests);
  return 0;
}