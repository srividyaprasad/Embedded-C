#include "datatypes.h"

// Design and Develop a function factsum that can take input n_in and return two values 
// a) factorial of n_in and b) sum: 1+2+3...n_in. Use pointers as parameters to return multiple values to caller.

// Test the function from main() with different parameter values.

UINT32 fact = 1, sum = 0; 
void factsum(BYTE n_in, UINT32 *factptr, UINT32 *sumptr)
{
  
  for(BYTE i=1; i<=n_in; i++)
  {
    fact *= i;
    sum +=i;
  }
  *factptr = fact;
  *sumptr = sum; 
}