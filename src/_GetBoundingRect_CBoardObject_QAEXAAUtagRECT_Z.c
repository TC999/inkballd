void __thiscall CBoardObject::GetBoundingRect(CBoardObject *this, struct tagRECT *a2)
{
  _BYTE v3[8]; // [esp+8h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardObject::GetBoundingRect", 0);
  a2->left = (int)*((double *)this + 1);
  a2->right = (int)((double)*((int *)this + 6) + *((double *)this + 1));
  a2->top = (int)*((double *)this + 2);
  a2->bottom = (int)((double)*((int *)this + 7) + *((double *)this + 2));
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
