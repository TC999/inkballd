#include "global_types.h"
#include <cstdint>
#include <windows.h>
#include <new>

int __stdcall SearchBoardList(wchar_t* board_name, uint8_t* output_buffer, int board_count, void* board_collection_ptr, int* result)
{
    uint8_t* board_data_ptr;
    uint16_t board_size_high;
    size_t board_size;
    int search_result;
    HWND main_window_hwnd;
    uint8_t log_buffer[8];
    wchar_t* search_name;
    void* source_data;
    int board_index;
    WCHAR window_title[518];
    int flag;

    search_name = board_name;
    source_data = output_buffer;
    BoardCollection* board_collection = static_cast<BoardCollection*>(board_collection_ptr);
    new (&log_buffer) Helpers::CLogBlock(&log_buffer, "SearchBoardList", 0);
    flag = 0;
    board_index = 0;
    
    if (board_count <= 0)
    {
LABEL_5:
        search_result = 0;
    }
    else
    {
        while (true)
        {
            if (!Helpers::__wcsicmp(search_name, board_collection->board_name))
            {
                board_data_ptr = (uint8_t*)&g_BoardData + board_collection->board_data_offset;
                board_size_high = *board_data_ptr++ << 8;
                board_size = *board_data_ptr + board_size_high;
                Helpers::memcpy(source_data, board_data_ptr + 1, board_size);
                if (board_size <= 0x1000)
                    break;
            }
            ++board_index;
            board_collection = (BoardCollection*)((uint8_t*)board_collection + 516);
            if (board_index >= board_count)
                goto LABEL_5;
        }
        
        Helpers::memcpy(&g_pLastLoadedLevel, source_data, board_size);
        *result = -1;
        Helpers::memset(window_title, 0, 1024);
        Helpers::LoadStringW((HINSTANCE)0, (HINSTANCE)0x3A98, window_title, (uint16_t*)0x200, 0, (int*)0);
        main_window_hwnd = ::GetMainWindowHwnd();
        SetWindowTextW(main_window_hwnd, window_title);
        search_result = 1;
    }
    
    flag = -1;
    ((Helpers::CLogBlock*)&log_buffer)->~CLogBlock();
    return search_result;
}
