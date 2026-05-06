int __stdcall WinInit(HINSTANCE hInstance, int a2, HWND *a3, HACCEL *a4)
{
  int v4; // esi
  char v5; // al
  char LastError; // al
  HWND Window; // eax
  int *v9; // [esp+0h] [ebp-278h]
  int *v10; // [esp+0h] [ebp-278h]
  int *v11; // [esp+0h] [ebp-278h]
  int *v12; // [esp+0h] [ebp-278h]
  int *v13; // [esp+0h] [ebp-278h]
  WNDCLASSEXW v14; // [esp+10h] [ebp-268h] BYREF
  _BYTE v15[8]; // [esp+40h] [ebp-238h] BYREF
  HWND *v16; // [esp+48h] [ebp-230h]
  HACCEL AcceleratorsW; // [esp+4Ch] [ebp-22Ch]
  HACCEL *v18; // [esp+50h] [ebp-228h]
  struct tagRECT Rect; // [esp+54h] [ebp-224h] BYREF
  int v20; // [esp+64h] [ebp-214h] BYREF
  WCHAR Buffer[262]; // [esp+68h] [ebp-210h] BYREF
  int v22; // [esp+274h] [ebp-4h]

  v16 = a3;
  v18 = a4;
  v4 = 0;
  v20 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v15, "WinInit", &v20);
  v22 = 0;
  v14.cbSize = 48;
  v14.lpszClassName = g_szAppName;
  v14.lpfnWndProc = (WNDPROC)MainWndProc;
  v14.style = 3;
  v14.hInstance = hInstance;
  v14.hIcon = Helpers::LoadIconW(hInstance, (HINSTANCE)0x65, 0, v9);
  v14.hIconSm = Helpers::LoadIconW(hInstance, (HINSTANCE)0x65, 0, v10);
  v14.hCursor = Helpers::LoadCursorW(0, (HINSTANCE)0x7F77, 0, v11);
  v14.hbrBackground = (HBRUSH)6;
  v14.lpszMenuName = (LPCWSTR)102;
  v14.cbClsExtra = 0;
  v14.cbWndExtra = 0;
  if ( RegisterClassExW(&v14) )
  {
    AcceleratorsW = LoadAcceleratorsW(hInstance, (LPCWSTR)0x67);
    if ( !AcceleratorsW && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      LastError = GetLastError();
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xBu, &stru_1003520, LastError);
    }
    Helpers::LoadStringW(0, (HINSTANCE)0x3A98, Buffer, (unsigned __int16 *)0x100, 0, v12);
    Rect.left = 0;
    Rect.top = 0;
    Rect.right = 544;
    Rect.bottom = 586;
    AdjustWindowRectEx(&Rect, 0xCA0000u, 1, 0);
    Window = Helpers::CreateWindowExW(
               0,
               g_szAppName,
               Buffer,
               0xCA0000u,
               0x80000000,
               0x80000000,
               Rect.right - Rect.left,
               Rect.bottom - Rect.top,
               0,
               0,
               (HMENU)hInstance,
               0,
               0,
               v13);
    if ( Window )
    {
      *v16 = Window;
      *v18 = AcceleratorsW;
      goto LABEL_6;
    }
  }
  else if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    v5 = GetLastError();
    WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, &stru_1003520, v5);
  }
  v4 = -2147467259;
LABEL_6:
  v22 = -1;
  v20 = v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v15);
  return v4;
}
