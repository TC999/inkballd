#include "global_types.h"
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>
int CreateWindowedDisplay_CDisplay(CDisplay* self, LPVOID *self, HWND hWnd, uint32_t xRight, int yBottom)
{
  void (**v5)(LPVOID *); // eax
  uint32_t *v6; // edi
  LONG v7; // eax
  int v8; // eax
  int v9; // esi
  RECT rc; // [esp-8h] [ebp-D0h]
  BOOL v11; // [esp-8h] [ebp-D0h]
  LONG WindowLongW; // [esp-4h] [ebp-CCh]
  int*v13; // [esp+0h] [ebp-C8h]
  int*v14; // [esp+0h] [ebp-C8h]
  int*v15; // [esp+0h] [ebp-C8h]
  int*v16; // [esp+0h] [ebp-C8h]
  int*v17; // [esp+0h] [ebp-C8h]
  uint32_t v18[31]; // [esp+10h] [ebp-B8h] BYREF
  LONG pvParam; // [esp+8Ch] [ebp-3Ch] BYREF
  LONG v20; // [esp+90h] [ebp-38h]
  uint8_t v21[8]; // [esp+9Ch] [ebp-2Ch] BYREF
  int v23; // [esp+B4h] [ebp-14h] BYREF
  char v24[4]; // [esp+B8h] [ebp-10h] BYREF
  int v25; // [esp+C4h] [ebp-4h]

  *(uint32_t *)v24 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v21, "CDisplay::CreateWindowedDisplay", (int*)v24);
  auto v5 = (void (**)(LPVOID *))*self;
  v25 = 0;
  (*v5)(self);
  v6 = self + 1;
      *(uint32_t *)v24 = DirectDrawCreateEx(0, self + 1, &IID_IDirectDraw7, 0);
  if ( *(int*)v24 < 0 )
  {
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x18u, &stru_1002FB8, v24[0]);
  }
  else
  {
    *(uint32_t *)v24 = (*(int (__stdcall **)(uint32_t, HWND, int))(*(uint32_t *)*v6 + 80))(*v6, hWnd, 8);
    if ( *(int*)v24 < 0 )
    {
      if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x17u, &stru_1002FB8, v24[0]);
    }
    else
    {
      SetRect(&rc, 0, 0, xRight, yBottom);
      WindowLongW = GetWindowLongW(hWnd, -20);
      v11 = GetMenu(hWnd) != 0;
      v7 = GetWindowLongW(hWnd, -16);
      AdjustWindowRectEx(&rc, v7, v11, WindowLongW);
      Helpers::SetWindowPos(hWnd, 0, 0, 0, rc.right - rc.left, rc.bottom - rc.top, 0x16u, 0, v13);
      Helpers::SetWindowPos(hWnd, (HWND)0xFFFFFFFE, 0, 0, 0, 0, 0x13u, 0, v14);
      Helpers::SystemParametersInfoW(0x30u, 0, &pvParam, 0, 0, v15);
      Helpers::GetWindowRect(hWnd, (HWND)&rc, 0, v16);
      if ( rc.left < pvParam )
        rc.left = pvParam;
      if ( rc.top < v20 )
        rc.top = v20;
      Helpers::SetWindowPos(hWnd, 0, (HWND)rc.left, rc.top, 0, 0, 0x15u, 0, v17);
      memset(v18, 0, sizeof(v18));
      v8 = *v6;
      v18[0] = 124;
      v18[1] = 1;
      v18[26] = 512;
      *(uint32_t *)v24 = (*(int (__stdcall **)(int, uint32_t *, char*, uint32_t))(*(uint32_t *)v8 + 24))(
                         v8,
                         v18,
                         reinterpret_cast<char*>(self) + 8,
                         0);
      if ( *(int*)v24 < 0 )
      {
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x16u, &stru_1002FB8, v24[0]);
      }
      else
      {
        v18[3] = xRight;
        v18[1] = 7;
        v18[26] = 64;
        v18[2] = yBottom;
        if ( fPortraitMode() )
          v18[26] |= 0x800u;
        *(uint32_t *)v24 = (*(int (__stdcall **)(uint32_t, uint32_t *, char*, uint32_t))(*(uint32_t *)*v6 + 24))(
                           *v6,
                           v18,
                           reinterpret_cast<char*>(self) + 12,
                           0);
        if ( *(int*)v24 < 0 )
        {
          if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
            WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x15u, &stru_1002FB8, v24[0]);
        }
        else
        {
          *(uint32_t *)v24 = (*(int (__stdcall **)(uint32_t, uint32_t *, char*, uint32_t))(*(uint32_t *)*v6 + 24))(
                             *v6,
                             v18,
                             reinterpret_cast<char*>(self) + 20,
                             0);
          if ( *(int*)v24 < 0 )
          {
            if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x14u, &stru_1002FB8, v24[0]);
          }
          else
          {
            *(uint32_t *)v24 = (*(int (__stdcall **)(uint32_t, uint32_t *, char*, uint32_t))(*(uint32_t *)*v6 + 24))(
                               *v6,
                               v18,
                               reinterpret_cast<char*>(self) + 24,
                               0);
            if ( *(int*)v24 < 0 )
            {
              if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x13u, &stru_1002FB8, v24[0]);
            }
            else
            {
              *(uint32_t *)v24 = (*(int (__stdcall **)(uint32_t, uint32_t, int*, uint32_t))(*(uint32_t *)*v6 + 16))(
                                 *v6,
                                 0,
                                 &v23,
                                 0);
              if ( *(int*)v24 < 0 )
              {
                if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                  WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x12u, &stru_1002FB8, v24[0]);
              }
              else
              {
                *(uint32_t *)v24 = (*(int (__stdcall **)(int, uint32_t, HWND))(*(uint32_t *)v23 + 32))(v23, 0, hWnd);
                if ( *(int*)v24 < 0 )
                {
                  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                    WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x11u, &stru_1002FB8, v24[0]);
                }
                else
                {
                  *(uint32_t *)v24 = (*(int (__stdcall **)(LPVOID, int))(*(uint32_t *)self[2] + 112))(self[2], v23);
                  if ( *(int*)v24 < 0 )
                  {
                    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((uint8_t *)WPP_GLOBAL_Control + 28) & 4) != 0 )
                      WPP_SF_d(*((uint64_t *)WPP_GLOBAL_Control + 2), 0x10u, &stru_1002FB8, v24[0]);
                  }
                  else
                  {
                    self[7] = hWnd;
                    self[12] = (LPVOID)1;
                    CDisplay::UpdateBounds((CDisplay *)self);
                  }
                }
                (*(void (__stdcall **)(int))(*(uint32_t *)v23 + 8))(v23);
              }
            }
          }
        }
      }
    }
  }
  v9 = *(uint32_t *)v24;
  v25 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v21)->~CLogBlock();
  return v9;
}
