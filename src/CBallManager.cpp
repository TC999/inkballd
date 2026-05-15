#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <new>
#include <exception>
#include <windows.h>
#include <cstddef>

extern "C" {
    extern void* g_pBallManagerSurface;
    extern void* g_pGamePiecesSurface;
    extern void* g_CBitmapRects;
}

extern "C" void* CBall_func(int a1, int a2, int a3, int a4, int a5);

CBallManager::CBallManager()
{
    void* ball_mem;
    CBall* ball;
    char* bitmap_rect;
    uint8_t log_buffer[8];
    void* temp_ptr;
    int error_code;
    int ball_index;
    int log_state;

    *((uint32_t*)this + 0) = 0;
    error_code = 0;
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBallManager::CBallManager", error_code);
    *((uint32_t*)this + 4) = 104;
    *((uint32_t*)this + 8) = 104;
    log_state = 0;
    *((uint32_t*)this + 1) = 0;
    *((uint32_t*)this + 2) = 0;
    *((uint32_t*)this + 3) = 42;
    *((uint32_t*)this + 5) = 0;
    *((uint32_t*)this + 6) = 0;
    *((uint32_t*)this + 7) = 42;
    if (CBallManager::InitSurface(this) < 0)
    {
        // [TODO] exception handling — decompiled CxxThrowException pattern
    }
    CSurface::GetDDrawSurface(reinterpret_cast<CSurface*>(g_pBallManagerSurface));
    ball_index = 0;
    bitmap_rect = CBitmapRects::GetBitmapRect(reinterpret_cast<CBitmapRects*>(g_CBitmapRects), 106);
    CSurface::GetDDrawSurface(reinterpret_cast<CSurface*>(g_pGamePiecesSurface));
    error_code = 0;
    *((uint32_t*)this + 9) = 0;
    *((uint32_t*)this + 10) = 0;
    *((uint32_t*)this + 11) = 4;
    *((uint32_t*)this + 81) = 0;
    *((uint32_t*)this + 82) = 150;
    *((uint32_t*)this + 83) = 150;
    *((uint32_t*)this + 3) = 0;
    *((uint32_t*)this + 4) = 0;
    ball_index = 0;
    log_state = 1;
    while (ball_index < 6)
    {
        ball_mem = operator new(0x1A8u);
        temp_ptr = ball_mem;
        log_state = 2;
        if (ball_mem)
            ball = reinterpret_cast<CBall*>(CBall_func(0, 0, 0, 0, 18));
        else
            ball = nullptr;
        log_state = 1;
        *((uintptr_t*)((uint32_t*)this + 14 + ball_index)) = reinterpret_cast<uintptr_t>(ball);
        if (ball)
            CBall::AddRef(ball);
        ++ball_index;
    }
    *((uint32_t*)this + 5) = 0;
    memset(reinterpret_cast<char*>(this) + 84, 0, 0x484u);
    log_state = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
