#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern "C" PIMAGE_NT_HEADERS __stdcall RtlImageNtHeader(PVOID Base);

int _get_image_app_type(int a1)
{
  HMODULE ModuleHandleA;
  PIMAGE_NT_HEADERS v2;
  __int16 v3;

  ModuleHandleA = GetModuleHandleA(0);
  if ( !ModuleHandleA )
    return a1;
  v2 = RtlImageNtHeader(ModuleHandleA);
  if ( !v2 )
    return a1;
  v3 = *reinterpret_cast<uint16_t*>(reinterpret_cast<char*>(v2) + 92);
  if ( v3 == 2 )
    return 2;
  if ( v3 == 3 )
    return 1;
  else
    return a1;
}
