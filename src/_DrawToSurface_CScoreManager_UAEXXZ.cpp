#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __thiscall CScoreManager::DrawToSurface(CScoreManager *this)
{
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  struct IDirectDrawSurface7Vtbl *lpVtbl; // edi
  struct IDirectDrawSurface7 *v4; // eax
  int v5; // edi
  DWORD v6; // edi
  struct IDirectDrawSurface7 *v7; // eax
  struct IDirectDrawSurface7Vtbl *v8; // ebx
  struct IDirectDrawSurface7 *v9; // eax
  struct IDirectDrawSurface7 *v10; // eax
  struct IDirectDrawSurface7Vtbl *v11; // ebx
  struct IDirectDrawSurface7 *v12; // eax
  DWORD v13; // edi
  struct IDirectDrawSurface7 *v14; // eax
  struct IDirectDrawSurface7Vtbl *v15; // ebx
  struct IDirectDrawSurface7 *v16; // eax
  DWORD v17; // edi
  struct IDirectDrawSurface7 *v18; // eax
  struct IDirectDrawSurface7Vtbl *v19; // ebx
  struct IDirectDrawSurface7 *v20; // eax
  struct IDirectDrawSurface7 *v21; // eax
  struct IDirectDrawSurface7Vtbl *v22; // ebx
  struct IDirectDrawSurface7 *v23; // eax
  struct IDirectDrawSurface7 *v24; // eax
  struct IDirectDrawSurface7Vtbl *v25; // ebx
  struct IDirectDrawSurface7 *v26; // eax
  char*BitmapRect; // [esp-8h] [ebp-3Ch]
  char*v28; // [esp-8h] [ebp-3Ch]
  char*v29; // [esp-8h] [ebp-3Ch]
  char*v30; // [esp-8h] [ebp-3Ch]
  char*v31; // [esp-8h] [ebp-3Ch]
  char*v32; // [esp-8h] [ebp-3Ch]
  char*v33; // [esp-8h] [ebp-3Ch]
  uint8_t v34[8]; // [esp+10h] [ebp-24h] BYREF
  uint32_t v35; // [esp+18h] [ebp-1Ch]
  uint32_t v36; // [esp+1Ch] [ebp-18h]
  CScoreManager *v37; // [esp+20h] [ebp-14h]
  struct IDirectDrawSurface7 *v38; // [esp+24h] [ebp-10h]
  int v39; // [esp+30h] [ebp-4h]

  v37 = this;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v34, "CScoreManager::DrawToSurface", 0);
  v39 = 0;
  DDrawSurface = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v38 = DDrawSurface;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 107);
  v4 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast(v38, 0, 0, v4, (LPRECT)BitmapRect, 0);
  v5 = *((uint32_t *)this + 3);
  v38 = (struct IDirectDrawSurface7 *)*((uint32_t *)this + 9);
  v6 = v5 - 12;
  v7 = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  v8 = v7->lpVtbl;
  v36 = (uint32_t)v7;
  v28 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 133);
  v9 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v8->BltFast((IDirectDrawSurface7 *)v36, v6, 13, v9, (LPRECT)v28, 0);
  do
  {
    v6 -= 9;
    v36 = (uint32_t)v38 % 0xA;
    v38 = (struct IDirectDrawSurface7 *)((uint32_t)v38 / 0xA);
    v10 = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
    v11 = v10->lpVtbl;
    v35 = (uint32_t)v10;
    v29 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v36 + 123);
    v12 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    v11->BltFast((IDirectDrawSurface7 *)v35, v6, 13, v12, (LPRECT)v29, 0);
  }
  while ( v38 );
  v13 = v6 - 9;
  v14 = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  v15 = v14->lpVtbl;
  v35 = (uint32_t)v14;
  v30 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 122);
  v16 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v15->BltFast((IDirectDrawSurface7 *)v35, v13, 13, v16, (LPRECT)v30, 0);
  v17 = v13 - 20;
  v38 = (struct IDirectDrawSurface7 *)*((uint32_t *)v37 + 10);
  v18 = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  v19 = v18->lpVtbl;
  v35 = (uint32_t)v18;
  v31 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 121);
  v20 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v19->BltFast((IDirectDrawSurface7 *)v35, v17, 13, v20, (LPRECT)v31, 0);
  do
  {
    v17 -= 9;
    v35 = (uint32_t)v38 % 0xA;
    v38 = (struct IDirectDrawSurface7 *)((uint32_t)v38 / 0xA);
    v21 = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
    v22 = v21->lpVtbl;
    v36 = (uint32_t)v21;
    v32 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v35 + 111);
    v23 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    v22->BltFast((IDirectDrawSurface7 *)v36, v17, 13, v23, (LPRECT)v32, 0);
  }
  while ( v38 );
  v24 = CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  v25 = v24->lpVtbl;
  v35 = (uint32_t)v24;
  v33 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 110);
  v26 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v25->BltFast((IDirectDrawSurface7 *)v35, v17 - 9, 13, v26, (LPRECT)v33, 0);
  AddDisplayUpdateRect((struct tagRECT *)((char*)v37 + 20));
  v39 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v34);
}
