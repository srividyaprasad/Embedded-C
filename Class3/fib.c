#include "fib.h"
#include <stdio.h>
#include "datatypes.h"
#define FIRSTVAL 0
#define SECONDVAL 1

UINT32 fib(UINT32 n)
{
  UINT32 i;
  UINT32 a=FIRSTVAL;
  UINT32 b=SECONDVAL;
  UINT32 temp;
  UINT32 retval;
  #ifdef _DEBUG
  printf("fib(%lu) entered\n",n);
  #endif
  if(n==1)
    retval=a;
  else if(n==2)
    retval=b;
  else
  {
  for(i=3;i<=n;i++)
  {
    temp=b;
    b=a+b;
    a=temp;
  }
  retval=b;
  }
  #ifdef _DEBUG
    printf("fib returned %d\n",retval);
  #endif
  return retval;
}