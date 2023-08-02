#include "fibprod.h"
int fibprod(int a, int b)
{
  int fa=fib(a);
  int fb=fib(b);
  return fa*fb;
}