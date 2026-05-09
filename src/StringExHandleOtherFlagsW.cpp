#include "global_types.h"
#include <cstdint>
#include <cstring>

extern "C" {
    HRESULT __stdcall StringExHandleOtherFlagsW(
            STRSAFE_LPWSTR destination,
            size_t dest_size,
            size_t flags,
            STRSAFE_LPWSTR* dest_end,
            size_t* remaining,
            DWORD unused_flags)
    {
      int offset; // ecx
      uint32_t* remaining_ptr; // ebx
      uint16_t* buffer; // edi
      uint32_t dest_words; // esi
      uint16_t* end_ptr; // eax
      uint16_t* last_ptr; // eax

      dest_words = reinterpret_cast<uint32_t>(destination) >> 1;
      if (dest_words && (flags & 0x1000) != 0)
      {
        end_ptr = &buffer[offset];
        *reinterpret_cast<uint32_t*>(dest_size) = reinterpret_cast<uint32_t>(end_ptr);
        *remaining_ptr = dest_words - offset;
        *end_ptr = 0;
      }
      if ((flags & 0x400) != 0)
      {
        memset(buffer, static_cast<uint8_t>(flags), reinterpret_cast<size_t>(destination));
        if (static_cast<uint8_t>(flags))
        {
          if (!dest_words)
            return 0;
          last_ptr = &buffer[dest_words - 1];
          *reinterpret_cast<uint32_t*>(dest_size) = reinterpret_cast<uint32_t>(last_ptr);
          *remaining_ptr = 1;
          *last_ptr = 0;
        }
        else
        {
          *reinterpret_cast<uint32_t*>(dest_size) = reinterpret_cast<uint32_t>(buffer);
          *remaining_ptr = dest_words;
        }
      }
      if (dest_words && (flags & 0x800) != 0)
      {
        *reinterpret_cast<uint32_t*>(dest_size) = reinterpret_cast<uint32_t>(buffer);
        *remaining_ptr = dest_words;
        *buffer = 0;
      }
      return 0;
    }
}
