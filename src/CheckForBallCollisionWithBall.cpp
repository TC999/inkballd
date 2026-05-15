// [COMPLEX] Undeclared CBall members, CBall::Collide — left wrapped
#include "global_types.h"
#include <cstdint>
#include <windows.h>
int __stdcall CheckForBallCollisionWithBall(CBall* a1)
{
  CGameBoard *v1;
  int v2;
  bool v3;
  CBall* Ball;
  uint8_t v6[8];
  int v7;
  int v8;

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v6), "CheckForBallCollisionWithBall", 0);
  v1 = g_pCGameBoard;
  v2 = 0;
  v3 = *((uint32_t *)g_pCGameBoard + 656) <= 0;
  v8 = 0;
  v7 = 0;
  if ( !v3 )
  {
    do
    {
      if ( v2 != *((uint32_t *)a1 + 41) )
      {
        Ball = CGameBoard::GetBall(v1, v2);
        if ( *((uint32_t *)Ball + 39) )
          v7 = CBall::Collide(a1, Ball);
      }
      v1 = g_pCGameBoard;
      ++v2;
    }
    while ( v2 < *((uint32_t *)g_pCGameBoard + 656) );
  }
  v8 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v6)->~CLogBlock();
  return v7;
}
