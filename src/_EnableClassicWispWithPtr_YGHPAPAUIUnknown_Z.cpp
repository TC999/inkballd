#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
int __stdcall EnableClassicWispWithPtr(LPVOID *ppv)
{
  int v1; // ebx
  uint32_t v3[2]; // [esp+Ch] [ebp-8h] BYREF

  v1 = 1;
  v3[0] = 0;
  v3[1] = 0;
  if ( CoCreateInstance(&CLSID_ClassicW, 0, 0x17u, &IID_IUnknown, ppv) < 0
    || (*(int (__stdcall **)(uint32_t, uint32_t *))(*(uint32_t *)*ppv + 12))(*ppv, v3) < 0
    || ((int (__stdcall *)(uint32_t, uint32_t, uint32_t, uint32_t))v3[0])(
         CLSID_EnablingKey.Data1,
         *(uint32_t *)&CLSID_EnablingKey.Data2,
         *(uint32_t *)CLSID_EnablingKey.Data4,
         *(uint32_t *)&CLSID_EnablingKey.Data4[4]) < 0 )
  {
    return 0;
  }
  return v1;
}
