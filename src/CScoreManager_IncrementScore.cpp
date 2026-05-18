//----- (0100D429) --------------------------------------------------------
void CScoreManager::IncrementScore(void *self, int a2)
{
  unsigned int v3; // eax
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CScoreManager::IncrementScore", 0);
  *((_DWORD *)self + 10) += a2;
  v3 = *((_DWORD *)self + 10);
  v5 = 0;
  if ( v3 >= *((_DWORD *)self + 9) )
    *((_DWORD *)self + 9) = v3;
  CScoreManager::DrawToSurface((CScoreManager *)self);
  v5 = -1;
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
}
