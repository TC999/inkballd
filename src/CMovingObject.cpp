#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void* CInk_vftable; // Forward declaration of virtual table

CMovingObject::CMovingObject()
{
    uint8_t log_buffer[8];

    CBoardObject::CBoardObject();
    *((uint32_t*)self + 0) = reinterpret_cast<uint32_t>(&CInk_vftable);
    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CMovingObject::CMovingObject", 0);
    *((float*)self + 2) = 0.0;
    *((float*)self + 3) = 0.0;
    *((float*)self + 4) = 0.0;
    *((float*)self + 5) = 0.0;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
