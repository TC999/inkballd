#include "global_types.h"
#include <cstdint>
#include <new>
void CTimeManager::SetTime(void* self, uint32_t time_value)
{
  uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
  int cleanup_flag; // [esp+20h] [ebp-4h]

  new (log_buffer) Helpers::CLogBlock(log_buffer, "CTimeManager::SetTime", 0);
  cleanup_flag = 0;
  *((uint32_t*)self + 13) = 0;
  *((uint32_t*)self + 9) = time_value;
  (*(void(**)(void*))(*(uint32_t*)self + 4))(self);
  cleanup_flag = -1;
  reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
