#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
#include "common.h"
char*__stdcall CGameBoard::GetBitmapRect(int a1)
{
  char*BitmapRect; // eax
  char*v2; // esi
  uint8_t v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::GetBitmapRect", 0);
  v5 = 0;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, a1);
  v5 = -1;
  v2 = BitmapRect;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
