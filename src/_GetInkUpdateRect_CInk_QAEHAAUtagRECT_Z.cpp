#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int GetInkUpdateRect_CInk(CInk *self, struct tagRECT *a2)
{
  int v3; // edi
  bool v4; // zf
  tagXFORM v6; // [esp+10h] [ebp-30h] BYREF
  uint8_t v7[8]; // [esp+28h] [ebp-18h] BYREF
  int v8[3]; // [esp+30h] [ebp-10h] BYREF
  int v9; // [esp+3Ch] [ebp-4h]

  v3 = 0;
  v8[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CInk::GetInkUpdateRect", v8);
  v4 = *((uint32_t *)self + 3) == 0;
  v9 = 0;
  if ( !v4 )
  {
    *((uint32_t *)self + 3) = 0;
    CInk::DrawInkToSurface(self, 0);
  }
  if ( *((uint32_t *)self + 2) )
  {
    *((uint32_t *)self + 2) = 0;
    v8[0] = (*(int (__stdcall **)(struct IRenderingContext *, tagXFORM *))(*(uint32_t *)g_pIRenderingContext + 20))(
              g_pIRenderingContext,
              &v6);
    if ( v8[0] >= 0 )
    {
      if ( g_pIStroke )
      {
        v8[0] = (*(int (__stdcall **)(struct IInkStroke *, uint32_t, struct tagRECT *))(*(uint32_t *)g_pIStroke + 16))(
                  g_pIStroke,
                  0,
                  a2);
        if ( v8[0] >= 0 )
        {
          ExpandRect(a2, 200);
          ConvertInkRectToDisplayRect(a2, &v6);
          v3 = 1;
        }
      }
    }
  }
  v9 = -1;
  ((Helpers::CLogBlock*)v7)->~CLogBlock();
  return v3;
}

