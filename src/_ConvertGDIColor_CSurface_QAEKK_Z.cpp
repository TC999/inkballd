int __thiscall CSurface::ConvertGDIColor(CSurface *this, COLORREF color)
{
  int v3; // edi
  int v4; // eax
  bool v5; // zf
  int v7; // eax
  int v8; // eax
  int v9; // eax
  _DWORD v10[21]; // [esp+10h] [ebp-9Ch] BYREF
  unsigned int v11; // [esp+64h] [ebp-48h]
  _BYTE v12[8]; // [esp+8Ch] [ebp-20h] BYREF
  COLORREF Pixel; // [esp+94h] [ebp-18h]
  int v14; // [esp+98h] [ebp-14h]
  HDC hdc[3]; // [esp+9Ch] [ebp-10h] BYREF
  int v16; // [esp+A8h] [ebp-4h]

  v3 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v12, "CSurface::ConvertGDIColor", 0);
  v4 = *(_DWORD *)this;
  v5 = *(_DWORD *)this == 0;
  v16 = 0;
  if ( !v5 )
  {
    v14 = -1;
    if ( color != -1 )
    {
      v7 = (*(int (__stdcall **)(int, HDC *))(*(_DWORD *)v4 + 68))(v4, hdc);
      if ( v7 )
      {
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Bu, &stru_1002FB8, v7);
      }
      else
      {
        Pixel = GetPixel(hdc[0], 0, 0);
        SetPixel(hdc[0], 0, 0, color);
        (*(void (__stdcall **)(_DWORD, HDC))(**(_DWORD **)this + 104))(*(_DWORD *)this, hdc[0]);
      }
    }
    v8 = *(_DWORD *)this;
    v10[0] = 124;
    if ( !(*(int (__stdcall **)(int, _DWORD, _DWORD *, int, _DWORD))(*(_DWORD *)v8 + 100))(v8, 0, v10, 1, 0) )
    {
      v14 = *(_DWORD *)v10[9];
      if ( v11 < 0x20 )
        v14 &= (1 << v11) - 1;
      (*(void (__stdcall **)(_DWORD, _DWORD))(**(_DWORD **)this + 128))(*(_DWORD *)this, 0);
    }
    if ( color != -1 )
    {
      v9 = (*(int (__stdcall **)(_DWORD, HDC *))(**(_DWORD **)this + 68))(*(_DWORD *)this, hdc);
      if ( v9 )
      {
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x2Cu, &stru_1002FB8, v9);
      }
      else
      {
        SetPixel(hdc[0], 0, 0, Pixel);
        (*(void (__stdcall **)(_DWORD, HDC))(**(_DWORD **)this + 104))(*(_DWORD *)this, hdc[0]);
      }
    }
    v3 = v14;
  }
  v16 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v12);
  return v3;
}
