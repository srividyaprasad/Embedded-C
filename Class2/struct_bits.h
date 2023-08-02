#include "datatypes.h"

typedef  struct {
    UBYTE bit0:1;
    UBYTE bit1:1;
    UBYTE bit2:1;
    UBYTE bit3:1;
    UBYTE bit4:1;
    UBYTE bit5:1;
    UBYTE bit6:1;
    UBYTE bit7:1;
  } bitValue_t;

typedef union {
  BYTE byteValue;
  bitValue_t bitValue;
} myReg_t;
