//----- (010046E1) --------------------------------------------------------
void** __thiscall BallPoints::scalar_deleting_destructor(void **self, char a2)
{
  BallPoints::~BallPoints(self);
  if ( (a2 & 1) != 0 )
    operator delete(self);
  return self;
}
