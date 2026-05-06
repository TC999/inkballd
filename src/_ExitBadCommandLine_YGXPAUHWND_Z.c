void __stdcall __noreturn ExitBadCommandLine(HWND hWnd)
{
  _BYTE v1[16]; // [esp+10h] [ebp-14h] BYREF
  int v2; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "ExitBadCommandLine", 0);
  v2 = 0;
  DispError(hWnd, (HINSTANCE)0x3AA3, (HINSTANCE)0x3AA7);
  _exit(0);
}
