#include <cstdint>
#include <cmath>

extern "C" {
    long double __stdcall sind(double degrees)
    {
      uint8_t log_buffer[8]; // [esp+0h] [ebp-8h] BYREF

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "sind", 0);
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
      return std::sin(degrees * 0.01745327777777778); // Convert degrees to radians
    }
}
