#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    namespace Helpers {
        class CLogBlock {
        public:
            CLogBlock(void* buffer, const char* message, int);
            ~CLogBlock();
        };
        extern int LoadStringW(HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, int nMaxCount, int* result);
    }
}

};

extern "C" void* g_BoardData; // Global board data
extern "C" void* g_pLastLoadedLevel; // Global last loaded level
extern "C" BOARDHIST g_bhPrevBoards; // Global board history
extern "C" int iBoardListCount; // Global board list count
extern "C" void* paBoardList; // Global board list array
extern "C" int GetRandomNumber(int max_value);
extern "C" int fPrevSeen(int value, BOARDHIST* history, int max_size);
extern "C" HWND GetMainWindowHwnd();
extern "C" void* memcpy(void* dest, const void* src, size_t count);

void __thiscall CBoardManager::LoadRandomBoardFromResources(CBoardManager *this, uint8_t* output_buffer, int* result)
{
    int random_number;
    uint8_t* board_data_ptr;
    uint16_t board_size_high;
    size_t board_size;
    HWND main_window_hwnd;
    int* temp_result;
    uint8_t log_buffer[8];
    WCHAR window_title[518];
    int flag;

    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardManager::LoadRandomBoardFromResources", 0);
    flag = 0;
    
    do
    {
        random_number = GetRandomNumber(iBoardListCount);
    }
    while (fPrevSeen(random_number, &g_bhPrevBoards, iBoardListCount));
    
    board_data_ptr = reinterpret_cast<uint8_t*>(&g_BoardData) + 
                     *reinterpret_cast<uint32_t*>(reinterpret_cast<uint8_t*>(paBoardList) + 129 * random_number);
    board_size_high = *board_data_ptr++ << 8;
    board_size = *board_data_ptr + board_size_high;
    Helpers::memcpy(output_buffer, board_data_ptr + 1, board_size);
    
    if (board_size <= 0x1000)
        Helpers::memcpy(&g_pLastLoadedLevel, output_buffer, board_size);
    
    *result = -1;
    temp_result = nullptr;
    Helpers::LoadStringW(nullptr, 0x3A98, window_title, 0x200, temp_result);
    main_window_hwnd = GetMainWindowHwnd();
    SetWindowTextW(main_window_hwnd, window_title);
    
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
}
