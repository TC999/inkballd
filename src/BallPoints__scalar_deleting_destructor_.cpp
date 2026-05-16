//----- (010046E1) --------------------------------------------------------
#include "global_types.h"

extern void BallPoints_dtor(BallPoints* self);

void BallPoints::scalar_deleting_destructor(BallPoints* self, int flags)
{
  BallPoints_dtor(self);
  if ( (flags & 1) != 0 )
    operator delete(self);
}
