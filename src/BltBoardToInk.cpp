#include "global_types.h"
#include <cstdint>
#include <windows.h>

int __stdcall BltBoardToInk(struct tagRECT* a1)
{
    uint8_t v4[8];
    int result;
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "BltBoardToInk", 0);
    result = CGameBoard::BltBoardToInk(g_pCGameBoard, a1, 0);
    reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
    return result;
}
