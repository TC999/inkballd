//----- (01008109) --------------------------------------------------------
void CGameBoard::AddDisplayUpdateRect(CGameBoard *self, struct tagRECT *a2)
{
  unsigned int v3; // ecx
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::AddDisplayUpdateRect", 0);
  v3 = *((_DWORD *)self + 1018);
  if ( v3 < 0x121 )
  {
    *((_DWORD *)self + 4 * v3 + 1019) = a2->left;
    *((_DWORD *)self + 4 * *((_DWORD *)self + 1018) + 1021) = a2->right;
    *((_DWORD *)self + 4 * *((_DWORD *)self + 1018) + 1020) = a2->top;
    *((_DWORD *)self + 4 * (*((_DWORD *)self + 1018))++ + 1022) = a2->bottom;
  }
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
}
