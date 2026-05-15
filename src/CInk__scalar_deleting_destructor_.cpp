//----- (01008047) --------------------------------------------------------
#include "global_types.h"
#include <cstdint>

extern void CInk_Cleanup(CInk* self);

void* CInk_scalar_deleting_destructor(CInk *self, char a2)
{
  CInk_Cleanup(self);
  if ( (a2 & 1) != 0 )
    operator delete(self);
  return self;
}
