//----- (01006B02) --------------------------------------------------------
unsigned int __thiscall CScoreManager::GetScore(CScoreManager *this)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CScoreManager::GetScore", 0);
  v2 = *((_DWORD *)this + 10);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
