void __thiscall CSurface::~CSurface(CSurface *this)
{
  int v2; // eax
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CSurface::~CSurface", 0);
  v2 = *(_DWORD *)this;
  v4 = 0;
  if ( v2 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
    *(_DWORD *)this = 0;
  }
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
