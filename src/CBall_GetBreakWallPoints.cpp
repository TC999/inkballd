//----- (01003DFC) --------------------------------------------------------
int *__thiscall CBall::GetBreakWallPoints(CBall *this)
{
  int *v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::GetBreakWallPoints", 0);
  v2 = (&BreakPoints)[*((_DWORD *)this + 11)];
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
