#include<stdio.h>
#include "io430.h"
#include "binones.h"
#include "fun10add4.h"
#include "f1.h"
int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  /*
  unsigned short int number = 5;
  while(1)
  {
    int acc =1;
    for(;number>0;acc*=number--);
    printf("%d",acc);

  }
  */
  /*
  printf("%d",calcbinones(3));
  */
  
  //Develop a function that initialises variable with 10. Every time the function is called it will return a value of +4 to the previous value.
  for(int i=0;i<10;i++)
  {
    printf("%d\n",fun10add4());
  }
  f1();
  
  return 0;
}
