//----- (01003C23) --------------------------------------------------------
unsigned int __thiscall CBall::AddRef(CBall *this)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::AddRef", 0);
  v2 = ++*((_DWORD *)this + 34);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
