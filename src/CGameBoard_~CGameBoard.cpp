//----- (01009A0D) --------------------------------------------------------
void CGameBoard_Dtor(CGameBoard *self, int flags)
{
  CBallManager *v2; // ecx
  CScoreManager *v3; // ecx
  CInk **v4; // esi
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::~CGameBoard", 0);
  v2 = (CBallManager *)*((_DWORD *)self + 2476);
  v6 = 0;
  if ( v2 )
  {
    delete v2;
    *((_DWORD *)self + 2476) = 0;
  }
  v3 = (CScoreManager *)*((_DWORD *)self + 2477);
  if ( v3 )
  {
    delete v3;
    *((_DWORD *)self + 2477) = 0;
  }
  if ( *((_DWORD *)self + 2478) )
  {
    operator delete(*((void **)self + 2478));
    *((_DWORD *)self + 2478) = 0;
  }
  if ( *((_DWORD *)self + 2479) )
  {
    operator delete(*((void **)self + 2479));
    *((_DWORD *)self + 2479) = 0;
  }
  if ( g_pGamePiecesSurface )
  {
    delete g_pGamePiecesSurface;
    g_pGamePiecesSurface = 0;
  }
  CGameBoard::FreeDirectDraw(self);
  v4 = (CInk **)((char *)self + 9924);
  if ( *v4 )
  {
    delete *v4;
    *v4 = 0;
  }
  v6 = -1;
  ((Helpers::CLogBlock *)v5)->~CLogBlock();
}
