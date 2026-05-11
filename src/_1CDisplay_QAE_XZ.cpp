#if 0
#include "global_types.h"
#include <cstdint>
#include "common.h"

extern "C" {
    void CDisplay::~CDisplay(CDisplay* this_ptr)
    {
      int destroy_result; // eax
      uint8_t log_buffer[8]; // [esp+10h] [ebp-18h] BYREF
      int error_code[3]; // [esp+18h] [ebp-10h] BYREF
      int cleanup_flag; // [esp+24h] [ebp-4h]

      error_code[0] = 0;
      *reinterpret_cast<uint32_t*>(this_ptr) = reinterpret_cast<uint32_t>(&CDisplay::`vftable`);
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CDisplay::~CDisplay", error_code);
      cleanup_flag = 0;
      destroy_result = CDisplay::DestroyObjects(this_ptr);
      cleanup_flag = -1;
      error_code[0] = destroy_result;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}

#endif
