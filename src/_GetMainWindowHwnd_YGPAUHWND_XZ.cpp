#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern CGameBoard* g_pCGameBoard;

extern "C" { HWND __stdcall GetMainWindowHwnd()
{
    int v0;
    uint8_t v2[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v2), "GetMainWindowHwnd", 0);
    v0 = *((uint32_t*)((char*)g_pCGameBoard + 2480));
    reinterpret_cast<Helpers::CLogBlock*>(v2)->~CLogBlock();
    return (HWND)v0;
}}
