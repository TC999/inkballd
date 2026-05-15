//----- (010046E1) --------------------------------------------------------
void **__thiscall BallPoints::`scalar deleting destructor'(void **this, char a2)
{
  BallPoints::~BallPoints(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
