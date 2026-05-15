#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern "C" {
    void __stdcall AddBallToUpdateList(void* ball)
    {
        uint8_t log_buffer[16]; // [esp+10h] [ebp-14h] BYREF
        int cleanup_flag; // [esp+20h] [ebp-4h]

        Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "AddBallToUpdateList", 0);
        cleanup_flag = 0;
        CGameBoard::AddBallToUpdateList(g_pCGameBoard, (CBall*)ball);
        cleanup_flag = -1;
        reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    }
}


void CGameBoard::AddBallToUpdateList(CGameBoard *self, CBall* a2)
{
  int v3; // ecx
  uint8_t v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v4), "CGameBoard::AddBallToUpdateList", 0);
  v3 = *((uint32_t *)self + 301);
  if ( v3 < 64 )
  {
    *((uint32_t *)self + v3 + 302) = (uint32_t)a2;
    ++*((uint32_t *)self + 301);
  }
  reinterpret_cast<Helpers::CLogBlock*>(v4)->~CLogBlock();
}
