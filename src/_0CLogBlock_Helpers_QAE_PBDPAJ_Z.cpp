#include "global_types.h"
#include <cstdint>

namespace Helpers {

CLogBlock::CLogBlock(void* self, const char* name, int line)
{
    uint8_t* base = reinterpret_cast<uint8_t*>(this);
    *reinterpret_cast<const char**>(base + 4) = name;
    *reinterpret_cast<int*>(base) = line;
    if (WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) &&
        (reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control))[14] & 0x400) != 0)
        WPP_SF_s(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2, 0xAu, &stru_10036F8, name);
}

}
