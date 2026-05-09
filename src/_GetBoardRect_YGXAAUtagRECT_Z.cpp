#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
void __stdcall GetBoardRect(struct tagRECT *a1)
{
  uint8_t v1[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "GetBoardRect", 0);
  a1->left = *((uint32_t *)g_pCGameBoard + 2467);
  a1->top = *((uint32_t *)g_pCGameBoard + 2468);
  a1->right = *((uint32_t *)g_pCGameBoard + 2465);
  a1->bottom = *((uint32_t *)g_pCGameBoard + 2466);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
