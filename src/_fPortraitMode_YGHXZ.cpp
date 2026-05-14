#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <new>

int __stdcall fPortraitMode()
{
  BOOL v0;
  int SystemMetrics;
  int*v3;
  int*v4;
  uint8_t v5[8];
  DEVMODEW DevMode;
  int v7;

  v0 = 0;
  new (v5) Helpers::CLogBlock(v5, "fPortraitMode", 0);
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
    SystemMetrics = Helpers::GetSystemMetrics((void*)1, 0, v3);
    v0 = Helpers::GetSystemMetrics((void*)0, 0, v4) < SystemMetrics;
  }
  v7 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
  return v0;
}
