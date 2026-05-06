int __thiscall CDisplay::Blt(CDisplay *this, unsigned int a2, unsigned int a3, struct CSurface *a4, struct tagRECT *a5)
{
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  int v7; // eax
  int v8; // esi
  unsigned int v10; // [esp-4h] [ebp-2Ch]
  _BYTE v11[8]; // [esp+10h] [ebp-18h] BYREF
  int v12[3]; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  v12[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::Blt", v12);
  v13 = 0;
  if ( !a4 )
    v12[0] = -2147024809;
  v10 = CSurface::IsColorKeyed(a4) != 0;
  DDrawSurface = CSurface::GetDDrawSurface(a4);
  v7 = CDisplay::Blt(this, a2, a3, DDrawSurface, a5, v10);
  v13 = -1;
  v12[0] = v7;
  v8 = v7;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
  return v8;
}
