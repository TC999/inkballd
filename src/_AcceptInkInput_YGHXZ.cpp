#include "global_types.h"
#include <cstdint>

extern "C" {
    int __stdcall AcceptInkInput()
    {
      int result;
      uint8_t log_buffer[8];

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "AcceptInkInput", 0);
      result = *reinterpret_cast<uint32_t*>(*reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(g_pCGameBoard) + 2481) + 16);
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
      return result;
    }
}
