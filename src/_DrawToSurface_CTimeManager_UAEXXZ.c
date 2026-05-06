void __thiscall CTimeManager::DrawToSurface(CTimeManager *this)
{
  unsigned int v2; // eax
  unsigned int v3; // edi
  struct IDirectDrawSurface7 *v4; // eax
  unsigned int v5; // edx
  struct IDirectDrawSurface7 *v6; // eax
  char *v7; // eax
  char *v8; // eax
  LONG v9; // ecx
  LONG v10; // eax
  char *v11; // eax
  char *v12; // ecx
  bool v13; // zf
  struct IDirectDrawSurface7 *v14; // eax
  struct IDirectDrawSurface7 *v15; // eax
  char *v16; // eax
  char *v17; // eax
  LONG v18; // ecx
  LONG v19; // eax
  struct IDirectDrawSurface7 *v20; // eax
  char *v21; // eax
  char *v22; // eax
  LONG v23; // ecx
  LONG v24; // eax
  char *v25; // eax
  struct IDirectDrawSurface7 *v26; // ebx
  void (__stdcall **v27)(struct IDirectDrawSurface7 *, unsigned int, unsigned int, struct IDirectDrawSurface7 *, char *, _DWORD); // edi
  struct IDirectDrawSurface7 *v28; // eax
  char *BitmapRect; // [esp-8h] [ebp-58h]
  char *v30; // [esp-8h] [ebp-58h]
  char *v31; // [esp-8h] [ebp-58h]
  char *v32; // [esp-8h] [ebp-58h]
  char *v33; // [esp-8h] [ebp-58h]
  struct tagRECT v34; // [esp+10h] [ebp-40h] BYREF
  _BYTE v35[8]; // [esp+20h] [ebp-30h] BYREF
  char *v36; // [esp+28h] [ebp-28h]
  char *p_BltFast; // [esp+2Ch] [ebp-24h]
  unsigned int DDrawSurface; // [esp+30h] [ebp-20h]
  struct IDirectDrawSurface7 *v39; // [esp+34h] [ebp-1Ch]
  struct IDirectDrawSurface7 *v40; // [esp+38h] [ebp-18h]
  unsigned int v41; // [esp+3Ch] [ebp-14h]
  unsigned int v42; // [esp+40h] [ebp-10h]
  int v43; // [esp+4Ch] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v35, "CTimeManager::DrawToSurface", 0);
  v2 = *((_DWORD *)this + 9) / 0x3E8u;
  v3 = *((_DWORD *)this + 3) - dwLeftDrawDif - 9;
  v43 = 0;
  v42 = v3;
  v40 = (struct IDirectDrawSurface7 *)v2;
  v41 = dwTopDrawLoc;
  DDrawSurface = (unsigned int)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v39 = (struct IDirectDrawSurface7 *)(*(_DWORD *)DDrawSurface + 28);
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, 158);
  v4 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  ((void (__stdcall *)(unsigned int, unsigned int, unsigned int, struct IDirectDrawSurface7 *, char *, _DWORD))v39->lpVtbl)(
    DDrawSurface,
    v3,
    v41,
    v4,
    BitmapRect,
    0);
  if ( (unsigned int)v40 <= 0x3E7 )
  {
    DDrawSurface = (unsigned int)v40;
    v40 = (struct IDirectDrawSurface7 *)&unk_10B06A4;
    while ( 1 )
    {
      v5 = DDrawSurface % 0xA;
      DDrawSurface /= 0xAu;
      v42 -= dwTimeDigitWidth;
      if ( *((_DWORD *)this + 12) )
      {
        v13 = v40->lpVtbl == (struct IDirectDrawSurface7Vtbl *)(v5 + 146);
        v39 = (struct IDirectDrawSurface7 *)(v5 + 146);
        if ( !v13 )
        {
          p_BltFast = (char *)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
          v36 = (char *)(*(_DWORD *)p_BltFast + 28);
          v31 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (int)v39);
          v14 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
          (*(void (__stdcall **)(char *, unsigned int, unsigned int, struct IDirectDrawSurface7 *, char *, _DWORD))v36)(
            p_BltFast,
            v42,
            v41,
            v14,
            v31,
            0);
          v15 = v39;
          v40->lpVtbl = (struct IDirectDrawSurface7Vtbl *)v39;
          v34.left = v42 + *((_DWORD *)this + 1);
          v16 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (int)v15);
          v36 = (char *)(v34.left + *((_DWORD *)v16 + 2));
          v17 = CBitmapRects::GetBitmapRect(g_CBitmapRects, (int)v39);
          v18 = (LONG)&v36[-*(_DWORD *)v17];
          v19 = v41 + *((_DWORD *)this + 2);
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
        p_BltFast = (char *)&v39->lpVtbl->BltFast;
        v30 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v6 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
        (*(void (__stdcall **)(struct IDirectDrawSurface7 *, unsigned int, unsigned int, struct IDirectDrawSurface7 *, char *, _DWORD))p_BltFast)(
          v39,
          v42,
          v41,
          v6,
          v30,
          0);
        v40->lpVtbl = (struct IDirectDrawSurface7Vtbl *)157;
        v34.left = v42 + *((_DWORD *)this + 1);
        v7 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        p_BltFast = (char *)(v34.left + *((_DWORD *)v7 + 2));
        v8 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v9 = (LONG)&p_BltFast[-*(_DWORD *)v8];
        v10 = v41 + *((_DWORD *)this + 2);
        v34.right = v9;
        v34.top = v10;
        p_BltFast = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157) + 12;
        v11 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 157);
        v12 = p_BltFast;
LABEL_8:
        v34.bottom = v34.top + *(_DWORD *)v12 - *((_DWORD *)v11 + 1);
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
      v36 = (char *)CSurface::GetDDrawSurface(g_pTimeManagerSurface);
      p_BltFast = (char *)(*(_DWORD *)v36 + 28);
      v32 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v20 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
      (*(void (__stdcall **)(char *, unsigned int, unsigned int, struct IDirectDrawSurface7 *, char *, _DWORD))p_BltFast)(
        v36,
        v42,
        v41,
        v20,
        v32,
        0);
      v39->lpVtbl = (struct IDirectDrawSurface7Vtbl *)156;
      v34.left = v42 + *((_DWORD *)this + 1);
      v21 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v36 = (char *)(v34.left + *((_DWORD *)v21 + 2));
      v22 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v23 = (LONG)&v36[-*(_DWORD *)v22];
      v24 = v41 + *((_DWORD *)this + 2);
      v34.right = v23;
      v34.top = v24;
      v36 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156) + 12;
      v25 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 156);
      v34.bottom = v34.top + *(_DWORD *)v36 - *((_DWORD *)v25 + 1);
      AddDisplayUpdateRect(&v34);
    }
    ++v39;
  }
  while ( (int)v39 < (int)&Src );
LABEL_15:
  v42 -= 9;
  v26 = CSurface::GetDDrawSurface(g_pTimeManagerSurface);
  v27 = (void (__stdcall **)(struct IDirectDrawSurface7 *, unsigned int, unsigned int, struct IDirectDrawSurface7 *, char *, _DWORD))&v26->lpVtbl->BltFast;
  v33 = CBitmapRects::GetBitmapRect(g_CBitmapRects, 145);
  v28 = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  (*v27)(v26, v42, v41, v28, v33, 0);
  v43 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v35);
}
