void __thiscall CBoardTile::SetClosestSide(CBoardTile *this, struct tagPOINT *a2)
{
  struct tagRECT v3; // [esp+10h] [ebp-2Ch] BYREF
  _BYTE v4[8]; // [esp+20h] [ebp-1Ch] BYREF
  struct tagPOINT v5; // [esp+28h] [ebp-14h] BYREF
  int v6; // [esp+38h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBoardTile::SetClosestSide", 0);
  v6 = 0;
  CBoardObject::GetBoundingRect(this, &v3);
  v5.x = a2->x;
  v5.y = v3.top;
  CalcUnsqrtDistance(a2, &v5);
  v5.x = v3.right;
  v5.y = a2->y;
  CalcUnsqrtDistance(a2, &v5);
  v5.x = a2->x;
  v5.y = v3.bottom;
  CalcUnsqrtDistance(a2, &v5);
  v5.x = v3.left;
  v5.y = a2->y;
  CalcUnsqrtDistance(a2, &v5);
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
