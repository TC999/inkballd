#include "global_types.h"
#include <cstdint>
#include <windows.h>
#include <new>

extern "C" {
    void __stdcall CRegistryManager_WriteDifficulty(CRegistryManager* this_ptr, uint8_t data)
    {
      uint8_t log_buffer[16];
      int cleanup_flag;

      new (log_buffer) Helpers::CLogBlock(log_buffer, "CRegistryManager::WriteDifficulty", 0);
      cleanup_flag = 0;
      if (!WriteRegValueDWORD(HKEY_CURRENT_USER, SubKey, stru_1002CD8, data))
      {
        CreateInkballKey();
        WriteRegValueDWORD(HKEY_CURRENT_USER, SubKey, stru_1002CD8, data);
      }
      cleanup_flag = -1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}
