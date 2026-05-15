#include "global_types.h"
#include <cstdint>

extern "C" void* CDisplay_vftable;

CDisplay::CDisplay()
{
    uint8_t log_buffer[8];

    *((uint32_t*)this + 0) = reinterpret_cast<uint32_t>(&CDisplay_vftable);
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CDisplay::CDisplay", 0);
    *((uint32_t*)this + 1) = 0;
    *((uint32_t*)this + 2) = 0;
    *((uint32_t*)this + 3) = 0;
    *((uint32_t*)this + 4) = 0;
    *((uint32_t*)this + 5) = 0;
    *((uint32_t*)this + 6) = 0;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}

CDisplay::~CDisplay()
{
    int destroy_result;
    uint8_t log_buffer[8];
    int error_code;
    int cleanup_flag;

    error_code = 0;
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CDisplay::~CDisplay", error_code);
    cleanup_flag = 0;
    destroy_result = CDisplay::DestroyObjects(this);
    cleanup_flag = -1;
    error_code = destroy_result;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
