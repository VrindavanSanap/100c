#include <stdio.h>

int main(void) {
#if defined(__STDC_VERSION__)
  printf("Standard Version: %ld\n", __STDC_VERSION__);
#elif defined(__STDC__)
  printf("Standard: C89/C90\n");
#else
  printf("Standard: Pre-standard C (K&R)\n");
#endif

  return 0;
}
