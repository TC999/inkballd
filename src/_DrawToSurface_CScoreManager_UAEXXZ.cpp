#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void DrawToSurface_CScoreManager(CScoreManager* self)
{
    IDirectDrawSurface7* DDrawSurface;
    IDirectDrawSurface7Vtbl* lpVtbl;
    IDirectDrawSurface7* v4;
    IDirectDrawSurface7* v7;
    IDirectDrawSurface7Vtbl* v8;
    IDirectDrawSurface7* v9;
    IDirectDrawSurface7* v14;
    IDirectDrawSurface7Vtbl* v15;
    IDirectDrawSurface7* v16;
    IDirectDrawSurface7* v18;
    IDirectDrawSurface7Vtbl* v19;
    IDirectDrawSurface7* tmpSurf;
    IDirectDrawSurface7* v22;
    IDirectDrawSurface7Vtbl* v23;
    IDirectDrawSurface7* v24;
    IDirectDrawSurface7* v25;
    IDirectDrawSurface7Vtbl* v26;
  int v5; // edi
  DWORD v6; // edi
  DWORD v13; // edi
  DWORD v17; // edi
  uint32_t score1; // score value (was v38)
  uint32_t score2; // high score value
  uint32_t digit;   // current digit
  IDirectDrawSurface7* v35; // reused surface ptr
  IDirectDrawSurface7* v36; // reused surface ptr
  char*BitmapRect; // [esp-8h] [ebp-3Ch]
  char*v28; // [esp-8h] [ebp-3Ch]
  char*v29; // [esp-8h] [ebp-3Ch]
  char*v30; // [esp-8h] [ebp-3Ch]
  char*v31; // [esp-8h] [ebp-3Ch]
  char*v32; // [esp-8h] [ebp-3Ch]
  char*v33; // [esp-8h] [ebp-3Ch]
  uint8_t v34[8]; // [esp+10h] [ebp-24h] BYREF
  CScoreManager *v37; // [esp+20h] [ebp-14h]
  int v39; // [esp+30h] [ebp-4h]

  v37 = self;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v34), "CScoreManager::DrawToSurface", 0);
  v39 = 0;
  DDrawSurface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v36 = DDrawSurface;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 107);
  v4 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast(v36, 0, 0, v4, (LPRECT)BitmapRect, 0);
  v5 = *((uint32_t *)self + 3);
  score1 = *((uint32_t *)self + 9);
  v6 = v5 - 12;
  v7 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  v8 = v7->lpVtbl;
  v36 = v7;
  v28 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 133);
  v9 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v8->BltFast(v36, v6, 13, v9, (LPRECT)v28, 0);
  do
  {
    v6 -= 9;
    digit = score1 % 0xA;
    score1 /= 0xA;
    v14 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pScoreManagerSurface);
    v15 = v14->lpVtbl;
    v35 = v14;
    v29 = CBitmapRects::GetBitmapRect(g_CBitmapRects, digit + 123);
    v16 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    v15->BltFast(v35, v6, 13, v16, (LPRECT)v29, 0);
  }
  while ( score1 );
  v13 = v6 - 9;
  v18 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  v19 = v18->lpVtbl;
  v35 = v18;
  v30 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 122);
  tmpSurf = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v19->BltFast(v35, v13, 13, tmpSurf, (LPRECT)v30, 0);
  v17 = v13 - 20;
  score2 = *((uint32_t *)v37 + 10);
  v35 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  v19 = v35->lpVtbl;
  v31 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 121);
  tmpSurf = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v19->BltFast(v35, v17, 13, tmpSurf, (LPRECT)v31, 0);
  do
  {
    v17 -= 9;
    digit = score2 % 0xA;
    score2 /= 0xA;
    v22 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pScoreManagerSurface);
    v23 = v22->lpVtbl;
    v36 = v22;
    v32 = CBitmapRects::GetBitmapRect(g_CBitmapRects, digit + 111);
    v24 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    v23->BltFast(v36, v17, 13, v24, (LPRECT)v32, 0);
  }
  while ( score2 );
  v25 = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pScoreManagerSurface);
  v26 = v25->lpVtbl;
  v35 = v25;
  v33 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 110);
  tmpSurf = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v26->BltFast(v35, v17 - 9, 13, tmpSurf, (LPRECT)v33, 0);
  AddDisplayUpdateRect((struct tagRECT *)((char*)v37 + 20));
  v39 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v34)->~CLogBlock();
}
