//----- (010048AD) --------------------------------------------------------
int CBall::Collide(CBall* self, void* a2)
{
  auto _a2 = (int (__stdcall *)(const struct tagRECT *))a2;
  int v3; // ebx
  int v4; // edi
  struct BallPoint *NextPoint; // eax
  int PrevBallPoint; // eax
  int v7; // eax
  int *Point; // eax
  int v9; // esi
  _DWORD v11[4]; // [esp+24h] [ebp-30h] BYREF
  _BYTE v12[8]; // [esp+34h] [ebp-20h] BYREF
  struct tagPOINT v13; // [esp+3Ch] [ebp-18h] BYREF
  int v14; // [esp+44h] [ebp-10h]
  int v15; // [esp+50h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CBall::Collide", 0);
  v15 = 0;
  CBall::InitBallPoints(self);
  v14 = 0;
  v3 = -1;
  v4 = -1;
  CBoardObject::GetCenterPoint(self, &v13);
  NextPoint = (struct BallPoint *)CBall::GetNextPoint(self);
  if ( !NextPoint )
    goto LABEL_12;
  do
  {
    v11[0] = v13.x + *(_DWORD *)NextPoint;
    v11[2] = v13.x + *(_DWORD *)NextPoint;
    v11[1] = v13.y + *((_DWORD *)NextPoint + 1);
    v11[3] = v13.y + *((_DWORD *)NextPoint + 1);
    if ( _a2((const struct tagRECT *)v11) )
    {
      PrevBallPoint = CBall::GetPrevBallPoint(self);
      if ( v4 == -1 )
        v4 = PrevBallPoint;
      v3 = PrevBallPoint;
      v14 = 1;
    }
    NextPoint = (struct BallPoint *)CBall::GetNextPoint(self);
  }
  while ( NextPoint );
  if ( v14 )
  {
    v7 = (v3 + v4) / 2;
    if ( v3 < v4 )
      v7 = (v7 + 16) % 32;
    Point = (int *)(uintptr_t)CBall::GetPoint(self, v7);
    CBall::Deflect(self, (double)*Point, (double)Point[1]);
    v9 = 1;
  }
  else
  {
LABEL_12:
    v9 = 0;
  }
  v15 = -1;
  ((Helpers::CLogBlock *)v12)->~CLogBlock();
  return v9;
}
