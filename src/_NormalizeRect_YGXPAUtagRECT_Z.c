void __stdcall NormalizeRect(struct tagRECT *a1)
{
  LONG left; // ecx
  LONG right; // edx
  LONG bottom; // ecx
  _BYTE v4[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "NormalizeRect", 0);
  left = a1->left;
  right = a1->right;
  if ( a1->left > right )
  {
    a1->left = right;
    a1->right = left;
  }
  bottom = a1->bottom;
  if ( a1->top > bottom )
    a1->top = bottom;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
