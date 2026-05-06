int __stdcall BallOnTile(struct CBoardTile *a1)
{
  int v1; // eax
  int v2; // esi
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "BallOnTile", 0);
  v5 = 0;
  v1 = CGameBoard::BallOnTile(g_pCGameBoard, a1);
  v5 = -1;
  v2 = v1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
