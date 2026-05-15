//----- (010044EF) --------------------------------------------------------
void __thiscall BallPoints::~BallPoints(void **self)
{
  void *v2; // eax
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "BallPoints::~BallPoints", 0);
  v2 = *self;
  v4 = 0;
  if ( v2 )
  {
    operator delete[](v2);
    *self = 0;
  }
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
