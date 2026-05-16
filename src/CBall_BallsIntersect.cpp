//----- (01003FFF) --------------------------------------------------------
int CBall::BallsIntersect(CBall* self, CBall* a2)
{
  double v3; // st5
  double v4; // st6
  double v5; // st5
  BOOL v6; // esi
  _BYTE v8[8]; // [esp+8h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBall::BallsIntersect", 0);
  v3 = *((double *)self + 2) - *((double *)a2 + 2);
  v4 = v3 * v3;
  v5 = *((double *)self + 1) - *((double *)a2 + 1);
  v6 = (double)*((int *)a2 + 6) * 0.5 + 0.5 * (double)*((int *)self + 6) > sqrt(v5 * v5 + v4);
  ((Helpers::CLogBlock *)v8)->~CLogBlock();
  return v6;
}
