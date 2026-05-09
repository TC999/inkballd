#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CTimeManager::DrawToSurface(CTimeManager *this)
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
  void (__stdcall **v27)(struct IDirectDrawSurface7 *, uint32_t, uint32_t, struct IDirectDrawSurface7 *, char*, uint32_t); // edi
  char*BitmapRect; // [esp-8h] [ebp-58h]
  char*v30; // [esp-8h] [ebp-58h]
  char*v31; // [esp-8h] [ebp-58h]
  char*v32; // [esp-8h] [ebp-58h]
  char*v33; // [esp-8h] [ebp-58h]
  uint8_t v35[8]; // [esp+20h] [ebp-30h] BYREF
  char*v36; // [esp+28h] [ebp-28h]
  char*p_BltFast; // [esp+2Ch] [ebp-24h]
  uint32_t DDrawSurface; // [esp+30h] [ebp-20h]
  uint32_t v41; // [esp+3Ch] [ebp-14h]
  uint32_t v42; // [esp+40h] [ebp-10h]
  int v43; // [esp+4Ch] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v35, "CTimeManager::DrawToSurface", 0);
  v2 = *((uint32_t *)this + 9) / 0x3E8u;
  v3 = *((uint32_t *)this + 3) - dwLeftDrawDif - 9;
  v43 = 0;
  v42 = v3;
  v40 = (struct IDirectDrawSurface7 *)v2;
  v41 = dwTopDrawLoc;
  DDrawSurface = (uint32_t)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v39 = (struct IDirectDrawSurface7 *)(*(uint32_t *)DDrawSurface + 28);
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 158);
  v4 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  ((void (__stdcall *)(uint32_t, uint32_t, uint32_t, struct IDirectDrawSurface7 *, char*, uint32_t))v39->lpVtbl)(
    DDrawSurface,
    v3,
    v41,
    v4,
    BitmapRect,
    0);
  if ( (uint32_t)v40 <= 0x3E7 )
  {
    DDrawSurface = (uint32_t)v40;
    v40 = (struct IDirectDrawSurface7 *)&unk_10B06A4;
    while ( 1 )
    {
      v5 = DDrawSurface % 0xA;
      DDrawSurface /= 0xAu;
      v42 -= dwTimeDigitWidth;
      if ( *((uint32_t *)this + 12) )
      {
        v13 = v40->lpVtbl == (struct IDirectDrawSurface7Vtbl *)(v5 + 146);
        v39 = (struct IDirectDrawSurface7 *)(v5 + 146);
        if ( !v13 )
        {
          p_BltFast = (char*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
          v36 = (char*)(*(uint32_t *)p_BltFast + 28);
          v31 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (int)v39);
          v14 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
          (*(void (__stdcall **)(char*, uint32_t, uint32_t, struct IDirectDrawSurface7 *, char*, uint32_t))v36)(
            p_BltFast,
            v42,
            v41,
            v14,
            v31,
            0);
          v15 = v39;
          v40->lpVtbl = (struct IDirectDrawSurface7Vtbl *)v39;
          v34.left = v42 + *((uint32_t *)this + 1);
          v16 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (int)v15);
          v36 = (char*)(v34.left + *((uint32_t *)v16 + 2));
          v17 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (int)v39);
          v18 = (LONG)&v36[-*(uint32_t *)v17];
          v19 = v41 + *((uint32_t *)this + 2);
          v34.right = v18;
          v34.top = v19;
          v36 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (int)v39) + 12;
          v11 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (int)v39);
          v12 = v36;
          goto LABEL_8;
        }
      }
      else if ( v40->lpVtbl != (struct IDirectDrawSurface7Vtbl *)157 )
      {
        v39 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
        p_BltFast = (char*)&v39->lpVtbl->BltFast;
        v30 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v6 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        (*(void (__stdcall **)(struct IDirectDrawSurface7 *, uint32_t, uint32_t, struct IDirectDrawSurface7 *, char*, uint32_t))p_BltFast)(
          v39,
          v42,
          v41,
          v6,
          v30,
          0);
        v40->lpVtbl = (struct IDirectDrawSurface7Vtbl *)157;
        v34.left = v42 + *((uint32_t *)this + 1);
        v7 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        p_BltFast = (char*)(v34.left + *((uint32_t *)v7 + 2));
        v8 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v9 = (LONG)&p_BltFast[-*(uint32_t *)v8];
        v10 = v41 + *((uint32_t *)this + 2);
        v34.right = v9;
        v34.top = v10;
        p_BltFast = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157) + 12;
        v11 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v12 = p_BltFast;
LABEL_8:
        v34.bottom = v34.top + *(uint32_t *)v12 - *((uint32_t *)v11 + 1);
        AddDisplayUpdateRect(&v34);
      }
      if ( (int)++v40 >= (int)&Src )
        goto LABEL_15;
    }
  }
  v39 = (struct IDirectDrawSurface7 *)&unk_10B06A4;
  do
  {
    v42 -= 9;
    if ( v39->lpVtbl != (struct IDirectDrawSurface7Vtbl *)156 )
    {
      v36 = (char*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
      p_BltFast = (char*)(*(uint32_t *)v36 + 28);
      v32 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v20 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
      (*(void (__stdcall **)(char*, uint32_t, uint32_t, struct IDirectDrawSurface7 *, char*, uint32_t))p_BltFast)(
        v36,
        v42,
        v41,
        v20,
        v32,
        0);
      v39->lpVtbl = (struct IDirectDrawSurface7Vtbl *)156;
      v34.left = v42 + *((uint32_t *)this + 1);
      v21 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v36 = (char*)(v34.left + *((uint32_t *)v21 + 2));
      v22 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v23 = (LONG)&v36[-*(uint32_t *)v22];
      v24 = v41 + *((uint32_t *)this + 2);
      v34.right = v23;
      v34.top = v24;
      v36 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156) + 12;
      v25 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v34.bottom = v34.top + *(uint32_t *)v36 - *((uint32_t *)v25 + 1);
      AddDisplayUpdateRect(&v34);
    }
    ++v39;
  }
  while ( (int)v39 < (int)&Src );
LABEL_15:
  v42 -= 9;
  v26 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v27 = (void (__stdcall **)(struct IDirectDrawSurface7 *, uint32_t, uint32_t, struct IDirectDrawSurface7 *, char*, uint32_t))&v26->lpVtbl->BltFast;
  v33 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 145);
  v28 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  (*v27)(v26, v42, v41, v28, v33, 0);
  v43 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v35);
}
