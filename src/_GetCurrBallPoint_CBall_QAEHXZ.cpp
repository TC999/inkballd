int __thiscall CBall::GetCurrBallPoint(CBall *this)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::GetCurrBallPoint", 0);
  v2 = (*((_DWORD *)this + 31) + *((_DWORD *)this + 32)) % 32;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
