#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
}

extern "C" int SearchBoardList(wchar_t* board_name, uint8_t* output_buffer, int board_count, void* board_collection, int* result);
extern "C" int iBoardCollectionsCount; // Global board collections count
extern "C" int* iBoardCounts; // Global board counts array
extern "C" void** pBoardCollections; // Global board collections array

int LoadBoardFromResources_CBoardManager(CBoardManager *self,
    wchar_t* board_name,
    uint8_t* output_buffer,
    int* result)
{
    int collection_index;
    int search_result;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(&log_buffer), "CBoardManager::LoadBoardFromResources", 0);
    flag = 0;
    collection_index = 0;
    search_result = 0;
    
    do
    {
        if (collection_index >= iBoardCollectionsCount)
            break;
        
        int* current_board_count = &iBoardCounts[collection_index];
        void* current_board_collection = pBoardCollections[collection_index];
        search_result = SearchBoardList(board_name, output_buffer, *current_board_count, current_board_collection, result);
        ++collection_index;
    }
    while (!search_result);
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
    return search_result;
}
