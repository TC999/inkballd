#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void DrawToSurface_CTimeManager(CTimeManager* self)
{
  uint32_t v2; // eax
  uint32_t v3; // edi
  uint32_t v5; // edx
  char*v7; // eax
  char*v8; // eax
  LONG v9; // ecx
  LONG v10; // eax
  char*v11; // eax
  char*v12; // ecx
  bool v13; // zf
  char*v16; // eax
  char*v17; // eax
  LONG v18; // ecx
  LONG v19; // eax
  char*v21; // eax
  char*v22; // eax
  LONG v23; // ecx
  LONG v24; // eax
  char*v25; // eax
  char*BitmapRect; // [esp-8h] [ebp-58h]
  char*v30; // [esp-8h] [ebp-58h]
  char*v31; // [esp-8h] [ebp-58h]
  char*v32; // [esp-8h] [ebp-58h]
  char*v33; // [esp-8h] [ebp-58h]
  uint8_t v35[8]; // [esp+20h] [ebp-30h] BYREF
  char*v36; // [esp+28h] [ebp-28h]
  uint32_t p_BltFast; // [esp+2Ch] [ebp-24h] vtable function pointer
  IDirectDrawSurface7* DDrawSurface; // [esp+30h] [ebp-20h]
  uint32_t v41; // [esp+3Ch] [ebp-14h]
  uint32_t v42; // [esp+40h] [ebp-10h]
  int v43; // [esp+4Ch] [ebp-4h]
  RECT v34; // update rect (was auto-declared uint32_t)
  IDirectDrawSurface7* v4; // src surface
  IDirectDrawSurface7* v14; // temp
  IDirectDrawSurface7* v15; // temp
  IDirectDrawSurface7* v6_surf; // temp
  IDirectDrawSurface7* v20; // temp
  uint32_t digit_states[3]; // tracking

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v35), "CTimeManager::DrawToSurface", 0);
  v2 = *((uint32_t *)self + 9) / 0x3E8u;
  v3 = *((uint32_t *)self + 3) - dwLeftDrawDif - 9;
  v43 = 0;
  v42 = v3;
  v41 = dwTopDrawLoc;
  DDrawSurface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  p_BltFast = *(uint32_t*)((uint8_t*)DDrawSurface->lpVtbl + 28);
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 158);
  v4 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  ((void (__stdcall *)(IDirectDrawSurface7*, uint32_t, uint32_t, IDirectDrawSurface7*, char*, uint32_t))p_BltFast)(
    DDrawSurface, v3, v41, v4, BitmapRect, 0);
  if ( v2 <= 0x3E7 )
  {
    uint32_t saved_time = v2;
    uint8_t* state_ptr = (uint8_t*)&digit_states[0];
    while ( 1 )
    {
      v5 = saved_time % 0xA;
      saved_time /= 0xAu;
      v42 -= dwTimeDigitWidth;
      if ( *((uint32_t *)self + 12) )
      {
        v13 = *(uint32_t*)state_ptr == v5 + 146;
        if ( !v13 )
        {
          DDrawSurface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
          p_BltFast = *(uint32_t*)((uint8_t*)DDrawSurface->lpVtbl + 28);
          v31 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v5 + 146);
          v14 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
          ((void (__stdcall *)(IDirectDrawSurface7*, uint32_t, uint32_t, IDirectDrawSurface7*, char*, uint32_t))p_BltFast)(
            DDrawSurface, v42, v41, v14, v31, 0);
          v15 = (IDirectDrawSurface7*)(uintptr_t)(v5 + 146);
          *(uint32_t*)state_ptr = v5 + 146;
          v34.left = v42 + *((uint32_t *)self + 1);
          v16 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v5 + 146);
          v36 = (char*)(v34.left + *((uint32_t *)v16 + 2));
          v17 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v5 + 146);
          v18 = (LONG)&v36[-*(uint32_t *)v17];
          v19 = v41 + *((uint32_t *)self + 2);
          v34.right = v18;
          v34.top = v19;
          v36 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v5 + 146) + 12;
          v11 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v5 + 146);
          v12 = v36;
          goto LABEL_8;
        }
      }
      else if ( *(uint32_t*)state_ptr != 157 )
      {
        DDrawSurface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
        p_BltFast = *(uint32_t*)((uint8_t*)&DDrawSurface->lpVtbl->BltFast);
        v30 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v6_surf = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        ((void (__stdcall *)(IDirectDrawSurface7*, uint32_t, uint32_t, IDirectDrawSurface7*, char*, uint32_t))p_BltFast)(
          DDrawSurface, v42, v41, v6_surf, v30, 0);
        *(uint32_t*)state_ptr = 157;
        v34.left = v42 + *((uint32_t *)self + 1);
        v7 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v36 = (char*)(v34.left + *((uint32_t *)v7 + 2));
        v8 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v9 = (LONG)&v36[-*(uint32_t *)v8];
        v10 = v41 + *((uint32_t *)self + 2);
        v34.right = v9;
        v34.top = v10;
        v36 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157) + 12;
        v11 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v12 = v36;
LABEL_8:
        v34.bottom = v34.top + *(uint32_t *)v12 - *((uint32_t *)v11 + 1);
        AddDisplayUpdateRect(&v34);
      }
      state_ptr += 4;
      if ( (int)state_ptr >= (int)&digit_states[3] )
        goto LABEL_15;
    }
  }
  {
    uint8_t* state_ptr2 = (uint8_t*)&digit_states[0];
    do
    {
      v42 -= 9;
      if ( *(uint32_t*)state_ptr2 != 156 )
      {
        DDrawSurface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
        p_BltFast = *(uint32_t*)((uint8_t*)DDrawSurface->lpVtbl + 28);
        v32 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
        v20 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        ((void (__stdcall *)(IDirectDrawSurface7*, uint32_t, uint32_t, IDirectDrawSurface7*, char*, uint32_t))p_BltFast)(
          DDrawSurface, v42, v41, v20, v32, 0);
        *(uint32_t*)state_ptr2 = 156;
        v34.left = v42 + *((uint32_t *)self + 1);
        v21 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
        v36 = (char*)(v34.left + *((uint32_t *)v21 + 2));
        v22 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
        v23 = (LONG)&v36[-*(uint32_t *)v22];
        v24 = v41 + *((uint32_t *)self + 2);
        v34.right = v23;
        v34.top = v24;
        v36 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156) + 12;
        v25 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
        v34.bottom = v34.top + *(uint32_t *)v36 - *((uint32_t *)v25 + 1);
        AddDisplayUpdateRect(&v34);
      }
      state_ptr2 += 4;
    }
    while ( (int)state_ptr2 < (int)&digit_states[3] );
  }
LABEL_15:
  v42 -= 9;
  DDrawSurface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v33 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 145);
  v4 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  DDrawSurface->lpVtbl->BltFast(DDrawSurface, v42, v41, v4, (LPRECT)v33, 0);
  v43 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v35)->~CLogBlock();
}
