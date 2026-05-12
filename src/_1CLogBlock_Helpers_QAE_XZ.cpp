#include "global_types.h"
#include <cstdint>

namespace Helpers {

CLogBlock::~CLogBlock()
{
    uint8_t* base = reinterpret_cast<uint8_t*>(this);
    const char* func_name = *reinterpret_cast<const char**>(base + 4);
    int error = *reinterpret_cast<int*>(base);

    if (!func_name)
        return;
    if (error >= 0)
        return;

    if (WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control))
    {
        uint8_t* ctrl = reinterpret_cast<uint8_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control));
        if ((ctrl[28] & 4) != 0)
        {
            WPP_SF_sL(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2,
                      0xBu, &stru_10036F8, func_name, static_cast<char>(error));
        }
        if ((ctrl[14] & 0x400) != 0)
        {
            WPP_SF_s(*reinterpret_cast<uint64_t*>(static_cast<uintptr_t>(WPP_GLOBAL_Control)) + 2,
                     0xCu, &stru_10036F8, func_name);
        }
    }
}

}
