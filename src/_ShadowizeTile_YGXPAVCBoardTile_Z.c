void __stdcall ShadowizeTile(struct CBoardTile *a1)
{
  _BYTE v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "ShadowizeTile", 0);
  v2 = 0;
  CGameBoard::ShadowizeTile((CInk **)g_pCGameBoard, a1, 0);
  v2 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
