//----- (0100BC46) --------------------------------------------------------
extern "C" void* CInk_vftable;
CInk::CInk(HWND hWnd)
{
  int *v4; // [esp+0h] [ebp-24h]
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  *(_DWORD *)this = (uint32_t)&CInk_vftable;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CInk::CInk", 0);
  v6 = 0;
  Helpers::GetClientRect(hWnd, &g_rcClient, 0, v4);
  v6 = -1;
  dword_10B0664 = 10 * (dword_10B0674 - g_rcClient.left);
  g_hWnd = hWnd;
  dword_10B0668 = 10 * (dword_10B0678 - dword_10B0670);
  *((_DWORD *)this + 4) = 0;
  ((Helpers::CLogBlock *)v5)->~CLogBlock();
}
