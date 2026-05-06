CDisplay *__thiscall CDisplay::`scalar deleting destructor'(CDisplay *this, char a2)
{
  CDisplay::~CDisplay(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
