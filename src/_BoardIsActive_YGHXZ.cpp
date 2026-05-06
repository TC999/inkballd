int __stdcall BoardIsActive()
{
  int v0; // esi
  _BYTE v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "BoardIsActive", 0);
  v0 = *((_DWORD *)g_pCGameManager + 1);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return v0;
}
