#include "io430.h"
#include "fact_nonr.h"
#include "datatypes.h"
#include "factsum.h"
#include "memcpy_imp.h"
#include <stdio.h>
#include "colours.h"
#include "struct_bits.h"

int main( void )
{
  // Stop watchdog timer to prevent time out reset
  WDTCTL = WDTPW + WDTHOLD;
  /*
  printf("%lu\n", fact_add(1,1,2,2,3,3));
  
  UINT16 x=10;
  
  UINT16 *p1;
  (*p1)++;
  printf("%d",(*p1));
  
  void *p2;
  p2=&x;
  (*(UINT16*)p2)++;
  printf("%d",(*(UINT16*)p2));
  
  BYTE n_in=3;
  UINT32 factValue;
  UINT32 sumValue;
  factsum(n_in, &factValue, &sumValue);
  printf("%lu\n", factValue);
  printf("%lu\n", sumValue);

  UINT32 noBytes_in=5;
  UCHAR src_in=1;
  UCHAR dest_in=2;
  printf("%02x",dest_in);
  memcpy_(&src_in, &dest_in, noBytes_in);
  printf("%02x",dest_in);
  */
  
  processColour(R,10);
  processColour(G,11);
  processColour(B,12);
  processColour(Y,13);
  
  myReg_t myReg;
  myReg.bitValue.bit0=1;
  myReg.bitValue.bit1=1;
  myReg.bitValue.bit2=0;
  myReg.bitValue.bit3=0;
  myReg.bitValue.bit4=0;
  myReg.bitValue.bit5=0;
  myReg.bitValue.bit6=0;
  myReg.bitValue.bit7=0;

  printf("Sizes, struct:%d, union:%d\n", sizeof(myReg), sizeof(bitValue_t)); 
  printf("myReg Bits %d%d%d%d%d%d%d%d\n", myReg.bitValue.bit7,
         myReg.bitValue.bit6, myReg.bitValue.bit5, myReg.bitValue.bit4,
         myReg.bitValue.bit3, myReg.bitValue.bit2, myReg.bitValue.bit1,
         myReg.bitValue.bit0
         );
  
  printf("myReg Byte: %d\n", myReg.byteValue);
  return 0;
}
