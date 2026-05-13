#include "global_types.h"
#include <cstdint>
#include <windows.h>

int AddRef_CBall(CBall *self)
{
    uint32_t result;
    uint8_t log_buffer[8];

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CBall::AddRef", 0);
    result = ++((uint32_t*)self)[34];
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return result;
}
