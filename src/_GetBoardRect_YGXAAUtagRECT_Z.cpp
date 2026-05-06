void __stdcall GetBoardRect(struct tagRECT *a1)
{
  _BYTE v1[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v1, "GetBoardRect", 0);
  a1->left = *((_DWORD *)g_pCGameBoard + 2467);
  a1->top = *((_DWORD *)g_pCGameBoard + 2468);
  a1->right = *((_DWORD *)g_pCGameBoard + 2465);
  a1->bottom = *((_DWORD *)g_pCGameBoard + 2466);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v1);
}
