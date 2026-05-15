//----- (010046E1) --------------------------------------------------------
#include "global_types.h"

extern void BallPoints_dtor(BallPoints* self);

void* BallPoints_scalar_deleting_destructor(BallPoints *self, char a2)
{
  BallPoints_dtor(self);
  if ( (a2 & 1) != 0 )
    operator delete(self);
  return self;
}
