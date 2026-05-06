void __thiscall CBallManager::DrawToSurface(CBallManager *this)
{
  struct IDirectDrawSurface7 *DDrawSurface; // edi
  struct IDirectDrawSurface7Vtbl *lpVtbl; // esi
  struct IDirectDrawSurface7 *v4; // eax
  CBoardObject **v5; // edi
  char *v6; // eax
  struct IDirectDrawSurface7 *v7; // eax
  struct IDirectDrawSurface7Vtbl *v8; // esi
  CBoardObject *v9; // edi
  char *BitmapRect; // [esp-Ch] [ebp-60h]
  struct tagRECT v11; // [esp+10h] [ebp-44h] BYREF
  int v12; // [esp+20h] [ebp-34h]
  int v13; // [esp+24h] [ebp-30h]
  int v14; // [esp+28h] [ebp-2Ch]
  int v15; // [esp+2Ch] [ebp-28h]
  _BYTE v16[8]; // [esp+30h] [ebp-24h] BYREF
  struct IDirectDrawSurface7 *v17; // [esp+38h] [ebp-1Ch]
  CBallManager *v18; // [esp+3Ch] [ebp-18h]
  struct tagRECT *v19; // [esp+40h] [ebp-14h]
  int i; // [esp+44h] [ebp-10h]
  int v21; // [esp+50h] [ebp-4h]

  v18 = this;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CBallManager::DrawToSurface", 0);
  v21 = 0;
  DDrawSurface = CSurface::GetDDrawSurface(g_pBallManagerSurface);
  lpVtbl = DDrawSurface->lpVtbl;
  v19 = (struct tagRECT *)((char *)this + 20);
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 106);
  v4 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  lpVtbl->Blt(DDrawSurface, v19, v4, (LPRECT)BitmapRect, 0, 0);
  for ( i = 0; i < 6; ++i )
  {
    v5 = (CBoardObject **)((char *)v18 + 4 * i + 56);
    if ( *((_DWORD *)*v5 + 39) && (i || !*((_DWORD *)v18 + 13)) )
    {
      CBoardObject::GetBoundingRect(*v5, &v11);
      v6 = CBitmapRects::GetBitmapRect(g_CBitmapRects, *((_DWORD *)*v5 + 11) + 12);
      v12 = *(_DWORD *)v6;
      v13 = *((_DWORD *)v6 + 1);
      v14 = *((_DWORD *)v6 + 2);
      v15 = *((_DWORD *)v6 + 3);
      if ( v11.left < 104 )
      {
        if ( v11.right > 104 )
          v14 += 104 - v11.right;
        v7 = CSurface::GetDDrawSurface(g_pBallManagerSurface);
        v8 = v7->lpVtbl;
        v9 = *v5;
        v17 = v7;
        CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        ((void (__stdcall *)(struct IDirectDrawSurface7 *, _DWORD))v8->BltFast)(
          v17,
          (unsigned __int64)*((double *)v9 + 1));
      }
    }
  }
  AddDisplayUpdateRect(v19);
  v21 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
}
