CGameManager *__thiscall CGameManager::CGameManager(CGameManager *this, HWND a2)
{
  _DWORD *v3; // ecx
  CGameBoard *v4; // eax
  _BYTE v6[8]; // [esp+10h] [ebp-1Ch] BYREF
  void *v7; // [esp+18h] [ebp-14h]
  int v8; // [esp+28h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CGameManager::CGameManager", 0);
  v8 = 1;
  g_pCGameBoard = 0;
  v3 = operator new(0x26C8u);
  v7 = v3;
  LOBYTE(v8) = 2;
  if ( v3 )
    v4 = (CGameBoard *)CGameBoard::CGameBoard(v3, a2, (void *)1);
  else
    v4 = 0;
  g_pCGameBoard = v4;
  *((_DWORD *)this + 4) = 0;
  *((_DWORD *)this + 1) = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 0;
  CGameManager::UpdateTime(this);
  v8 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return this;
}
