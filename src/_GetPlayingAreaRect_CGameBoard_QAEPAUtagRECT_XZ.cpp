#if 0
#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
{
  uint8_t v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::GetPlayingAreaRect", 0);
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
  return (struct tagRECT *)(reinterpret_cast<char*>(this) + 4040);
}

#endif
