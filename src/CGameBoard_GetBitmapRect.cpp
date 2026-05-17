//----- (01008626) --------------------------------------------------------
char * CGameBoard::GetBitmapRect(CGameBoard *self, int a1)
{
  char *BitmapRect; // eax
  char *v2; // esi
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::GetBitmapRect", 0);
  v5 = 0;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, a1);
  v5 = -1;
  v2 = BitmapRect;
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
  return v2;
}
