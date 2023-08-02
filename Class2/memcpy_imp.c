#include "datatypes.h"
#include "memcpy_imp.h"

enum BOOL{FAILURE, SUCCESS};
UCHAR *src_array;
UCHAR *dest_array;
BOOL memcpy_(UCHAR *src_in, UCHAR *dest_in, UINT32 noBytes_in)
{
  if (src_location == NULL || dst_location == NULL || noOfBytes <= 0)
        return FALSE; // Invalid parameters
  for(BYTE i=1;i<=noBytes_in; i++)
  {  
    *dest_in = *src_in;
    src_in++;
    dest_in++;
   }
  return TRUE;
}