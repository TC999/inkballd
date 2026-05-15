//----- (0100825A) --------------------------------------------------------
void __thiscall CGameBoard::SetTile(CGameBoard *this, struct CBoardTile *a2)
{
  int v3; // eax
  struct IDirectDrawSurface7 *BoardBuffer; // ebx
  void (__stdcall **p_Blt)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD); // edi
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  int v7; // [esp-Ch] [ebp-40h]
  struct tagRECT v8; // [esp+10h] [ebp-24h] BYREF
  _BYTE v9[16]; // [esp+20h] [ebp-14h] BYREF
  int v10; // [esp+30h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CGameBoard::SetTile", 0);
  v3 = *((_DWORD *)a2 + 19) + *((_DWORD *)a2 + 20) * *((_DWORD *)this + 2469);
  v10 = 0;
  if ( v3 < 289 )
    *((_DWORD *)this + v3 + 721) = a2;
  if ( *((_DWORD *)this + 2475) == 1 )
  {
    CDisplay::BltToBoard(
      g_pDisplay,
      (unsigned __int64)*((double *)a2 + 1),
      (unsigned __int64)*((double *)a2 + 2),
      g_pGamePiecesSurface,
      *((struct tagRECT **)a2 + 8));
  }
  else
  {
    CBoardObject::GetBoundingRect(a2, &v8);
    BoardBuffer = CDisplay::GetBoardBuffer(g_pDisplay);
    v7 = *((_DWORD *)a2 + 8);
    p_Blt = (void (__stdcall **)(_DWORD, _DWORD, _DWORD, _DWORD, _DWORD, _DWORD))&BoardBuffer->lpVtbl->Blt;
    DDrawSurface = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    (*p_Blt)(BoardBuffer, &v8, DDrawSurface, v7, 0, 0);
  }
  v10 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
}
