//----- (01008047) --------------------------------------------------------
CInk* __thiscall CInk::scalar_deleting_destructor(CInk *self, char a2)
{
  CInk::~CInk(self);
  if ( (a2 & 1) != 0 )
    operator delete(self);
  return self;
}
