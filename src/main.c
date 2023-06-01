#include <stdio.h>

#include <constants.h>

#include <shared.h>
#include <static.h>
#include <custom.h>
#include <point.h>

#if !defined(TEST_DEFINE)
#define TEST_DEFINE 0
#endif /* TEST_DEFINE */

int
main(void)
{
  point_t p = {0.75f, 0.25f};
  point_print(&p);
  printf("static(): %f\n", lib_static());
  printf("shared(): %f\n", shared());
  printf("custom(): %f\n", custom());
  printf("MODERN_MAGIC_CONSTANT: %d\n", MODERN_MAGIC_CONSTANT);
  printf("TEST_DEFINE: %d\n", TEST_DEFINE);
  return 0;
}
