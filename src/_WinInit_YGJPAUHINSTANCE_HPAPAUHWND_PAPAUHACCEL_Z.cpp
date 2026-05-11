#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    int __stdcall WinInit(HINSTANCE hInstance, int cmdShow, HWND* hWnd, HACCEL* hAccel)
    {
      int return_code; // esi
      char error_char; // al
      uint8_t last_error; // al
      HWND window_handle; // eax
      int* unused1; // [esp+0h] [ebp-278h]
      int* unused2; // [esp+0h] [ebp-278h]
      int* unused3; // [esp+0h] [ebp-278h]
      int* unused4; // [esp+0h] [ebp-278h]
      int* unused5; // [esp+0h] [ebp-278h]
      WNDCLASSEXW wc; // [esp+10h] [ebp-268h] BYREF
      uint8_t log_buffer[8]; // [esp+40h] [ebp-238h] BYREF
      HWND* window_ptr; // [esp+48h] [ebp-230h]
      HACCEL accel_handle; // [esp+4Ch] [ebp-22Ch]
      HACCEL* accel_ptr; // [esp+50h] [ebp-228h]
      RECT window_rect; // [esp+54h] [ebp-224h] BYREF
      int log_error_code; // [esp+64h] [ebp-214h] BYREF
      WCHAR title_buffer[262]; // [esp+68h] [ebp-210h] BYREF
      int cleanup_code; // [esp+274h] [ebp-4h]

      window_ptr = hWnd;
      accel_ptr = hAccel;
      return_code = 0;
      log_error_code = 0;
      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "WinInit", 0);
      cleanup_code = 0;
      wc.cbSize = sizeof(WNDCLASSEXW);
      wc.lpszClassName = g_szAppName;
      wc.lpfnWndProc = MainWndProc;
      wc.style = CS_HREDRAW | CS_VREDRAW;
      wc.hInstance = hInstance;
      wc.hIcon = LoadIconW(hInstance, MAKEINTRESOURCEW(IDI_APPLICATION));
      wc.hIconSm = LoadIconW(hInstance, MAKEINTRESOURCEW(IDI_APPLICATION));
      wc.hCursor = LoadCursorW(nullptr, IDC_ARROW);
      wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
      wc.lpszMenuName = (LPCWSTR)102;
      wc.cbClsExtra = 0;
      wc.cbWndExtra = 0;
      if (RegisterClassExW(&wc))
      {
        accel_handle = LoadAcceleratorsW(hInstance, (LPCWSTR)0x67);
        if (!accel_handle && WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && ((*reinterpret_cast<uint8_t*>(&WPP_GLOBAL_Control) + 28) & 4) != 0)
        {
          last_error = GetLastError();
          WPP_SF_d(WPP_GLOBAL_Control + 2, 0xBu, &stru_1003520, last_error);
        }
        LoadStringW(hInstance, 0x3A98, title_buffer, 262);
        window_rect.left = 0;
        window_rect.top = 0;
        window_rect.right = 544;
        window_rect.bottom = 586;
        AdjustWindowRectEx(&window_rect, WS_OVERLAPPEDWINDOW, 1, 0);
        window_handle = CreateWindowExW(
                          0,
                          g_szAppName,
                          title_buffer,
                          WS_OVERLAPPEDWINDOW,
                          CW_USEDEFAULT,
                          CW_USEDEFAULT,
                          window_rect.right - window_rect.left,
                          window_rect.bottom - window_rect.top,
                          0,
                          0,
                          hInstance,
                          nullptr);
        if (window_handle)
        {
          *window_ptr = window_handle;
          *accel_ptr = accel_handle;
          goto LABEL_6;
        }
      }
      else if (WPP_GLOBAL_Control != reinterpret_cast<uint64_t>(&WPP_GLOBAL_Control) && ((*reinterpret_cast<uint8_t*>(&WPP_GLOBAL_Control) + 28) & 4) != 0)
      {
        error_char = GetLastError();
        WPP_SF_d(WPP_GLOBAL_Control + 2, 0xAu, &stru_1003520, error_char);
      }
      return_code = -2147467259;
LABEL_6:
      cleanup_code = -1;
      log_error_code = return_code;
      reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
      return return_code;
    }
}
