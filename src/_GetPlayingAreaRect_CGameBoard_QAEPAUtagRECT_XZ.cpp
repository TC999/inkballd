#include "global_types.h"
#include <cstdint>
#include <windows.h>
struct tagRECT* CGameBoard::GetPlayingAreaRect(CGameBoard* self)
{
  uint8_t v3[8];

  Helpers::CLogBlock::CLogBlock(v3, "CGameBoard::GetPlayingAreaRect", 0);
  reinterpret_cast<Helpers::CLogBlock*>(v3)->~CLogBlock();
  return (struct tagRECT *)(reinterpret_cast<char*>(self) + 4040);
}
