#include "global_types.h"
#include <cstdint>
#include <cwchar>

extern "C" {
    uint32_t __stdcall WPP_SF_Sd(
            TRACEHANDLE LoggerHandle,
            uint16_t MessageNumber,
            const GUID* MessageGuid,
            const uint16_t* message,
            char flags)
    {
      const wchar_t* display_message; // edx
      uint32_t buffer_size; // eax
      int default_size; // [esp-4h] [ebp-4h]

      display_message = reinterpret_cast<const wchar_t*>(message);
      if (message)
      {
        if (*message)
        {
          buffer_size = 2 * wcslen(reinterpret_cast<const wchar_t*>(message)) + 2;
          goto LABEL_7;
        }
        default_size = 14;
      }
      else
      {
        default_size = 10;
      }
      buffer_size = default_size;
LABEL_7:
      if (message)
      {
        if (!*message)
          display_message = L"<NULL>";
      }
      else
      {
        display_message = L"NULL";
      }
      return TraceMessage(LoggerHandle, 0x2Bu, MessageGuid, MessageNumber, display_message, buffer_size, &flags, 4, 0);
    }
}
