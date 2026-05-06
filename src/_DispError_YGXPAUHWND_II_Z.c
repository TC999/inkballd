void __stdcall DispError(HWND hWnd, HINSTANCE uID, HINSTANCE a3)
{
  int *v3; // [esp+0h] [ebp-20A4h]
  int *v4; // [esp+0h] [ebp-20A4h]
  _BYTE v5[8]; // [esp+Ch] [ebp-2098h] BYREF
  WCHAR Text[4096]; // [esp+14h] [ebp-2090h] BYREF
  WCHAR Caption[64]; // [esp+2014h] [ebp-90h] BYREF
  int v8; // [esp+20A0h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "DispError", 0);
  v8 = 0;
  Helpers::LoadStringW(0, uID, Caption, (unsigned __int16 *)0x40, 0, v3);
  Helpers::LoadStringW(0, a3, Text, (unsigned __int16 *)0x1000, 0, v4);
  MessageBoxW(hWnd, Text, Caption, 0x10u);
  v8 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
