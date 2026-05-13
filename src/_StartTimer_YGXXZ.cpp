#include "global_types.h"
#include <cstdint>
#include <new>

extern "C" {
    void __stdcall StartTimer()
    {
      uint8_t log_buffer[8];

      new (log_buffer) Helpers::CLogBlock(log_buffer, "StartTimer", 0);
      *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(g_pCGameBoard + 2479) + 56) = 1;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}
