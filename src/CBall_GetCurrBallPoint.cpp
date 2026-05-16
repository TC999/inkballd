//----- (01003F30) --------------------------------------------------------
int CBall::GetCurrBallPoint(CBall* self)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::GetCurrBallPoint", 0);
  v2 = (*((_DWORD *)self + 31) + *((_DWORD *)self + 32)) % 32;
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return v2;
}
