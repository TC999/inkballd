int __stdcall AcceptInkInput()
{
  int v0; // esi
  _BYTE v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "AcceptInkInput", 0);
  v0 = *(_DWORD *)(*((_DWORD *)g_pCGameBoard + 2481) + 16);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return v0;
}
