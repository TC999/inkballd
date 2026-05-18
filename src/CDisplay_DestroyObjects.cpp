//----- (0100E213) --------------------------------------------------------
int CDisplay::DestroyObjects(void* self)
{
  int v2; // eax
  int v3; // eax
  int v4; // eax
  int v5; // eax
  int v6; // eax
  int v7; // eax
  int v8; // eax
  int v9; // esi
  const char *v11[2]; // [esp+10h] [ebp-18h] BYREF
  char v12[4]; // [esp+18h] [ebp-10h] BYREF
  int v13; // [esp+24h] [ebp-4h]

  *(_DWORD *)v12 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CDisplay::DestroyObjects", (int *)v12);
  v2 = *((_DWORD *)self + 6);
  v13 = 0;
  if ( v2 )
  {
    (*(void (__stdcall **)(int))(*(_DWORD *)v2 + 8))(v2);
    *((_DWORD *)self + 6) = 0;
  }
  v3 = *((_DWORD *)self + 5);
  if ( v3 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v3 + 8))(*((_DWORD *)self + 5));
    *((_DWORD *)self + 5) = 0;
  }
  v4 = *((_DWORD *)self + 4);
  if ( v4 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v4 + 8))(*((_DWORD *)self + 4));
    *((_DWORD *)self + 4) = 0;
  }
  v5 = *((_DWORD *)self + 3);
  if ( v5 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v5 + 8))(*((_DWORD *)self + 3));
    *((_DWORD *)self + 3) = 0;
  }
  v6 = *((_DWORD *)self + 2);
  if ( v6 )
  {
    (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v6 + 8))(*((_DWORD *)self + 2));
    *((_DWORD *)self + 2) = 0;
  }
  v7 = *((_DWORD *)self + 1);
  if ( v7 )
  {
    *(_DWORD *)v12 = (*(int (__stdcall **)(int, _DWORD, int))(*(_DWORD *)v7 + 80))(v7, *((_DWORD *)self + 7), 8);
    if ( *(int *)v12 < 0 && (uintptr_t)WPP_GLOBAL_Control != (uintptr_t)&WPP_GLOBAL_Control && (*((uint8_t *)&WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((uint64_t *)&WPP_GLOBAL_Control + 2), 0xAu, &stru_1002FB8, v12[0]);
    v8 = *((_DWORD *)self + 1);
    if ( v8 )
    {
      (*(void (__stdcall **)(_DWORD))(*(_DWORD *)v8 + 8))(*((_DWORD *)self + 1));
      *((_DWORD *)self + 1) = 0;
    }
  }
  v9 = *(_DWORD *)v12;
  v13 = -1;
  ((Helpers::CLogBlock*)v11)->~CLogBlock();
  return v9;
}
