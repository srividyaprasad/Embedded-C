#include "fun10add4.h"
#include "datatypes.h"

#define INIT_VALUE 10
#define INC_VALUE 4

UINT16 fun10add4()
{
    static UINT16 val;
    if(val==0)
      val=INIT_VALUE;
    else
      val+=INC_VALUE;
    return val;
}