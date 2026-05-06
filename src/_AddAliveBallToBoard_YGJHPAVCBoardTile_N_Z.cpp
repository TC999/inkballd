int __stdcall AddAliveBallToBoard(int a1, struct CBoardTile *a2, double a3)
{
  char *BitmapRect; // eax
  int v4; // esi
  struct tagPOINT v6; // [esp+18h] [ebp-24h] BYREF
  _BYTE v7[8]; // [esp+20h] [ebp-1Ch] BYREF
  int v8[4]; // [esp+28h] [ebp-14h] BYREF
  int v9; // [esp+38h] [ebp-4h]
  CBoardObject *v10; // [esp+48h] [ebp+Ch]

  v8[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "AddAliveBallToBoard", v8);
  v9 = 0;
  if ( CGameBoard::NumBallsOnBoard(g_pCGameBoard) >= 64 )
    DisplayBoardLoadMsg();
  CBoardObject::GetCenterPoint(a2, &v6);
  LOBYTE(v9) = 1;
  v10 = (CBoardObject *)operator new(0x1A8u);
  LOBYTE(v9) = 2;
  if ( v10 )
  {
    BitmapRect = CGameBoard::GetBitmapRect(a1 + 2);
    v4 = CBall::CBall((int)v10, (int)BitmapRect, a1, 1, *((_DWORD *)g_pCGameBoard + 2471));
  }
  else
  {
    v4 = 0;
  }
  v9 = 0;
  if ( v4 )
  {
    CBall::AddRef((CBall *)v4);
    *(_DWORD *)(v4 + 24) = *((_DWORD *)g_pCGameBoard + 2471);
    *(_DWORD *)(v4 + 28) = *((_DWORD *)g_pCGameBoard + 2471);
    *(double *)(v4 + 8) = (double)v6.x - (double)*((int *)g_pCGameBoard + 2471) * 0.5;
    *(double *)(v4 + 16) = (double)v6.y - 0.5 * (double)*((int *)g_pCGameBoard + 2471);
    CBallManager::SetBallSpeed(*((CBallManager **)g_pCGameBoard + 2476), (struct CBall *)v4, a3);
    *(_DWORD *)(v4 + 156) = 1;
    *(_DWORD *)(v4 + 160) = 1;
    CGameBoard::AddBall(g_pCGameBoard, (struct CBall *)v4);
    v9 = -1;
    v8[0] = 0;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
    return 0;
  }
  else
  {
    v9 = -1;
    v8[0] = -2147024882;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
    return -2147024882;
  }
}
