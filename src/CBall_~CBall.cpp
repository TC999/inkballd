//----- (01004B72) --------------------------------------------------------
void __thiscall CBall::~CBall(CBall *this)
{
  void **v2; // ecx
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  *(_DWORD *)this = &CBall::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBall::~CBall", 0);
  v2 = (void **)*((_DWORD *)this + 30);
  v4 = 0;
  if ( v2 )
  {
    BallPoints::`scalar deleting destructor'(v2, 1);
    *((_DWORD *)this + 30) = 0;
  }
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
