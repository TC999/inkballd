#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int __stdcall QueryInterface_CSink(CSink *self, const struct _GUID *a2, void**a3)
{
  int v3; // esi
  uint8_t v5[8]; // [esp+8h] [ebp-Ch] BYREF
  int v6; // [esp+10h] [ebp-4h] BYREF

  v6 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)v5, "CSink::QueryInterface", &v6);
  if ( !memcmp(a2, &IID_ITabletEventSink, 0x10u) || !memcmp(a2, &IID_IUnknown, 0x10u) )
  {
    *a3 = self;
    (*(void (__stdcall **)(CSink *))(*(uint32_t *)self + 4))(self);
    v3 = v6;
    ((Helpers::CLogBlock*)v5)->~CLogBlock();
    return v3;
  }
  else
  {
    *a3 = 0;
    ((Helpers::CLogBlock*)v5)->~CLogBlock();
    return -2147467262;
  }
}

