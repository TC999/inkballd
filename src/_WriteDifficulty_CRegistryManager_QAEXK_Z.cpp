#include <cstdint>
#include <windows.h>

extern "C" {
    void CRegistryManager::WriteDifficulty(CRegistryManager* this_ptr, uint8_t data)
    {
      uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
      int cleanup_flag; // [esp+20h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CRegistryManager::WriteDifficulty", 0);
      cleanup_flag = 0;
      if (!WriteRegValueDWORD(HKEY_CURRENT_USER, reinterpret_cast<HKEY>(&SubKey), reinterpret_cast<HKEY>(&stru_1002CD8), data))
      {
        CreateInkballKey();
        WriteRegValueDWORD(HKEY_CURRENT_USER, reinterpret_cast<HKEY>(&SubKey), reinterpret_cast<HKEY>(&stru_1002CD8), data);
      }
      cleanup_flag = -1;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
    }
}
