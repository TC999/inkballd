#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
struct tagRECT *__thiscall CGameBoard::GetPlayingAreaRect(CGameBoard *this)
{
  uint8_t v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::GetPlayingAreaRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return (struct tagRECT *)(reinterpret_cast<char*>(this) + 4040);
}
