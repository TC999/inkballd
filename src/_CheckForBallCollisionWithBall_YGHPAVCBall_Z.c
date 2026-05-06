int __stdcall CheckForBallCollisionWithBall(struct CBall *a1)
{
  CGameBoard *v1; // ecx
  int v2; // esi
  bool v3; // cc
  struct CBall *Ball; // eax
  _BYTE v6[8]; // [esp+10h] [ebp-18h] BYREF
  int v7; // [esp+18h] [ebp-10h]
  int v8; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v6, "CheckForBallCollisionWithBall", 0);
  v1 = g_pCGameBoard;
  v2 = 0;
  v3 = *((_DWORD *)g_pCGameBoard + 656) <= 0;
  v8 = 0;
  v7 = 0;
  if ( !v3 )
  {
    do
    {
      if ( v2 != *((_DWORD *)a1 + 41) )
      {
        Ball = CGameBoard::GetBall(v1, v2);
        if ( *((_DWORD *)Ball + 39) )
          v7 = CBall::Collide(a1, Ball);
      }
      v1 = g_pCGameBoard;
      ++v2;
    }
    while ( v2 < *((_DWORD *)g_pCGameBoard + 656) );
  }
  v8 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v6);
  return v7;
}
