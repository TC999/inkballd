#include <cstdint>
#include <windows.h>

extern "C" {
    long __stdcall CSink::AddRef(volatile long* this_ptr)
    {
      long result; // esi
      uint8_t log_buffer[8]; // [esp+4h] [ebp-8h] BYREF

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSink::AddRef", 0);
      result = InterlockedIncrement(reinterpret_cast<volatile long*>(this_ptr + 1));
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return result;
    }
}
