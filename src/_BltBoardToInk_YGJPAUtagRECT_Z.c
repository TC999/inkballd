int __stdcall BltBoardToInk(struct tagRECT *a1)
{
  int v1; // eax
  int v2; // esi
  _BYTE v4[8]; // [esp+10h] [ebp-18h] BYREF
  int v5[3]; // [esp+18h] [ebp-10h] BYREF
  int v6; // [esp+24h] [ebp-4h]

  v5[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "BltBoardToInk", v5);
  v6 = 0;
  v1 = CGameBoard::BltBoardToInk(g_pCGameBoard, a1, 0);
  v5[0] = v1;
  if ( v1 >= 0 )
    goto LABEL_6;
  if ( v1 == -2005532222 )
  {
    CGameBoard::RestoreSurfaces((CScoreManager **)g_pCGameBoard);
LABEL_6:
    v2 = v5[0];
    goto LABEL_4;
  }
  v2 = v1;
LABEL_4:
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
