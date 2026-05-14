#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

void __stdcall DispError(HWND hWnd, HINSTANCE uID, HINSTANCE a3)
{
    uint8_t v5[8];
    WCHAR Text[4096] = { 0 };
    WCHAR Caption[64] = { 0 };

    Helpers::CLogBlock::CLogBlock(
        reinterpret_cast<Helpers::CLogBlock*>(v5), "DispError", 0);

    HINSTANCE hInst = GetModuleHandleW(NULL);

    // 直接调用标准 API
    int ret1 = LoadStringW(hInst, (UINT)uID, Caption, 64);
    int ret2 = LoadStringW(hInst, (UINT)a3, Text, 4096);

    MessageBoxW(hWnd, Text, Caption, 0x10u);

    reinterpret_cast<Helpers::CLogBlock*>(v5)->~CLogBlock();
}
