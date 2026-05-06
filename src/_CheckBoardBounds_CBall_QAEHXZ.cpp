int __thiscall CBall::CheckBoardBounds(CBall *this)
{
  int v2; // edi
  double left; // st7
  int v4; // ecx
  double top; // st7
  int v6; // ecx
  struct tagRECT v8; // [esp+10h] [ebp-28h] BYREF
  _BYTE v9[8]; // [esp+20h] [ebp-18h] BYREF
  int v10; // [esp+28h] [ebp-10h]
  int v11; // [esp+34h] [ebp-4h]

  v2 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CBall::CheckBoardBounds", 0);
  v11 = 0;
  GetBoardRect(&v8);
  left = (double)v8.left;
  if ( left <= *((double *)this + 1) )
  {
    v4 = v8.right - *((_DWORD *)this + 6);
    v10 = v4;
    if ( (double)v4 >= *((double *)this + 1) )
      goto LABEL_5;
    v10 = v4 - 1;
    left = (double)(v4 - 1);
  }
  *((double *)this + 1) = left;
  v2 = 1;
  *((double *)this + 8) = -*((double *)this + 8);
LABEL_5:
  top = (double)v8.top;
  if ( top > *((double *)this + 2) )
  {
LABEL_8:
    *((double *)this + 2) = top;
    v2 = 1;
    *((double *)this + 9) = -*((double *)this + 9);
    goto LABEL_9;
  }
  v6 = v8.bottom - *((_DWORD *)this + 7);
  v10 = v6;
  if ( (double)v6 < *((double *)this + 2) )
  {
    v10 = v6 - 1;
    top = (double)(v6 - 1);
    goto LABEL_8;
  }
LABEL_9:
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
  return v2;
}
