#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
BOOL __stdcall fPortraitMode()
{
  BOOL v0; // esi
  int SystemMetrics; // edi
  int*v3; // [esp+0h] [ebp-104h]
  int*v4; // [esp+0h] [ebp-104h]
  uint8_t v5[8]; // [esp+10h] [ebp-F4h] BYREF
  DEVMODEW DevMode; // [esp+18h] [ebp-ECh] BYREF
  int v7; // [esp+100h] [ebp-4h]

  v0 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "fPortraitMode", 0);
  v7 = 0;
  memset(&DevMode, 0, sizeof(DevMode));
  DevMode.dmSize = 220;
  if ( EnumDisplaySettingsExW(0, 0xFFFFFFFF, &DevMode, 6u) && SLOBYTE(DevMode.dmFields) < 0 )
  {
    if ( DevMode.dmDisplayOrientation == 1 || DevMode.dmDisplayOrientation == 3 )
      v0 = 1;
  }
  else
  {
    SystemMetrics = Helpers::GetSystemMetrics((Helpers *)1, 0, v3);
    v0 = Helpers::GetSystemMetrics(0, 0, v4) < SystemMetrics;
  }
  v7 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v0;
}
