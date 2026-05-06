struct BallPoint *__thiscall CBall::GetPoint(CBall *this, int a2)
{
  int v3; // esi
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::GetPoint", 0);
  v3 = **((_DWORD **)this + 30) + 8 * a2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return (struct BallPoint *)v3;
}
