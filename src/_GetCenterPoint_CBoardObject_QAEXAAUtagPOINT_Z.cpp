void __thiscall CBoardObject::GetCenterPoint(CBoardObject *this, struct tagPOINT *a2)
{
  _BYTE v3[8]; // [esp+8h] [ebp-Ch] BYREF
  int v4; // [esp+10h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CBoardObject::GetCenterPoint", 0);
  v4 = *((int *)this + 6) >> 1;
  a2->x = (int)((double)v4 + *((double *)this + 1));
  a2->y = (int)((double)(*((int *)this + 7) >> 1) + *((double *)this + 2));
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
