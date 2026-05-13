#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void CGameBoard::AddDisplayUpdateRect(CGameBoard* self, struct tagRECT *a2)
{
  uint32_t v3;
  uint8_t v4[8];

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CGameBoard::AddDisplayUpdateRect", 0);
  v3 = *((uint32_t *)self + 1018);
  if ( v3 < 0x121 )
  {
    *((uint32_t *)self + 4 * v3 + 1019) = a2->left;
    *((uint32_t *)self + 4 * *((uint32_t *)self + 1018) + 1021) = a2->right;
    *((uint32_t *)self + 4 * *((uint32_t *)self + 1018) + 1020) = a2->top;
    *((uint32_t *)self + 4 * (*((uint32_t *)self + 1018))++ + 1022) = a2->bottom;
  }
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
