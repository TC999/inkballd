void __stdcall SetBoardActiveState(int a1)
{
  _BYTE v1[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "SetBoardActiveState", 0);
  *((_DWORD *)g_pCGameManager + 1) = a1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
