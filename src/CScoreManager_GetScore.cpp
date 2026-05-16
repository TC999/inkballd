//----- (01006B02) --------------------------------------------------------
unsigned int CScoreManager::GetScore(void *self)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CScoreManager::GetScore", 0);
  v2 = *((_DWORD *)self + 10);
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return v2;
}
