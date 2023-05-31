#include <stdio.h>

#include <constants.h>

#include <mylib.h>

int
main(void)
{
  printf("Hello, World!\n");
  printf("mylib(): %f\n", mylib());
  printf("MODERN_MAGIC_CONSTANT: %d\n", MODERN_MAGIC_CONSTANT);
  return 0;
}
