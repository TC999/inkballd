long double __stdcall sind(double a1)
{
  _BYTE v2[8]; // [esp+0h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "sind", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
  return sin(a1 * 0.01745327777777778);
}
