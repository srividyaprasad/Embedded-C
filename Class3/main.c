#include "fib.h"
#include "fibprod.h"

#include <stdio.h>
#include "io430.h"

#define AND &&
#define OR ||

#define _DEBUG 1
#define INIT_VALUE 0
//can have many levels: _DEBUG_l1, _DEBUG_L2

int main(void)
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  
  //CLASS 1
  
  /*
  printf("Printing numbers from 0 to 250:");
  for(int i=0; i<=250; i++)
  {
    printf("%d\n",i);
  }
  */
  /*
  printf("Printing 10th fibonacci number:\n");
  printf("%d\n",fib(10));
  for (int i=1;i<=10;i++)
  {
    printf("%d\n",fib(i));
  }
  */
  /*
  int x=0xF0; //11110000 in hexa
  int y=0x0F; //00001111 in hexa
  if(x&y) //00000000
    printf("BITWISE not= 0\n");
  else
    printf("BITWISE = 0\n");
  if(x AND y) //true&&true = true
    printf("LOGIC not= 0\n");
  else
    printf("LOGIC = 0\n");
   */
  
  //CLASS 2
  //Including header libraries best practice
  printf("%d\n",fib(5));
  printf("%d\n",fibprod(5,3));
  char c;
  enum 
  {
    OFF,ON
  }test1;
  
  printf("Size: %d %d %d\n",sizeof(unsigned long int), sizeof(c), sizeof(test1));
  
  typedef unsigned short int USHORT;
  typedef signed short int SHORT;
  
  typedef struct
  {
    char name[10];
    char srn[12];
  }studentrecord;
  
  //Write an equivalent while loop and do-while loop for the below code snippet:
  for (int i=INIT_VALUE; i<50;i++)
    printf("i=%d\n",i);
  
  int i=INIT_VALUE;
  while(i<50)
  {
    printf("i=%d\n",i);
    i++;
  }
  
  i=INIT_VALUE;
  do
  {
    printf("i=%d\n",i);
    i++;
  }while(i<50);
   
   return 0;
}  
