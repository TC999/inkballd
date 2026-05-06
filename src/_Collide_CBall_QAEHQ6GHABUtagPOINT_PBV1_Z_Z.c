int __thiscall CBall::Collide(CBall *this, int (__stdcall *const a2)(const struct tagPOINT *, const struct CBall *))
{
  int v3; // ebx
  int v4; // edi
  struct BallPoint *NextPoint; // eax
  int PrevBallPoint; // eax
  int v7; // eax
  int *Point; // eax
  int v9; // esi
  _BYTE v11[8]; // [esp+28h] [ebp-28h] BYREF
  _DWORD v12[2]; // [esp+30h] [ebp-20h] BYREF
  struct tagPOINT v13; // [esp+38h] [ebp-18h] BYREF
  int v14; // [esp+40h] [ebp-10h]
  int v15; // [esp+4Ch] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBall::Collide", 0);
  v15 = 0;
  CBall::InitBallPoints(this);
  v14 = 0;
  v3 = -1;
  v4 = -1;
  CBoardObject::GetCenterPoint(this, &v13);
  NextPoint = CBall::GetNextPoint(this);
  if ( !NextPoint )
    goto LABEL_12;
  do
  {
    v12[0] = v13.x + *(_DWORD *)NextPoint;
    v12[1] = v13.y + *((_DWORD *)NextPoint + 1);
    if ( a2((const struct tagPOINT *)v12, this) )
    {
      PrevBallPoint = CBall::GetPrevBallPoint(this);
      if ( v4 == -1 )
        v4 = PrevBallPoint;
      v3 = PrevBallPoint;
      v14 = 1;
    }
    NextPoint = CBall::GetNextPoint(this);
  }
  while ( NextPoint );
  if ( v14 )
  {
    v7 = (v3 + v4) / 2;
    if ( v3 < v4 )
      v7 = (v7 + 16) % 32;
    Point = (int *)CBall::GetPoint(this, v7);
    CBall::Deflect(this, (double)*Point, (double)Point[1]);
    v9 = 1;
  }
  else
  {
LABEL_12:
    v9 = 0;
  }
  v15 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  return v9;
}
