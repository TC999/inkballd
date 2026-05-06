void __thiscall CGameBoard::AddDisplayUpdateRect(CGameBoard *this, struct tagRECT *a2)
{
  unsigned int v3; // ecx
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::AddDisplayUpdateRect", 0);
  v3 = *((_DWORD *)this + 1018);
  if ( v3 < 0x121 )
  {
    *((_DWORD *)this + 4 * v3 + 1019) = a2->left;
    *((_DWORD *)this + 4 * *((_DWORD *)this + 1018) + 1021) = a2->right;
    *((_DWORD *)this + 4 * *((_DWORD *)this + 1018) + 1020) = a2->top;
    *((_DWORD *)this + 4 * (*((_DWORD *)this + 1018))++ + 1022) = a2->bottom;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
