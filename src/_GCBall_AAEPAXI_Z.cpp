CBall *__thiscall CBall::`scalar deleting destructor'(CBall *this, char a2)
{
  CBall::~CBall(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
