//----- (01003C58) --------------------------------------------------------
void CBall::Deflect(CBall* self, double a2, double a3)
{
  double v4; // st5
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::Deflect", 0);
  v4 = a2 * *((double *)self + 8) + a3 * *((double *)self + 9);
  *((double *)self + 8) = *((double *)self + 8) - a2 * ((v4 + v4) / (a2 * a2 + a3 * a3));
  *((double *)self + 9) = *((double *)self + 9) - (v4 + v4) / (a2 * a2 + a3 * a3) * a3;
  ((Helpers::CLogBlock *)v5)->~CLogBlock();
}
