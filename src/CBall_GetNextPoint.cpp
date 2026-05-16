//----- (01003EC1) --------------------------------------------------------
void* CBall::GetNextPoint(CBall* self)
{
  int v2; // eax
  int v3; // esi
  int v5; // ecx
  _BYTE v6[16]; // [esp+10h] [ebp-14h] BYREF
  int v7; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CBall::GetNextPoint", 0);
  v2 = *((_DWORD *)self + 32);
  if ( v2 <= 16 )
  {
    v5 = **((_DWORD **)self + 30) + 8 * ((v2 + *((_DWORD *)self + 31)) % 32);
    *((_DWORD *)self + 32) = v2 + 1;
    v3 = v5;
  }
  else
  {
    *((_DWORD *)self + 32) = 0;
    v3 = 0;
  }
  v7 = -1;
  ((Helpers::CLogBlock *)v6)->~CLogBlock();
  return (struct BallPoint *)v3;
}
