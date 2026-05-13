#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
struct tagRECT* CGameBoard::GetPlayingAreaRect(CGameBoard* self)
{
  uint8_t v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v3), "CGameBoard::GetPlayingAreaRect", 0);
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
  return (struct tagRECT *)(reinterpret_cast<char*>(self) + 4040);
}
