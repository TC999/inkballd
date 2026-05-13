#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern void* g_pCGameBoard;

void GetBoardRect(struct tagRECT* a1)
{
    uint8_t v1[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v1), "GetBoardRect", 0);
    a1->left = *((uint32_t*)g_pCGameBoard + 2467);
    a1->top = *((uint32_t*)g_pCGameBoard + 2468);
    a1->right = *((uint32_t*)g_pCGameBoard + 2465);
    a1->bottom = *((uint32_t*)g_pCGameBoard + 2466);
    reinterpret_cast<Helpers::CLogBlock*>(v1)->~CLogBlock();
}
