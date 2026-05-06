int __thiscall CDisplay::BltToBoard(
        CDisplay *this,
        unsigned int a2,
        unsigned int a3,
        struct CSurface *a4,
        struct tagRECT *a5)
{
  int IsColorKeyed; // eax
  int v7; // edi
  struct IDirectDrawSurface7 *DDrawSurface; // eax
  int v9; // eax
  int v10; // esi
  BOOL v12; // [esp-4h] [ebp-2Ch]
  _BYTE v13[8]; // [esp+10h] [ebp-18h] BYREF
  int v14[3]; // [esp+18h] [ebp-10h] BYREF
  int v15; // [esp+24h] [ebp-4h]

  v14[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CDisplay::BltToBoard", v14);
  v15 = 0;
  if ( !a4 )
    v14[0] = -2147024809;
  IsColorKeyed = CSurface::IsColorKeyed(a4);
  v7 = **((_DWORD **)this + 6);
  v12 = IsColorKeyed != 0;
  DDrawSurface = CSurface::GetDDrawSurface(a4);
  v9 = (*(int (__stdcall **)(_DWORD, unsigned int, unsigned int, struct IDirectDrawSurface7 *, struct tagRECT *, BOOL))(v7 + 28))(
         *((_DWORD *)this + 6),
         a2,
         a3,
         DDrawSurface,
         a5,
         v12);
  v15 = -1;
  v14[0] = v9;
  v10 = v9;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
  return v10;
}
