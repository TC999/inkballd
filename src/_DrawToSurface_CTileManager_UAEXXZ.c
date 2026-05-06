void __thiscall CTileManager::DrawToSurface(CTileManager *this)
{
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  struct IDirectDrawSurface7Vtbl *lpVtbl; // esi
  struct IDirectDrawSurface7 *v3; // eax
  struct IDirectDrawSurface7 *v4; // eax
  struct IDirectDrawSurface7Vtbl *v5; // esi
  struct IDirectDrawSurface7 *v6; // eax
  unsigned int v7; // edx
  struct IDirectDrawSurface7 *v8; // ebx
  void (__stdcall **p_BltFast)(struct IDirectDrawSurface7 *, int, int, struct IDirectDrawSurface7 *, char *, _DWORD); // esi
  struct IDirectDrawSurface7 *v10; // eax
  char *BitmapRect; // [esp-8h] [ebp-3Ch]
  char *v12; // [esp-8h] [ebp-3Ch]
  char *v13; // [esp-8h] [ebp-3Ch]
  _BYTE v14[8]; // [esp+10h] [ebp-24h] BYREF
  unsigned int v15; // [esp+18h] [ebp-1Ch]
  CTileManager *v16; // [esp+1Ch] [ebp-18h]
  struct IDirectDrawSurface7 *v17; // [esp+20h] [ebp-14h]
  int v18; // [esp+24h] [ebp-10h]
  int v19; // [esp+30h] [ebp-4h]

  v16 = this;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v14, "CTileManager::DrawToSurface", 0);
  v19 = 0;
  DDrawSurface = CSurface::GetDDrawSurface(g_pTileManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v17 = DDrawSurface;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 108);
  v3 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->BltFast(v17, 0, 0, v3, (LPRECT)BitmapRect, 0);
  if ( *((_DWORD *)v16 + 9) <= 0x63u )
  {
    v17 = (struct IDirectDrawSurface7 *)*((_DWORD *)v16 + 9);
    v18 = 14;
    do
    {
      v7 = (unsigned int)v17 % 0xA + 134;
      v17 = (struct IDirectDrawSurface7 *)((unsigned int)v17 / 0xA);
      v15 = v7;
      v8 = CSurface::GetDDrawSurface(g_pTileManagerSurface);
      p_BltFast = (void (__stdcall **)(struct IDirectDrawSurface7 *, int, int, struct IDirectDrawSurface7 *, char *, _DWORD))&v8->lpVtbl->BltFast;
      v13 = CBitmapRects::GetBitmapRect(g_CBitmapRects, v15);
      v10 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
      (*p_BltFast)(v8, v18, 18, v10, v13, 0);
      v18 -= 9;
    }
    while ( v17 );
  }
  else
  {
    v4 = CSurface::GetDDrawSurface(g_pTileManagerSurface);
    v5 = v4->lpVtbl;
    v17 = v4;
    v12 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 144);
    v6 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    v5->BltFast(v17, 14, 18, v6, (LPRECT)v12, 0);
  }
  AddDisplayUpdateRect((struct tagRECT *)((char *)v16 + 20));
  v19 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v14);
}
