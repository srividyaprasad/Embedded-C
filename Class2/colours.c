#include "datatypes.h"
#include "colours.h"
#include <stdio.h>
void processR(UINT16 colourValue_in)
{
printf("Process R: %hd\n",colourValue_in);
}
void processG(UINT16 colourValue_in)
{
printf("Process G: %hd\n",colourValue_in);
}
void processB(UINT16 colourValue_in)
{
printf("Process B: %hd\n",colourValue_in);
}
void processY(UINT16 colourValue_in)
{
printf("Process Y: %hd\n",colourValue_in);
}
void(*func_ptr[4])(UINT16 colourValue_in) = {processR, processG, processB, processY};
void processColour(eColour colour_in, UINT16 colourValue)
{
  func_ptr[colour_in](colourValue);
}