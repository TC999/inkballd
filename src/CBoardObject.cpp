#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void* CInk_vftable; // Forward declaration of virtual table

CBoardObject::CBoardObject()
{
    uint8_t log_buffer[8];

    *((uint32_t*)this + 0) = reinterpret_cast<uint32_t>(&CInk_vftable);
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBoardObject::CBoardObject", 0);
    *((uint32_t*)this + 1) = 0;
    *((float*)this + 2) = 0.0;
    *((uint32_t*)this + 2) = 0;
    *((float*)this + 3) = 0.0;
    *((uint32_t*)this + 3) = 0;
    *((float*)this + 4) = 1.0;
    *((float*)this + 5) = 1.0;
    *((uint32_t*)this + 6) = 32;
    *((uint32_t*)this + 7) = 32;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
