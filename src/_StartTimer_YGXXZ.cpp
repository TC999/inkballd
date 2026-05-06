void __stdcall StartTimer()
{
  _BYTE v0[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v0, "StartTimer", 0);
  *(_DWORD *)(*((_DWORD *)g_pCGameBoard + 2479) + 56) = 1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v0);
}
