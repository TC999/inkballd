#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
void Restore_CTimeManager(CTimeManager *self)
{
    IDirectDrawSurface7* DDrawSurface;
    IDirectDrawSurface7Vtbl* lpVtbl;
    IDirectDrawSurface7* v12;
    IDirectDrawSurface7Vtbl* v13;
    IDirectDrawSurface7* v14;
    IDirectDrawSurface7Vtbl* v15;
    IDirectDrawSurface7* v16;
    IDirectDrawSurface7Vtbl* v17;
    IDirectDrawSurface7* v18;
    IDirectDrawSurface7* v19;
    IDirectDrawSurface7Vtbl* v20;
    IDirectDrawSurface7* v21;
    IDirectDrawSurface7* v22;
    IDirectDrawSurface7* v23;
    IDirectDrawSurface7* v3;
    IDirectDrawSurface7* v31;
    IDirectDrawSurface7* v5;
    IDirectDrawSurface7* v7;
    IDirectDrawSurface7Vtbl* v8;
    IDirectDrawSurface7* v9;
  uint32_t v6; // esi
  uint32_t v10; // edx
  bool v11; // zf
  char*BitmapRect; // [esp-8h] [ebp-44h]
  char*v25; // [esp-8h] [ebp-44h]
  char*v26; // [esp-8h] [ebp-44h]
  char*v27; // [esp-8h] [ebp-44h]
  char*v28; // [esp-8h] [ebp-44h]
  char*v29; // [esp-8h] [ebp-44h]
  uint8_t v30[8]; // [esp+10h] [ebp-2Ch] BYREF
  IDirectDrawSurface7* v32; // [esp+1Ch] [ebp-20h]
  CTimeManager *v33; // [esp+20h] [ebp-1Ch]
  int v34; // [esp+24h] [ebp-18h]
  uint32_t v35; // [esp+28h] [ebp-14h]
  uint32_t v36; // [esp+2Ch] [ebp-10h]
  int v37; // [esp+38h] [ebp-4h]

  v33 = self;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v30, "CTimeManager::Restore", 0);
  v37 = 0;
  DDrawSurface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  DDrawSurface->lpVtbl->Restore(DDrawSurface);
  v3 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  lpVtbl = v3->lpVtbl;
  v34 = (int)(uintptr_t)v3;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 109);
  v5 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast((IDirectDrawSurface7 *)v34, 0, 0, v5, (LPRECT)BitmapRect, 0);
  v6 = *((uint32_t *)self + 3) - dwLeftDrawDif - 9;
  v35 = *((uint32_t *)self + 9) / 0x3E8u;
  v36 = dwTopDrawLoc;
  v7 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v8 = v7->lpVtbl;
  v34 = (int)(uintptr_t)v7;
  v25 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 158);
  v9 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v8->BltFast((IDirectDrawSurface7 *)v34, v6, v36, v9, (LPRECT)v25, 0);
  if ( v35 > 0x3E7 )
  {
    v34 = 3;
    do
    {
      v6 -= 9;
      v16 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
      v17 = v16->lpVtbl;
      v31 = v16;
      v28 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v18 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
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
      v32 = (IDirectDrawSurface7*)(uintptr_t)v10;
      if ( v11 )
      {
        v12 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
        v13 = v12->lpVtbl;
        v32 = v12;
        v26 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v22 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        v13->BltFast(v32, v6, v36, v22, (LPRECT)v26, 0);
      }
      else
      {
        v14 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
        v15 = v14->lpVtbl;
        v31 = v14;
        v27 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (uint32_t)(uintptr_t)v32 + 146);
        v23 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        v15->BltFast(v31, v6, v36, v23, (LPRECT)v27, 0);
      }
      --v34;
    }
    while ( v34 );
  }
  v19 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v20 = v19->lpVtbl;
  v31 = v19;
  v29 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 145);
  v21 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v20->BltFast(v31, v6 - 9, v36, v21, (LPRECT)v29, 0);
  v37 = -1;
  ((Helpers::CLogBlock *)v30)->~CLogBlock();
}
