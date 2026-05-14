#include "global_types.h"
#include <cstdint>
#include <cstdarg>
#include <cstring>

extern "C" {
    int StringCchPrintfExW(
            wchar_t** destination,
            uint16_t* buffer,
            uint32_t buffer_size,
            uint16_t** new_buffer,
            uint32_t* remaining,
            size_t flags,
            const wchar_t* format,
            ...)
    {
      int result; // esi
      uint32_t remaining_space; // ebx
      int format_result; // eax
      size_t* temp_ptr; // [esp+0h] [ebp-10h]
      DWORD error_code; // [esp+4h] [ebp-Ch]
      size_t dest_size; // [esp+8h] [ebp-8h] BYREF
      uint32_t original_size; // [esp+Ch] [ebp-4h]
      va_list args; // [esp+30h] [ebp+20h] BYREF

      va_start(args, format);
      result = 0;
      if ((flags & 0x100) != 0)
      {
        if (buffer || !buffer_size)
        {
LABEL_6:
          if (buffer_size <= 0x7FFFFFFF)
            goto LABEL_8;
        }
      }
      else
      {
        result = 0;
        if (buffer_size)
          goto LABEL_6;
      }
      result = -2147024809; // STRSAFE_E_INVALID_PARAMETER
LABEL_8:
      if (result < 0)
        return result;
      dest_size = reinterpret_cast<size_t>(buffer);
      original_size = buffer_size;
      if ((flags & 0x100) != 0 && !format)
        format = reinterpret_cast<wchar_t*>(dword_10035B8);
      result = 0;
      if ((flags & 0xFFFFE000) != 0)
      {
        result = -2147024809; // STRSAFE_E_INVALID_PARAMETER
        if (buffer_size)
          *buffer = 0;
        goto LABEL_15;
      }
      if (buffer_size)
      {
        result = 0;
        remaining_space = buffer_size - 1;
        format_result = _vsnwprintf(buffer, buffer_size - 1, format, args);
        if (format_result < 0 || format_result > remaining_space)
        {
          result = -2147024774; // STRSAFE_E_INSUFFICIENT_BUFFER
        }
        else if (format_result != remaining_space)
        {
          remaining_space = format_result;
          goto LABEL_34;
        }
        buffer[remaining_space] = 0;
LABEL_34:
        dest_size = reinterpret_cast<size_t>(&buffer[remaining_space]);
        original_size = buffer_size - remaining_space;
        if (result >= 0)
        {
          if ((flags & 0x200) != 0 && original_size > 1 && 2 * original_size > 2)
            memset(reinterpret_cast<void*>(dest_size + 2), static_cast<uint8_t>(flags), 2 * original_size - 2);
          goto LABEL_20;
        }
        goto LABEL_15;
      }
      if (!*format)
      {
LABEL_20:
        if (new_buffer)
          *new_buffer = reinterpret_cast<uint16_t*>(dest_size);
        if (remaining)
          *remaining = original_size;
        return result;
      }
      result = buffer != 0 ? -2147024774 : -2147024809; // STRSAFE_E_INSUFFICIENT_BUFFER or STRSAFE_E_INVALID_PARAMETER
LABEL_15:
      if ((flags & 0x1C00) != 0 && buffer_size)
        StringExHandleOtherFlagsW(reinterpret_cast<STRSAFE_LPWSTR>(2 * buffer_size), &dest_size, flags, destination, temp_ptr, error_code);
      if (result >= 0 || result == -2147024774) // STRSAFE_E_INSUFFICIENT_BUFFER
        goto LABEL_20;
      return result;
    }
}
