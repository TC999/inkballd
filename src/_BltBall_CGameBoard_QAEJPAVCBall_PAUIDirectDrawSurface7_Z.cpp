// [COMPLEX] COM (IDirectDrawSurface7), undeclared globals — left wrapped
#if 0
#include "global_types.h"
#include <cstdint>
#include <windows.h>
int CGameBoard_BltBall(CGameBoard* self, struct tagRECT **a2, struct IDirectDrawSurface7 *a3)
{
  int v5;
  int v6;
  uint8_t v10[8];
  int v11[3];
  int v12;

  v11[0] = 0;
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v10), "CGameBoard::BltBall", 0);
  v12 = 0;
  CBoardObject::GetBoundingRect((CBoardObject *)a2, &v9);
  lpVtbl = a3->lpVtbl;
  v8 = a2[8];
  DDrawSurface = CSurface::GetDDrawSurface(g_pGamePiecesSurface);
  v5 = lpVtbl->Blt(a3, &v9, DDrawSurface, v8, 0x8000, 0);
  v12 = -1;
  v11[0] = v5;
  v6 = v5;
  reinterpret_cast<Helpers::CLogBlock*>(v10)->~CLogBlock();
  return v6;
}

#endif