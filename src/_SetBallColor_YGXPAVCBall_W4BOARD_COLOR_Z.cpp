void __stdcall SetBallColor(int a1, int a2)
{
  char *BitmapRect; // eax
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "SetBallColor", 0);
  v4 = 0;
  *(_DWORD *)(a1 + 44) = a2;
  BitmapRect = CGameBoard::GetBitmapRect(a2 + 2);
  v4 = -1;
  *(_DWORD *)(a1 + 32) = BitmapRect;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
