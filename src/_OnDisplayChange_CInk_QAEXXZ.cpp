#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void OnDisplayChange_CInk(CInk *self)
{
  int v1; // esi
  int v2; // edi
  uint8_t v3[16]; // [esp+10h] [ebp-28h] BYREF
  uint8_t v4[8]; // [esp+20h] [ebp-18h] BYREF
  int v5[3]; // [esp+28h] [ebp-10h] BYREF
  int v6; // [esp+34h] [ebp-4h]

  v1 = 0;
  v5[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)v4, "CInk::OnDisplayChange", v5);
  v6 = 0;
  if ( dword_10B068C > 0 )
  {
    v2 = dword_10B068C;
    do
    {
      v5[0] = (*(int (__stdcall **)(uint32_t, uint8_t *))(**(uint32_t **)((char*)g_arrTCI + v1 + 4) + 56))(
                *(uint32_t *)((char*)g_arrTCI + v1 + 4),
                v3);
      if ( v5[0] >= 0 )
        v5[0] = (*(int (__stdcall **)(struct IInkObject *, uint32_t, uint8_t *, void*))(*(uint32_t *)g_pIInkObject + 132))(
                  (struct IInkObject *)g_pIInkObject,
                  *(uint32_t *)((char*)g_arrTCI + v1 + 8),
                  v3,
                  &g_rcTabletInInk);
      v1 += 24;
      --v2;
    }
    while ( v2 );
  }
  v6 = -1;
  ((Helpers::CLogBlock*)v4)->~CLogBlock();
}

