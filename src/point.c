#include <point.h>

#include <stdio.h>

void
point_print(point_t* p)
{
  printf("{%.03f, %.03f}\n", p->x, p->y);
}
