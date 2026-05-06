int __thiscall CBall::Collide(CBall *this, struct CBall *a2)
{
  int v3; // ebx
  double v4; // st7
  double v5; // st6
  double v6; // st5
  double v7; // st7
  double v8; // st4
  double v9; // st6
  long double v10; // st7
  long double v11; // st6
  long double v12; // st7
  long double v13; // st5
  long double v14; // st5
  _BYTE v16[8]; // [esp+10h] [ebp-24h] BYREF
  double v17; // [esp+18h] [ebp-1Ch]
  double v18; // [esp+20h] [ebp-14h]
  int v19; // [esp+30h] [ebp-4h]

  v3 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v16, "CBall::Collide", 0);
  v19 = 0;
  if ( !CBall::BallsIntersect(this, a2) )
    goto LABEL_4;
  v3 = 1;
  if ( CBall::MovingTowards(this, a2) )
  {
    v4 = (double)*((int *)this + 6) * 0.5;
    v5 = 0.5 * (double)*((int *)a2 + 6);
    v6 = *((double *)this + 1) + v4;
    v7 = v4 + *((double *)this + 2);
    v8 = *((double *)a2 + 1) + v5;
    v9 = v5 + *((double *)a2 + 2);
    v18 = v6 - v8;
    v17 = v7 - v9;
    v10 = sqrt(v17 * v17 + v18 * v18);
    v11 = v18 / v10;
    v12 = v17 / v10;
    v13 = v12 * *((double *)this + 9)
        + v11 * *((double *)this + 8)
        - (*((double *)a2 + 9) * v12
         + *((double *)a2 + 8) * v11);
    v14 = (v13 + v13) / (*((double *)this + 7) + *((double *)a2 + 7));
    *((long double *)this + 8) = *((double *)this + 8) - *((double *)a2 + 7) * v14 * v11;
    *((long double *)this + 9) = *((double *)this + 9) - *((double *)a2 + 7) * v14 * v12;
    *((long double *)a2 + 8) = v11 * (*((double *)this + 7) * v14) + *((double *)a2 + 8);
    *((long double *)a2 + 9) = v12 * (v14 * *((double *)this + 7)) + *((double *)a2 + 9);
LABEL_4:
    *((_DWORD *)this + *((_DWORD *)a2 + 41) + 42) = v3;
    *((_DWORD *)a2 + *((_DWORD *)this + 41) + 42) = v3;
  }
  v19 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v16);
  return v3;
}
