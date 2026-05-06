struct CBall *__stdcall GetBall(int a1)
{
  struct CBall *Ball; // eax
  struct CBall *v2; // esi
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "GetBall", 0);
  v5 = 0;
  Ball = CGameBoard::GetBall(g_pCGameBoard, a1);
  v5 = -1;
  v2 = Ball;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
