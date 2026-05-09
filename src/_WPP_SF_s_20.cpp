#include "global_types.h"
#include <cstdint>
#include <cstring>

extern "C" {
    uint32_t __stdcall WPP_SF_s(TRACEHANDLE LoggerHandle, uint16_t MessageNumber, const GUID* MessageGuid, const char* message)
    {
      uint32_t buffer_size; // eax
      const char* display_message; // ecx

      if (message)
        buffer_size = strlen(message) + 1;
      else
        buffer_size = 5;
      display_message = message;
      if (!message)
        display_message = "NULL";
      return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, display_message, buffer_size, 0);
    }
}
