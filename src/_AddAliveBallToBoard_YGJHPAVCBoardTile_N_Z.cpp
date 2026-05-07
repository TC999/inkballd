#include <cstdint>
#include <new>

extern "C" {
    int __stdcall AddAliveBallToBoard(int ball_type, CBoardTile* tile, double speed)
    {
      char* bitmap_rect; // eax
      int ball_result; // esi
      POINT center_point; // [esp+18h] [ebp-24h] BYREF
      uint8_t log_buffer[8]; // [esp+20h] [ebp-1Ch] BYREF
      int error_code[4]; // [esp+28h] [ebp-14h] BYREF
      int init_step; // [esp+38h] [ebp-4h]
      CBoardObject* ball_object; // [esp+48h] [ebp+Ch]

      error_code[0] = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "AddAliveBallToBoard", error_code);
      init_step = 0;
      if (CGameBoard::NumBallsOnBoard(g_pCGameBoard) >= 64)
        DisplayBoardLoadMsg();
      CBoardObject::GetCenterPoint(tile, &center_point);
      init_step = 1;
      ball_object = reinterpret_cast<CBoardObject*>(operator new(0x1A8u));
      init_step = 2;
      if (ball_object)
      {
        bitmap_rect = CGameBoard::GetBitmapRect(ball_type + 2);
        ball_result = CBall::CBall(reinterpret_cast<int>(ball_object), reinterpret_cast<int>(bitmap_rect), ball_type, 1, *reinterpret_cast<uint32_t*>(g_pCGameBoard + 2471));
      }
      else
      {
        ball_result = 0;
      }
      init_step = 0;
      if (ball_result)
      {
        CBall::AddRef(reinterpret_cast<CBall*>(ball_result));
        *reinterpret_cast<uint32_t*>(ball_result + 24) = *reinterpret_cast<uint32_t*>(g_pCGameBoard + 2471);
        *reinterpret_cast<uint32_t*>(ball_result + 28) = *reinterpret_cast<uint32_t*>(g_pCGameBoard + 2471);
        *reinterpret_cast<double*>(ball_result + 8) = static_cast<double>(center_point.x) - static_cast<double>(*reinterpret_cast<int*>(g_pCGameBoard + 2471)) * 0.5;
        *reinterpret_cast<double*>(ball_result + 16) = static_cast<double>(center_point.y) - 0.5 * static_cast<double>(*reinterpret_cast<int*>(g_pCGameBoard + 2471));
        CBallManager::SetBallSpeed(*reinterpret_cast<CBallManager**>(g_pCGameBoard + 2476), reinterpret_cast<CBall*>(ball_result), speed);
        *reinterpret_cast<uint32_t*>(ball_result + 156) = 1;
        *reinterpret_cast<uint32_t*>(ball_result + 160) = 1;
        CGameBoard::AddBall(g_pCGameBoard, reinterpret_cast<CBall*>(ball_result));
        init_step = -1;
        error_code[0] = 0;
        Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
        return 0;
      }
      else
      {
        init_step = -1;
        error_code[0] = -2147024882; // E_OUTOFMEMORY
        Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
        return -2147024882;
      }
    }
}
  else
  {
    v4 = 0;
  }
  v9 = 0;
  if ( v4 )
  {
    CBall::AddRef((CBall *)v4);
    *(_DWORD *)(v4 + 24) = *((_DWORD *)g_pCGameBoard + 2471);
    *(_DWORD *)(v4 + 28) = *((_DWORD *)g_pCGameBoard + 2471);
    *(double *)(v4 + 8) = (double)v6.x - (double)*((int *)g_pCGameBoard + 2471) * 0.5;
    *(double *)(v4 + 16) = (double)v6.y - 0.5 * (double)*((int *)g_pCGameBoard + 2471);
    CBallManager::SetBallSpeed(*((CBallManager **)g_pCGameBoard + 2476), (struct CBall *)v4, a3);
    *(_DWORD *)(v4 + 156) = 1;
    *(_DWORD *)(v4 + 160) = 1;
    CGameBoard::AddBall(g_pCGameBoard, (struct CBall *)v4);
    v9 = -1;
    v8[0] = 0;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
    return 0;
  }
  else
  {
    v9 = -1;
    v8[0] = -2147024882;
    Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
    return -2147024882;
  }
}
