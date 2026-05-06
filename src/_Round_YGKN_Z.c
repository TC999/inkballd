unsigned int __stdcall Round(double X)
{
  double v1; // st7
  double Y; // [esp+1Ch] [ebp-1Ch] BYREF
  _BYTE v4[16]; // [esp+24h] [ebp-14h] BYREF
  int v5; // [esp+34h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "Round", 0);
  if ( _modf(X, &Y) < 0.5 )
    v1 = floor(X);
  else
    v1 = _ceil(X);
  v5 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return (unsigned __int64)v1;
}
