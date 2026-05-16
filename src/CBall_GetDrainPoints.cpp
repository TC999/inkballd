//----- (01003DC7) --------------------------------------------------------
int *__thiscall CBall::GetDrainPoints(CBall *this)
{
  int *v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::GetDrainPoints", 0);
  v2 = (&DrainPoints)[*((_DWORD *)this + 11)];
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
