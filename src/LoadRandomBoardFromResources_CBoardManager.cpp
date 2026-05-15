#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern int iBoardListCount;
extern void* paBoardList;

void LoadRandomBoardFromResources_CBoardManager(CBoardManager *self, uint8_t* output_buffer, int* result)
{
    int random_number;
    uint8_t* board_data_ptr;
    uint16_t board_size_high;
    size_t board_size;
    HWND main_window_hwnd;
    WCHAR window_title[518];
    uint8_t log_buffer[8];
    int flag;

    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)&log_buffer, "CBoardManager::LoadRandomBoardFromResources", 0);
    flag = 0;
    
    do
    {
        random_number = GetRandomNumber(iBoardListCount);
    }
    while (fPrevSeen(&g_bhPrevBoards, random_number));
    
    board_data_ptr = (uint8_t*)&g_BoardData + 
                     *(uint32_t*)((uint8_t*)paBoardList + 129 * random_number);
    board_size_high = *board_data_ptr++ << 8;
    board_size = *board_data_ptr + board_size_high;
    memcpy(output_buffer, board_data_ptr + 1, board_size);
    
    if (board_size <= 0x1000)
        memcpy(&g_pLastLoadedLevel, output_buffer, board_size);
    
    *result = -1;
    Helpers::LoadStringW((HINSTANCE)0, (HINSTANCE)0x3A98, window_title, (uint16_t*)0x200, 0, (int*)0);
    main_window_hwnd = GetMainWindowHwnd();
    SetWindowTextW(main_window_hwnd, window_title);
    
    flag = -1;
    ((Helpers::CLogBlock*)&log_buffer)->~CLogBlock();
}
