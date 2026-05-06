void __thiscall CUIBarObject::GetBoundingRect(CUIBarObject *this, struct tagRECT *a2)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CUIBarObject::GetBoundingRect", 0);
  *a2 = *(struct tagRECT *)((char *)this + 20);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
