#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include <new>

void CGameBoard::UpdateBounds(CGameBoard *self)
{
  uint8_t v1[16];
  int v2;

  new (v1) Helpers::CLogBlock(v1, "CGameBoard::UpdateBounds", 0);
  v2 = 0;
  CDisplay::UpdateBounds((CDisplay*)g_pDisplay);
  v2 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v1)->~CLogBlock();
}
