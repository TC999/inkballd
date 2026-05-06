int __thiscall CGameBoard::Shadowize(CGameBoard *this, int a2, int a3, int a4, int a5)
{
  int v6; // ebx
  int v7; // eax
  int v8; // esi
  int v9; // eax
  struct IDirectDrawSurface7 *BoardBuffer; // ebx
  int (__stdcall **p_Blt)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edi
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  int v14; // [esp-Ch] [ebp-D0h]
  _DWORD v15[31]; // [esp+10h] [ebp-B4h] BYREF
  struct tagRECT v16; // [esp+8Ch] [ebp-38h] BYREF
  struct tagRECT v17; // [esp+9Ch] [ebp-28h] BYREF
  _BYTE v18[8]; // [esp+ACh] [ebp-18h] BYREF
  int v19[3]; // [esp+B4h] [ebp-10h] BYREF
  int v20; // [esp+C0h] [ebp-4h]

  v6 = 0;
  v19[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CGameBoard::Shadowize", v19);
  v20 = 0;
  memset(v15, 0, sizeof(v15));
  v7 = a4;
  v15[0] = 124;
  if ( a4 >= a5 )
    goto LABEL_11;
  while ( a2 >= a3 )
  {
    if ( ++v7 >= a5 )
      goto LABEL_11;
  }
  v8 = *((_DWORD *)this + a2 + v7 * *((_DWORD *)this + 2469) + 721);
  CBoardObject::GetBoundingRect((CBoardObject *)v8, &v16);
  if ( *((_DWORD *)this + 2475) != 1 )
  {
    CBoardObject::GetBoundingRect((CBoardObject *)v8, &v17);
    BoardBuffer = CDisplay::GetBoardBuffer(g_pDisplay);
    v14 = *(_DWORD *)(v8 + 32);
    p_Blt = (int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&BoardBuffer->lpVtbl->Blt;
    DDrawSurface = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    v9 = (*p_Blt)(BoardBuffer, &v17, DDrawSurface, v14, 0, 0);
    v19[0] = v9;
    if ( v9 < 0 )
      goto LABEL_7;
    v6 = 0;
LABEL_11:
    v19[0] = 0;
    goto LABEL_8;
  }
  v9 = CDisplay::BltToBoard(
         g_pDisplay,
         (unsigned __int64)*(double *)(v8 + 8),
         (unsigned __int64)*(double *)(v8 + 16),
         g_pGamePiecesSurface,
         *(struct tagRECT **)(v8 + 32));
  v19[0] = v9;
  if ( v9 >= 0 )
    goto LABEL_11;
LABEL_7:
  v6 = v9;
LABEL_8:
  v20 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
  return v6;
}
