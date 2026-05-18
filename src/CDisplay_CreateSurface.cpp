//----- (0100F86F) --------------------------------------------------------
int CDisplay::CreateSurface(void* self, void** a2p, void *a3, DWORD a4)
{
  CSurface** a2 = (CSurface**)a2p;
  int v5; // eax
  int v6; // esi
  CSurface *v8; // ecx
  struct CSurface *v9; // eax
  struct _DDSURFACEDESC2 v10; // [esp+10h] [ebp-9Ch] BYREF
  const char *v11[2]; // [esp+8Ch] [ebp-20h] BYREF
  CDisplay *v12; // [esp+94h] [ebp-18h]
  int v13[4]; // [esp+98h] [ebp-14h] BYREF
  int v14; // [esp+A8h] [ebp-4h]

  v12 = (CDisplay*)self;
  v13[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::CreateSurface", v13);
  v14 = 0;
  if ( !a2 )
  {
    v5 = -2147024809;
LABEL_3:
    v6 = v5;
    v13[0] = v5;
    goto LABEL_4;
  }
  if ( !*((_DWORD *)self + 1) )
  {
    v5 = -2147418113;
    goto LABEL_3;
  }
  memset(&v10, 0, sizeof(v10));
  v10.dwWidth = (DWORD)a3;
  v10.dwSize = 124;
  v10.dwFlags = 7;
  v10.ddsCaps.dwCaps = 64;
  v10.dwHeight = a4;
  if ( fPortraitMode() )
    v10.ddsCaps.dwCaps |= 0x800u;
  LOBYTE(v14) = 1;
  v8 = (CSurface *)operator new(0x84u);
  LOBYTE(v14) = 2;
  if ( v8 )
    v9 = new(v8) CSurface();
  else
    v9 = 0;
  *a2 = v9;
  v14 = 0;
  if ( v13[0] >= 0 )
  {
    v13[0] = CSurface::Create(*a2, (LPDIRECTDRAWSURFACE7 *)*a2, *((struct IDirectDraw7 **)v12 + 1), &v10);
    if ( v13[0] < 0 )
    {
      if ( *a2 )
      {
        delete *a2;
        *a2 = 0;
      }
    }
  }
  v6 = v13[0];
LABEL_4:
  v14 = -1;
  ((Helpers::CLogBlock*)v11)->~CLogBlock();
  return v6;
}
