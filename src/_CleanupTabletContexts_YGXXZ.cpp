#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void CleanupTabletContexts()
{
  int v0; // ebx
  int v1; // esi
  int v2; // eax
  int v3; // eax
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CleanupTabletContexts", 0);
  v0 = 0;
  v5 = 0;
  if ( dword_10B068C > 0 )
  {
    v1 = 0;
    do
    {
      v2 = *(uint32_t *)((char*)g_arrTCI + v1 + 4);
      if ( v2 )
      {
        (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v2 + 8))(*(uint32_t *)((char*)g_arrTCI + v1 + 4));
        *(uint32_t *)((char*)g_arrTCI + v1 + 4) = 0;
      }
      v3 = *(uint32_t *)((char*)g_arrTCI + v1);
      if ( v3 )
      {
        (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v3 + 8))(*(uint32_t *)((char*)g_arrTCI + v1));
        *(uint32_t *)((char*)g_arrTCI + v1) = 0;
      }
      ++v0;
      v1 += 24;
    }
    while ( v0 < dword_10B068C );
  }
  CMFCArray<CTabletContextInfo,CTabletContextInfo &>::SetSize((int)&g_arrTCI, 0, -1);
  v5 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
