int __stdcall AddBallToBoard(int a1)
{
  char *BitmapRect; // eax
  CBall *v2; // esi
  _BYTE v4[8]; // [esp+10h] [ebp-20h] BYREF
  void *v5; // [esp+18h] [ebp-18h]
  int v6[4]; // [esp+1Ch] [ebp-14h] BYREF
  int v7; // [esp+2Ch] [ebp-4h]

  v6[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "AddBallToBoard", v6);
  v7 = 1;
  v5 = operator new(0x1A8u);
  LOBYTE(v7) = 2;
  if ( v5 )
  {
    BitmapRect = CGameBoard::GetBitmapRect(a1 + 2);
    v2 = (CBall *)CBall::CBall((int)v5, (int)BitmapRect, a1, 1, *((_DWORD *)g_pCGameBoard + 2471));
  }
  else
  {
    v2 = 0;
  }
  v7 = 0;
  if ( v2 )
  {
    CBall::AddRef(v2);
    *((_DWORD *)v2 + 6) = *((_DWORD *)g_pCGameBoard + 2471);
    *((_DWORD *)v2 + 7) = *((_DWORD *)g_pCGameBoard + 2471);
    *((_DWORD *)v2 + 39) = 0;
    *((_DWORD *)v2 + 40) = 0;
    CGameBoard::AddBall(g_pCGameBoard, v2);
    v7 = -1;
    v6[0] = 0;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
    return 0;
  }
  else
  {
    v7 = -1;
    v6[0] = -2147024882;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
    return -2147024882;
  }
}
