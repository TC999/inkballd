//----- (01004822) --------------------------------------------------------
int CBall::VerifyCollision(CBall* self, void* rect, void* point)
{
  struct tagRECT* a2 = (struct tagRECT*)rect;
  struct tagPOINT* a3 = (struct tagPOINT*)point;
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
  CBoardObject::GetCenterPoint(self, &v11);
  if ( *((int *)self + 33) <= 0 )
  {
LABEL_4:
    v6 = 0;
  }
  else
  {
    while ( 1 )
    {
      Point = (struct BallPoint *)CBall::GetPoint(self, v4);
      a3->x = v11.x + *(_DWORD *)Point;
      v9 = v11.y + *((_DWORD *)Point + 1);
      x = a3->x;
      a3->y = v9;
      if ( PointInRect(x, v9, a2) )
        break;
      if ( ++v4 >= *((_DWORD *)self + 33) )
        goto LABEL_4;
    }
    v6 = 1;
  }
  v12 = -1;
  ((Helpers::CLogBlock *)v10)->~CLogBlock();
  return v6;
}
