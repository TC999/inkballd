//----- (010061C3) --------------------------------------------------------
void CBall::SetXVel(CBall* self, long double a2)
{
  long double v3; // st7
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::SetXVel", 0);
  if ( fabs(a2) > 400.0 )
    v3 = 400.0 * (*((double *)self + 8) / fabs(*((double *)self + 8)));
  else
    v3 = a2;
  *((long double *)self + 8) = v3;
  ((Helpers::CLogBlock *)v4)->~CLogBlock();
}
