#include "global_types.h"
#include <cstdint>
#include <windows.h>

long CSink_AddRef(volatile long* this_ptr)
{
    uint8_t log_buffer[8];

    new (log_buffer) Helpers::CLogBlock(log_buffer, "CSink::AddRef", 0);
    long result = InterlockedIncrement(reinterpret_cast<volatile long*>(this_ptr + 1));
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return result;
}
