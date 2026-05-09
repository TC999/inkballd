#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    uint32_t __stdcall WppControlCallback(
            WMIDPREQUESTCODE request_code,
            uint16_t* request_context,
            uint32_t* buffer_size,
            void* buffer)
    {
      int unused1; // edx
      uint16_t* context_ptr; // edi
      int logger_handle_high; // ebx
      uint32_t trace_enable_flags; // eax
      TRACEHANDLE trace_logger_handle; // kr00_8
      uint16_t context_flags; // cx
      uint32_t* control_struct; // ecx
      uint16_t* alternate_context; // esi
      uint8_t trace_level; // [esp+23h] [ebp+Fh]

      unused1 = 0;
      *buffer_size = 0;
      context_ptr = request_context;
      if (request_code == WMI_ENABLE_EVENTS)
      {
        trace_logger_handle = GetTraceLoggerHandle(buffer);
        logger_handle_high = trace_logger_handle;
        trace_level = GetTraceEnableLevel(trace_logger_handle);
        trace_enable_flags = GetTraceEnableFlags(trace_logger_handle);
        unused1 = trace_logger_handle >> 32;
      }
      else
      {
        if (request_code != WMI_DISABLE_EVENTS)
          return 87; // ERROR_INVALID_PARAMETER
        logger_handle_high = 0;
        trace_enable_flags = 0;
        trace_level = 0;
      }
      context_flags = request_context[13];
      if ((context_flags & 1) != 0 && *reinterpret_cast<uint32_t*>(request_context + 4))
      {
        control_struct = reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(request_context + 4));
        *control_struct = logger_handle_high;
        control_struct[1] = unused1;
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(request_context + 4) + 12) = trace_level;
        *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(request_context + 4) + 8) = trace_enable_flags;
      }
      else
      {
        if ((context_flags & 2) != 0)
        {
          alternate_context = reinterpret_cast<uint16_t*>(*reinterpret_cast<uint32_t*>(request_context + 4));
          if (alternate_context)
            context_ptr = alternate_context;
        }
        *reinterpret_cast<uint32_t*>(context_ptr + 4) = logger_handle_high;
        *reinterpret_cast<uint32_t*>(context_ptr + 5) = unused1;
        *reinterpret_cast<uint8_t*>(context_ptr + 25) = trace_level;
        *reinterpret_cast<uint32_t*>(context_ptr + 7) = trace_enable_flags;
      }
      return 0;
    }
}
