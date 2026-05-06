void __thiscall CBoardManager::~CBoardManager(CBoardManager *this)
{
  unsigned int v2; // [esp-4h] [ebp-28h]
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardManager::~CBoardManager", 0);
  v2 = *((_DWORD *)this + 33281);
  v4 = 0;
  CRegistryManager::WriteDifficulty((CRegistryManager *)&g_CRegistryManager, v2);
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
