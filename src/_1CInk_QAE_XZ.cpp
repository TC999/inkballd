#include "global_types.h"
#include <cstdint>

extern "C" void* CInk_vftable;

CInk::~CInk()
{
  uint8_t log_buffer[16];
  int cleanup_flag;

  *((uint32_t*)self + 0) = reinterpret_cast<uint32_t>(&CInk_vftable);
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CInk::~CInk", 0);
  cleanup_flag = 0;
  CInk::Cleanup(self);
  cleanup_flag = -1;
  reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
