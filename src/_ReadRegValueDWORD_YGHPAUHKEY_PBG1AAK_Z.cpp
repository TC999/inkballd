#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
BOOL __stdcall ReadRegValueDWORD(HKEY hKey, HKEY lpSubKey, HKEY lpValueName, LPBYTE lpData)
{
  BOOL v4; // edi
  int*v6; // [esp+0h] [ebp-30h]
  int*v7; // [esp+0h] [ebp-30h]
  int*v8; // [esp+0h] [ebp-30h]
  uint8_t v9[8]; // [esp+10h] [ebp-20h] BYREF
  DWORD Type; // [esp+18h] [ebp-18h] BYREF
  DWORD cbData; // [esp+1Ch] [ebp-14h] BYREF
  HKEY phkResult; // [esp+20h] [ebp-10h] BYREF
  int v13; // [esp+2Ch] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "ReadRegValueDWORD", 0);
  v13 = 0;
  v4 = 0;
  cbData = 4;
  if ( !Helpers::RegOpenKeyExW(hKey, lpSubKey, 0, 0x20019u, &phkResult, 0, v6) )
  {
    v4 = Helpers::RegQueryValueExW(phkResult, lpValueName, 0, &Type, lpData, &cbData, 0, v7) == 0;
    Helpers::RegCloseKey(phkResult, 0, v8);
  }
  v13 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
  return v4;
}
