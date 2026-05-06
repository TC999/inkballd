struct IDirectDrawSurface7 *__thiscall CSurface::GetDDrawSurface(CSurface *this)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CSurface::GetDDrawSurface", 0);
  v2 = *(_DWORD *)this;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return (struct IDirectDrawSurface7 *)v2;
}
