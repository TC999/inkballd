#include "global_types.h"
#include <cstdint>
#include <windows.h>
void* CSurface::GetDDrawSurface(CSurface* self)
{
  uint8_t log_buffer[8];

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CSurface::GetDDrawSurface", 0);
  void* surface = reinterpret_cast<void*>(*((uint32_t*)self + 1));
  reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
  return surface;
}
