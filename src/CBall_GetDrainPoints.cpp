//----- (01003DC7) --------------------------------------------------------
int *CBall::GetDrainPoints(CBall* self)
{
  int *v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::GetDrainPoints", 0);
  v2 = (&DrainPoints)[*((_DWORD *)self + 11)];
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return v2;
}
