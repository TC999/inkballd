BOOL __stdcall PointInRect(LONG a1, LONG a2, struct tagRECT *a3)
{
  BOOL v3; // esi
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "PointInRect", 0);
  v6 = 0;
  NormalizeRect(a3);
  v3 = a1 >= a3->left && a1 < a3->right && a2 >= a3->top && a2 < a3->bottom;
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v3;
}
