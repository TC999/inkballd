HWND __stdcall GetMainWindowHwnd()
{
  int v0; // esi
  _BYTE v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "GetMainWindowHwnd", 0);
  v0 = *((_DWORD *)g_pCGameBoard + 2480);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return (HWND)v0;
}
