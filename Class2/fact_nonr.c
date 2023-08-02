#include "datatypes.h"
#include "fact_nonr.h"

UINT32 fact_nonr(UBYTE n_in)
{
  static int fact = 1; //
  for(int i=2; i<=n_in; i++)
    fact *= i;
  return fact;
}

UINT32 fact_add(UBYTE a_in, UBYTE b_in, UBYTE c_in, UBYTE d_in, UBYTE e_in, UBYTE f_in)
{
  return (fact_nonr(a_in)+fact_nonr(b_in)+fact_nonr(c_in)+fact_nonr(d_in)+fact_nonr(e_in)+fact_nonr(f_in));
}

