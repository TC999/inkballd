#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void* g_BoardData;

CBoardManager::CBoardManager()
{
    HRSRC resource_handle;
    HGLOBAL resource_data;
    size_t resource_size;
    const void* locked_resource;
    uint8_t log_buffer[8];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardManager::CBoardManager", 0);
    flag = 0;
    
    resource_handle = FindResourceW(nullptr, MAKEINTRESOURCEW(0x4E21), L"IKL");
    
    if (resource_handle)
    {
        resource_data = LoadResource(nullptr, resource_handle);
        if (resource_data)
        {
            resource_size = SizeofResource(nullptr, resource_handle);
            locked_resource = LockResource(resource_data);
            if (resource_size <= 0x51C84)
            {
                if (locked_resource)
                    memcpy(&g_BoardData, locked_resource, resource_size);
            }
        }
    }
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}

CBoardManager::~CBoardManager()
{
    uint32_t current_difficulty;
    uint8_t log_buffer[16];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardManager::~CBoardManager", 0);
    current_difficulty = *((uint32_t*)self + 1);
    flag = 0;

    CRegistryManager::WriteDifficulty(reinterpret_cast<CRegistryManager*>(&g_CRegistryManager), current_difficulty);

    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}