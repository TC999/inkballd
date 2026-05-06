int __stdcall UpdateBoardTile(struct tagRECT **a1)
{
  int v1; // eax
  struct IDirectDrawSurface7 *BoardBuffer; // ebx
  int (__stdcall **p_Blt)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // esi
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  int v5; // esi
  struct tagRECT *v7; // [esp-Ch] [ebp-44h]
  struct tagRECT v8; // [esp+10h] [ebp-28h] BYREF
  _BYTE v9[8]; // [esp+20h] [ebp-18h] BYREF
  int v10[3]; // [esp+28h] [ebp-10h] BYREF
  int v11; // [esp+34h] [ebp-4h]

  v10[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "UpdateBoardTile", v10);
  v11 = 0;
  CBoardObject::GetBoundingRect((CBoardObject *)a1, &v8);
  if ( *((_DWORD *)g_pCGameBoard + 2475) == 1 )
  {
    v1 = CDisplay::BltToBoard(
           g_pDisplay,
           (unsigned __int64)*((double *)a1 + 1),
           (unsigned __int64)*((double *)a1 + 2),
           g_pGamePiecesSurface,
           a1[8]);
  }
  else
  {
    BoardBuffer = CDisplay::GetBoardBuffer(g_pDisplay);
    v7 = a1[8];
    p_Blt = (int (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&BoardBuffer->lpVtbl->Blt;
    DDrawSurface = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    v1 = (*p_Blt)(BoardBuffer, &v8, DDrawSurface, v7, 0, 0);
  }
  v10[0] = v1;
  if ( v1 >= 0 )
  {
    v10[0] = BltBoardToInk(&v8);
    if ( v10[0] >= 0 )
      v10[0] = CDisplay::BltInk(g_pDisplay, &v8);
  }
  v5 = v10[0];
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
  return v5;
}
