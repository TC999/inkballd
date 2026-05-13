#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

int CreateInkballKey()
{
  int v0; // edi
  int*v2; // [esp+0h] [ebp-28h]
  int*v3; // [esp+0h] [ebp-28h]
  uint8_t v4[8]; // [esp+10h] [ebp-18h] BYREF
  HKEY hKey; // [esp+18h] [ebp-10h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CreateInkballKey", 0);
  v6 = 0;
  v0 = 0;
  if ( !Helpers::RegCreateKeyExW(HKEY_CURRENT_USER, (HKEY)&SubKey, 0, 0, 0, 0x2001Fu, 0, &hKey, 0, 0, v2) )
  {
    v0 = 1;
    Helpers::RegCloseKey(hKey, 0, v3);
  }
  v6 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
  return v0;
}
