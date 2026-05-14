#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

uint32_t __stdcall GenerateLastErrorHR_TabUtils(uint32_t fallback, int unused)
{
    uint32_t result;

    result = GetLastError();
    if ((int)result > 0)
    {
        result = (uint16_t)result | 0x80070000;
    }
    if ((int)result >= 0)
        return fallback;
    return result;
}
