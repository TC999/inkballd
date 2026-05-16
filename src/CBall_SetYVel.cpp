//----- (01006218) --------------------------------------------------------
void __thiscall CBall::SetYVel(CBall *this, long double a2)
{
  long double v3; // st7
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CBall::SetYVel", 0);
  if ( fabs(a2) > 400.0 )
    v3 = 400.0 * (*((double *)this + 9) / fabs(*((double *)this + 9)));
  else
    v3 = a2;
  *((long double *)this + 9) = v3;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
