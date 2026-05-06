int __thiscall CBall::VerifyCollision(CBall *this, struct tagRECT *a2, struct tagPOINT *a3)
{
  int v4; // ebx
  struct BallPoint *Point; // eax
  int v6; // esi
  LONG x; // [esp-Ch] [ebp-38h]
  LONG v9; // [esp-8h] [ebp-34h]
  _BYTE v10[8]; // [esp+10h] [ebp-1Ch] BYREF
  struct tagPOINT v11; // [esp+18h] [ebp-14h] BYREF
  int v12; // [esp+28h] [ebp-4h]

  v4 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBall::VerifyCollision", 0);
  v12 = 0;
  CBoardObject::GetCenterPoint(this, &v11);
  if ( *((int *)this + 33) <= 0 )
  {
LABEL_4:
    v6 = 0;
  }
  else
  {
    while ( 1 )
    {
      Point = CBall::GetPoint(this, v4);
      a3->x = v11.x + *(_DWORD *)Point;
      v9 = v11.y + *((_DWORD *)Point + 1);
      x = a3->x;
      a3->y = v9;
      if ( PointInRect(x, v9, a2) )
        break;
      if ( ++v4 >= *((_DWORD *)this + 33) )
        goto LABEL_4;
    }
    v6 = 1;
  }
  v12 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return v6;
}
