#include "global_types.h"
#include <cstdint>
#include <windows.h>
#include <new>

extern "C" {
    BOOL __stdcall WriteRegValueDWORD(HKEY key, const wchar_t* sub_key, const wchar_t* value_name, uint8_t data)
    {
      BOOL result;
      int* unused1;
      int* unused2;
      int* unused3;
      uint8_t log_buffer[8];
      HKEY result_key;
      int cleanup_flag;

      new (log_buffer) Helpers::CLogBlock(log_buffer, "WriteRegValueDWORD", 0);
      cleanup_flag = 0;
      result = 0;
      if (!RegOpenKeyExW(key, sub_key, 0, 0x2001Fu, &result_key))
      {
        DWORD dwData = data;
        result = RegSetValueExW(result_key, value_name, 0, 4u, reinterpret_cast<const BYTE*>(&dwData), 4u) == ERROR_SUCCESS;
        RegCloseKey(result_key);
      }
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
      return result;
    }
}
