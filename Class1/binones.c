#include "binones.h"
int calcbinones(signed long int a)
{
  int temp, rem, count=0;
  temp=a;
  while(temp!=0)
  {
  rem=temp%2;
  if(rem==1)
    count++;
  temp=temp/2;
  }
  return count;
}