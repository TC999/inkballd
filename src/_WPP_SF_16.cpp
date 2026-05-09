#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    ULONG __stdcall TraceMessage(TRACEHANDLE, ULONG, LPCGUID, USHORT, ULONG);
}

uint32_t __stdcall WPP_SF_(TRACEHANDLE LoggerHandle, uint16_t MessageNumber, LPCGUID MessageGuid)
{
    return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, 0);
}
