//----- (01008BE4) --------------------------------------------------------
int __thiscall CGameBoard::BltBoardToInk(CGameBoard *this, struct tagRECT *a2, int a3)
{
  int v3; // esi
  _BYTE v5[8]; // [esp+10h] [ebp-18h] BYREF
  int v6[3]; // [esp+18h] [ebp-10h] BYREF
  int v7; // [esp+24h] [ebp-4h]

  v6[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CGameBoard::BltBoardToInk", v6);
  v7 = 0;
  CDisplay::ClearInk(g_pDisplay, a2, a3);
  v3 = v6[0];
  v7 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v3;
}
