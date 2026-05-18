//----- (0100EC2E) --------------------------------------------------------
int CDisplay::ConvertGDIColor(void* self, COLORREF color)
{
  int v3; // edi
  bool v4; // zf
  int v6; // eax
  int v7; // eax
  int v8; // eax
  _DWORD v9[21]; // [esp+10h] [ebp-9Ch] BYREF
  unsigned int v10; // [esp+64h] [ebp-48h]
  const char *v11[2]; // [esp+8Ch] [ebp-20h] BYREF
  COLORREF Pixel; // [esp+94h] [ebp-18h]
  int v13; // [esp+98h] [ebp-14h]
  HDC hdc[3]; // [esp+9Ch] [ebp-10h] BYREF
  int v15; // [esp+A8h] [ebp-4h]

  v3 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::ConvertGDIColor", 0);
  v4 = *((_DWORD *)self + 5) == 0;
  v15 = 0;
  if ( !v4 )
  {
    v13 = -1;
    if ( color != -1 )
    {
      v6 = (*(int (__stdcall **)(_DWORD, HDC *))(**((_DWORD **)self + 5) + 68))(*((_DWORD *)self + 5), hdc);
      if ( v6 )
      {
        if ( (uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && (*((uint8_t *)&WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((uint64_t *)&WPP_GLOBAL_Control + 2), 0x22u, &stru_1002FB8, v6);
      }
      else
      {
        Pixel = GetPixel(hdc[0], 0, 0);
        SetPixel(hdc[0], 0, 0, color);
        (*(void (__stdcall **)(_DWORD, HDC))(**((_DWORD **)self + 5) + 104))(*((_DWORD *)self + 5), hdc[0]);
      }
    }
    v7 = *((_DWORD *)self + 5);
    v9[0] = 124;
    if ( !(*(int (__stdcall **)(int, _DWORD, _DWORD *, int, _DWORD))(*(_DWORD *)v7 + 100))(v7, 0, v9, 1, 0) )
    {
      v13 = *(_DWORD *)v9[9];
      if ( v10 < 0x20 )
        v13 &= (1 << v10) - 1;
      (*(void (__stdcall **)(_DWORD, _DWORD))(**((_DWORD **)self + 5) + 128))(*((_DWORD *)self + 5), 0);
    }
    if ( color != -1 )
    {
      v8 = (*(int (__stdcall **)(_DWORD, HDC *))(**((_DWORD **)self + 5) + 68))(*((_DWORD *)self + 5), hdc);
      if ( v8 )
      {
        if ( (uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && (*((uint8_t *)&WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((uint64_t *)&WPP_GLOBAL_Control + 2), 0x23u, &stru_1002FB8, v8);
      }
      else
      {
        SetPixel(hdc[0], 0, 0, Pixel);
        (*(void (__stdcall **)(_DWORD, HDC))(**((_DWORD **)self + 5) + 104))(*((_DWORD *)self + 5), hdc[0]);
      }
    }
    v3 = v13;
  }
  v15 = -1;
  ((Helpers::CLogBlock*)v11)->~CLogBlock();
  return v3;
}
