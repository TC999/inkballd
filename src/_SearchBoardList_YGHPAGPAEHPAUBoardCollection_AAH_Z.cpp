#if 0
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
        extern int __wcsicmp(const wchar_t* string1, const wchar_t* string2);
        extern void* memcpy(void* dest, const void* src, size_t count);
        extern void* memset(void* dest, int value, size_t count);
        extern int LoadStringW(HINSTANCE hInstance, UINT uID, LPWSTR lpBuffer, int nMaxCount, int* result);
    }
}

};

extern "C" void* g_BoardData; // Global board data
extern "C" void* g_pLastLoadedLevel; // Global last loaded level

extern "C" HWND GetMainWindowHwnd();

int __stdcall SearchBoardList(wchar_t* board_name, uint8_t* output_buffer, int board_count, BoardCollection* board_collection, int* result)
{
    uint8_t* board_data_ptr;
    uint16_t board_size_high;
    size_t board_size;
    int search_result;
    HWND main_window_hwnd;
    int* temp_result;
    uint8_t log_buffer[8];
    wchar_t* search_name;
    void* source_data;
    int board_index;
    WCHAR window_title[518];
    int flag;

    search_name = board_name;
    source_data = output_buffer;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "SearchBoardList", 0);
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
                board_data_ptr = reinterpret_cast<uint8_t*>(&g_BoardData) + board_collection->board_data_offset;
                board_size_high = *board_data_ptr++ << 8;
                board_size = *board_data_ptr + board_size_high;
                Helpers::memcpy(source_data, board_data_ptr + 1, board_size);
                if (board_size <= 0x1000)
                    break;
            }
            ++board_index;
            board_collection = reinterpret_cast<BoardCollection*>(reinterpret_cast<uint8_t*>(board_collection) + 516);
            if (board_index >= board_count)
                goto LABEL_5;
        }
        
        Helpers::memcpy(&g_pLastLoadedLevel, source_data, board_size);
        *result = -1;
        Helpers::memset(window_title, 0, 1024);
        temp_result = nullptr;
        Helpers::LoadStringW(nullptr, 0x3A98, window_title, 0x200, temp_result);
        main_window_hwnd = GetMainWindowHwnd();
        SetWindowTextW(main_window_hwnd, window_title);
        search_result = 1;
    }
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return search_result;
}

#endif
