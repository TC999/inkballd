#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
BOOL __stdcall CTabLicense::GetBOOLPermission(PCWSTR pwszValueName, DWORD a2)
{
  BOOL v2; // esi
  const char*v4[2]; // [esp+0h] [ebp-10h] BYREF
  int v5; // [esp+8h] [ebp-8h] BYREF
  DWORD pdwValue; // [esp+Ch] [ebp-4h] BYREF

  v5 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CTabLicense::GetBOOLPermission", &v5);
  pdwValue = 0;
  v5 = SLGetWindowsInformationDWORD(pwszValueName, &pdwValue);
  if ( v5 < 0 )
    pdwValue = a2;
  v2 = pdwValue == 1;
  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 0x10) != 0 )
    WPP_SF_Sd(*((uint64_t *)WPP_GLOBAL_Control + 2), 0xAu, &stru_10039F4, pwszValueName, pdwValue == 1);
  Helpers::CLogBlock::~CLogBlock(v4);
  return v2;
}
