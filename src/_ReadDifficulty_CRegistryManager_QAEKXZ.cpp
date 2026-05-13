#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int ReadDifficulty_CRegistryManager(CRegistryManager *self)
{
  int v2; // esi
  BYTE v4[8]; // [esp+10h] [ebp-18h] BYREF
  BYTE Data[12]; // [esp+18h] [ebp-10h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CRegistryManager::ReadDifficulty", 0);
  v6 = 0;
  if ( !ReadRegValueDWORD(HKEY_CURRENT_USER, (HKEY)&SubKey, (HKEY)&stru_1002CD8, Data) )
  {
    CreateInkballKey();
    CRegistryManager::WriteDifficulty(self, 0);
    *(uint32_t *)Data = 0;
  }
  v2 = *(uint32_t *)Data;
  v6 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v2;
}
