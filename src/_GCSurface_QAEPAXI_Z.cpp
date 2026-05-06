CSurface *__thiscall CSurface::`scalar deleting destructor'(CSurface *this, char a2)
{
  CSurface::~CSurface(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
