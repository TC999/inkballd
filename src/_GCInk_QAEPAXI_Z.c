CInk *__thiscall CInk::`scalar deleting destructor'(CInk *this, char a2)
{
  CInk::~CInk(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
