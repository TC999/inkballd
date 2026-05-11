#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    BOOL __stdcall WriteRegValueDWORD(HKEY key, const wchar_t* sub_key, const wchar_t* value_name, uint8_t data)
    {
      BOOL result; // edi
      int* unused1; // [esp+0h] [ebp-28h]
      int* unused2; // [esp+0h] [ebp-28h]
      int* unused3; // [esp+0h] [ebp-28h]
      uint8_t log_buffer[8]; // [esp+10h] [ebp-18h] BYREF
      HKEY result_key; // [esp+18h] [ebp-10h] BYREF
      int cleanup_flag; // [esp+24h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "WriteRegValueDWORD", 0);
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
