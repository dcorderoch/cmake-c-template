#include <stdio.h>

#include <constants.h>

#include <shared.h>
#include <static.h>

#if !defined(TEST_DEFINE)
#define TEST_DEFINE 0
#endif /* TEST_DEFINE */

int
main(void)
{
  printf("static(): %f\n", lib_static());
  printf("shared(): %f\n", shared());
  printf("MODERN_MAGIC_CONSTANT: %d\n", MODERN_MAGIC_CONSTANT);
  printf("TEST_DEFINE: %d\n", TEST_DEFINE);
  return 0;
}
