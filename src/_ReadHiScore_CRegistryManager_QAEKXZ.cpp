#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __thiscall CRegistryManager::ReadHiScore(CRegistryManager *this)
{
  int v2; // esi
  BYTE v4[8]; // [esp+10h] [ebp-18h] BYREF
  BYTE Data[12]; // [esp+18h] [ebp-10h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CRegistryManager::ReadHiScore", 0);
  v6 = 0;
  if ( !ReadRegValueDWORD(HKEY_CURRENT_USER, (HKEY)&SubKey, (HKEY)&ValueName, Data) )
  {
    CreateInkballKey();
    CRegistryManager::WriteHiScore(this, 0x88u);
    *(uint32_t *)Data = 5000;
  }
  v2 = *(uint32_t *)Data;
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
