#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern void* g_CBitmapRects;
char* CGameBoard::GetBitmapRect(CGameBoard* self, int a1)
{
    char* BitmapRect;
    char* v2;
    uint8_t v4[16];
    int v5;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CGameBoard::GetBitmapRect", 0);
    v5 = 0;
    BitmapRect = (char*)CBitmapRects::GetBitmapRect(g_CBitmapRects, a1);
    v5 = -1;
    v2 = BitmapRect;
    reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
    return v2;
}
