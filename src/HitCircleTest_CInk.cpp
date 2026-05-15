#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

#define LODWORD(x) (*(uint32_t*)&(x))

// g_tcid and g_cid declared in global_types.h as void*
extern void* GetTabletContextInfo(void* tcid);
extern void SetBoardActiveState(int active);
extern int BltBoardToInk(void* rect);

int HitCircleTest_CInk(CInk *self, struct tagPOINT *a2, int a3, int a4)
{
  void* TabletContextInfo;
  int v5; // ecx
  uint8_t v8[8]; // [esp+5Ch] [ebp-34h] BYREF
  uint32_t v9[2]; // [esp+64h] [ebp-2Ch] BYREF
  uint32_t v10[2]; // [esp+6Ch] [ebp-24h] BYREF
  int v11; // [esp+74h] [ebp-1Ch] BYREF
  int v12; // [esp+78h] [ebp-18h]
  int v13; // [esp+7Ch] [ebp-14h] BYREF
  uint32_t v14[3]; // [esp+80h] [ebp-10h] BYREF
  int v15; // [esp+8Ch] [ebp-4h]
  int v16; // [esp+98h] [ebp+8h]
  float v17; // [esp+9Ch] [ebp+Ch]

  v13 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CInk::HitCircleTest", &v13);
  v5 = 10 * a2->x;
  v10[1] = 10 * a2->y;
  v15 = 0;
  v14[0] = 0;
  v10[0] = v5;
  if ( a3 == 1 )
    v16 = 1;
  else
    v16 = 10 * a3;
  v17 = (float)v16;
  v13 = (*(int (__stdcall **)(struct IInkObject *, uint32_t *, float, uint32_t *))(*(uint32_t *)g_pIInkObject + 108))(
          (IInkObject*)g_pIInkObject,
          v10,
          v17,
          v14);
  if ( v13 )
  {
    v12 = 0;
  }
  else
  {
    v12 = 1;
    if ( a4 )
    {
      SetBoardActiveState(0);
      (*(void (__stdcall **)(struct IInkObject *, int*))(*(uint32_t *)g_pIInkObject + 16))((IInkObject*)g_pIInkObject, &v11);
      v13 = (*(int (__stdcall **)(uint32_t, uint32_t, int, uint32_t *))(*(uint32_t *)v14[0] + 16))(v14[0], 0, 1, v9);
      if ( v13 < 0 || (v16 = 1, v9[0] != v11 - 1) )
        v16 = 0;
    }
    if ( v14[0] )
    {
      (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v14[0] + 8))(v14[0]);
      v14[0] = 0;
    }
    if ( a4 )
    {
      if ( v16 )
      {
        TabletContextInfo = GetTabletContextInfo(g_tcid);
        if ( TabletContextInfo )
        {
          (*(void (__stdcall **)(uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t))(**(uint32_t **)TabletContextInfo
                                                                                            + 36))(
            *(uint32_t *)TabletContextInfo,
            (uint32_t)g_tcid,
            (uint32_t)g_cid,
            0,
            0,
            0);
          *((uint32_t *)self + 4) = 0;
        }
      }
      v13 = (*(int (__stdcall **)(struct IInkObject *, uint32_t *, float, uint32_t *))(*(uint32_t *)g_pIInkObject + 108))(
              (IInkObject*)g_pIInkObject,
              v10,
              v17,
              v14);
      if ( !v13 )
      {
        if ( (*(int (__stdcall **)(uint32_t, uint32_t, int, uint32_t *))(*(uint32_t *)v14[0] + 16))(v14[0], 0, 1, v9) >= 0 )
          (*(void (__stdcall **)(struct IInkObject *, uint32_t, int))(*(uint32_t *)g_pIInkObject + 68))(
            (IInkObject*)g_pIInkObject,
            v9[0],
            1);
        if ( v14[0] )
        {
          (*(void (__stdcall **)(uint32_t))(*(uint32_t *)v14[0] + 8))(v14[0]);
          v14[0] = 0;
        }
      }
      ::BltBoardToInk((tagRECT*)0);
      *((uint32_t *)self + 4) = 1;
      CInk_DrawInkToSurface(self);
      SetBoardActiveState(1);
    }
  }
  v15 = -1;
  ((Helpers::CLogBlock*)v8)->~CLogBlock();
  return v12;
}

