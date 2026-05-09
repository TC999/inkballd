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
        extern HINSTANCE FindResourceW(HINSTANCE hModule, LPCWSTR name, LPCWSTR type, int* result);
        extern HRSRC LoadResource(HINSTANCE hModule, HRSRC hRes, int* result);
        extern size_t SizeofResource(HINSTANCE hModule, HRSRC hRes);
        extern void* LockResource(HGLOBAL hMem);
        extern void* memcpy(void* dest, const void* src, size_t count);
    }
}

};

extern "C" void* g_BoardData; // Global board data

CBoardManager* __thiscall CBoardManager::CBoardManager(CBoardManager *this)
{
    HINSTANCE resource_instance;
    HRSRC resource_handle;
    void* resource_data;
    size_t resource_size;
    const void* locked_resource;
    int* temp_result1;
    int* temp_result2;
    uint8_t log_buffer[8];
    CBoardManager* instance;
    int flag;

    instance = this;
    Helpers::CLogBlock::CLogBlock(&log_buffer, "CBoardManager::CBoardManager", 0);
    flag = 0;
    
    temp_result1 = nullptr;
    resource_instance = Helpers::FindResourceW(nullptr, reinterpret_cast<LPCWSTR>(0x4E21), L"IKL", temp_result1);
    resource_handle = reinterpret_cast<HRSRC>(resource_instance);
    
    if (resource_instance)
    {
        temp_result2 = nullptr;
        resource_data = Helpers::LoadResource(nullptr, resource_instance, temp_result2);
        if (resource_data)
        {
            resource_size = Helpers::SizeofResource(nullptr, resource_handle);
            locked_resource = Helpers::LockResource(resource_data);
            if (resource_size <= 0x51C84)
            {
                if (locked_resource)
                    Helpers::memcpy(&g_BoardData, locked_resource, resource_size);
            }
        }
    }
    
    flag = -1;
    Helpers::CLogBlock::~CLogBlock(&log_buffer);
    return instance;
}
