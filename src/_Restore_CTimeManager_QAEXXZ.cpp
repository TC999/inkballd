#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CTimeManager::Restore(CTimeManager *this)
{
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  struct IDirectDrawSurface7 *v3; // eax
  struct IDirectDrawSurface7Vtbl *lpVtbl; // esi
  struct IDirectDrawSurface7 *v5; // eax
  uint32_t v6; // esi
  struct IDirectDrawSurface7 *v7; // eax
  struct IDirectDrawSurface7Vtbl *v8; // ebx
  struct IDirectDrawSurface7 *v9; // eax
  uint32_t v10; // edx
  bool v11; // zf
  struct IDirectDrawSurface7 *v12; // eax
  struct IDirectDrawSurface7Vtbl *v13; // ebx
  struct IDirectDrawSurface7 *v14; // eax
  struct IDirectDrawSurface7Vtbl *v15; // ebx
  struct IDirectDrawSurface7 *v16; // eax
  struct IDirectDrawSurface7Vtbl *v17; // ebx
  struct IDirectDrawSurface7 *v18; // eax
  struct IDirectDrawSurface7 *v19; // eax
  struct IDirectDrawSurface7Vtbl *v20; // ebx
  struct IDirectDrawSurface7 *v21; // eax
  struct IDirectDrawSurface7 *v22; // [esp-Ch] [ebp-48h]
  struct IDirectDrawSurface7 *v23; // [esp-Ch] [ebp-48h]
  char*BitmapRect; // [esp-8h] [ebp-44h]
  char*v25; // [esp-8h] [ebp-44h]
  char*v26; // [esp-8h] [ebp-44h]
  char*v27; // [esp-8h] [ebp-44h]
  char*v28; // [esp-8h] [ebp-44h]
  char*v29; // [esp-8h] [ebp-44h]
  uint8_t v30[8]; // [esp+10h] [ebp-2Ch] BYREF
  struct IDirectDrawSurface7 *v31; // [esp+18h] [ebp-24h]
  uint32_t v32; // [esp+1Ch] [ebp-20h]
  CTimeManager *v33; // [esp+20h] [ebp-1Ch]
  int v34; // [esp+24h] [ebp-18h]
  uint32_t v35; // [esp+28h] [ebp-14h]
  uint32_t v36; // [esp+2Ch] [ebp-10h]
  int v37; // [esp+38h] [ebp-4h]

  v33 = this;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CTimeManager::Restore", 0);
  v37 = 0;
  DDrawSurface = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  DDrawSurface->lpVtbl->Restore(DDrawSurface);
  v3 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  lpVtbl = v3->lpVtbl;
  v34 = (int)v3;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 109);
  v5 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast((IDirectDrawSurface7 *)v34, 0, 0, v5, (LPRECT)BitmapRect, 0);
  v6 = *((uint32_t *)this + 3) - dwLeftDrawDif - 9;
  v35 = *((uint32_t *)this + 9) / 0x3E8u;
  v36 = dwTopDrawLoc;
  v7 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v8 = v7->lpVtbl;
  v34 = (int)v7;
  v25 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 158);
  v9 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v8->BltFast((IDirectDrawSurface7 *)v34, v6, v36, v9, (LPRECT)v25, 0);
  if ( v35 > 0x3E7 )
  {
    v34 = 3;
    do
    {
      v6 -= 9;
      v16 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
      v17 = v16->lpVtbl;
      v31 = v16;
      v28 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v18 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
      v17->BltFast(v31, v6, v36, v18, (LPRECT)v28, 0);
      --v34;
    }
    while ( v34 );
  }
  else
  {
    v34 = 3;
    do
    {
      v10 = v35 % 0xA;
      v6 -= dwTimeDigitWidth;
      v35 /= 0xAu;
      v11 = *((uint32_t *)v33 + 12) == 0;
      v32 = v10;
      if ( v11 )
      {
        v12 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
        v13 = v12->lpVtbl;
        v32 = (uint32_t)v12;
        v26 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v22 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        v13->BltFast((IDirectDrawSurface7 *)v32, v6, v36, v22, (LPRECT)v26, 0);
      }
      else
      {
        v14 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
        v15 = v14->lpVtbl;
        v31 = v14;
        v27 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v32 + 146);
        v23 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        v15->BltFast(v31, v6, v36, v23, (LPRECT)v27, 0);
      }
      --v34;
    }
    while ( v34 );
  }
  v19 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v20 = v19->lpVtbl;
  v31 = v19;
  v29 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 145);
  v21 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v20->BltFast(v31, v6 - 9, v36, v21, (LPRECT)v29, 0);
  v37 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v30);
}
