//----- (0100D47B) --------------------------------------------------------
void CScoreManager::ResetScore(void *self)
{
  int v2; // eax
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CScoreManager::ResetScore", 0);
  v2 = *(_DWORD *)self;
  v4 = 0;
  *((_DWORD *)self + 10) = 0;
  (*(void (__thiscall **)(CScoreManager *))(v2 + 4))((CScoreManager *)self);
  v4 = -1;
  ((Helpers::CLogBlock *)v3)->~CLogBlock();
}
