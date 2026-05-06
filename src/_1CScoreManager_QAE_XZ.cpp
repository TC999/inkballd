void __thiscall CScoreManager::~CScoreManager(CScoreManager *this)
{
  int v2; // [esp-4h] [ebp-28h]
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  *(_DWORD *)this = &CScoreManager::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CScoreManager::~CScoreManager", 0);
  v2 = *((_DWORD *)this + 9);
  v4 = 0;
  CRegistryManager::WriteHiScore((CRegistryManager *)&g_CRegistryManager, v2);
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
