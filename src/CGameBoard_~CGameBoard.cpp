//----- (01009A0D) --------------------------------------------------------
void __thiscall CGameBoard::~CGameBoard(CGameBoard *this)
{
  CBallManager *v2; // ecx
  CScoreManager *v3; // ecx
  CInk **v4; // esi
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::~CGameBoard", 0);
  v2 = (CBallManager *)*((_DWORD *)this + 2476);
  v6 = 0;
  if ( v2 )
  {
    CBallManager::`scalar deleting destructor'(v2, 1);
    *((_DWORD *)this + 2476) = 0;
  }
  v3 = (CScoreManager *)*((_DWORD *)this + 2477);
  if ( v3 )
  {
    CScoreManager::`scalar deleting destructor'(v3, 1);
    *((_DWORD *)this + 2477) = 0;
  }
  if ( *((_DWORD *)this + 2478) )
  {
    operator delete(*((void **)this + 2478));
    *((_DWORD *)this + 2478) = 0;
  }
  if ( *((_DWORD *)this + 2479) )
  {
    operator delete(*((void **)this + 2479));
    *((_DWORD *)this + 2479) = 0;
  }
  if ( g_pGamePiecesSurface )
  {
    CSurface::`scalar deleting destructor'(g_pGamePiecesSurface, 1);
    g_pGamePiecesSurface = 0;
  }
  CGameBoard::FreeDirectDraw(this);
  v4 = (CInk **)((char *)this + 9924);
  if ( *v4 )
  {
    CInk::`scalar deleting destructor'(*v4, 1);
    *v4 = 0;
  }
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
