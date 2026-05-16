//----- (01004BE8) --------------------------------------------------------
int __thiscall CBall::Release(CBall *this)
{
  bool v2; // zf
  int v3; // edi
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::Release", 0);
  v6 = 0;
  v2 = (*((_DWORD *)this + 34))-- == 1;
  v3 = *((_DWORD *)this + 34);
  if ( v2 )
    CBall::`scalar deleting destructor'(this, 1);
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v3;
}
