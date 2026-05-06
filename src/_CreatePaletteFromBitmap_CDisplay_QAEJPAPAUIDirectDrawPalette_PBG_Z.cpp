int __thiscall CDisplay::CreatePaletteFromBitmap(CDisplay *this, struct IDirectDrawPalette **a2, WCHAR *lpFileName)
{
  bool v4; // zf
  HINSTANCE ResourceW; // eax
  void *Resource; // eax
  _DWORD *v7; // eax
  int v8; // esi
  bool v9; // cf
  char *v10; // edi
  unsigned __int16 v11; // cx
  int v12; // eax
  unsigned int v13; // edx
  _BYTE *v14; // eax
  _BYTE *v15; // ecx
  _BYTE *v16; // esi
  char *v17; // edi
  HANDLE FileW; // edi
  char LastError; // al
  unsigned int v20; // edi
  unsigned int i; // esi
  char *v22; // ecx
  char *v23; // eax
  char v24; // dl
  char v25; // al
  char v26; // al
  char v27; // al
  int *v29; // [esp+0h] [ebp-46Ch]
  int *v30; // [esp+0h] [ebp-46Ch]
  char v31; // [esp+10h] [ebp-45Ch] BYREF
  char v32; // [esp+11h] [ebp-45Bh] BYREF
  _DWORD v33[255]; // [esp+12h] [ebp-45Ah] BYREF
  char Buffer[16]; // [esp+410h] [ebp-5Ch] BYREF
  int v35[3]; // [esp+420h] [ebp-4Ch] BYREF
  int v36; // [esp+42Eh] [ebp-3Eh]
  unsigned int v37; // [esp+440h] [ebp-2Ch]
  _BYTE v38[8]; // [esp+448h] [ebp-24h] BYREF
  char *v39; // [esp+450h] [ebp-1Ch]
  CDisplay *v40; // [esp+454h] [ebp-18h]
  DWORD NumberOfBytesRead; // [esp+458h] [ebp-14h] BYREF
  char v42[4]; // [esp+45Ch] [ebp-10h] BYREF
  int v43; // [esp+468h] [ebp-4h]
  LPCWSTR lpFileNamea; // [esp+478h] [ebp+Ch]

  v40 = this;
  *(_DWORD *)v42 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v38, "CDisplay::CreatePaletteFromBitmap", (int *)v42);
  v4 = *((_DWORD *)this + 1) == 0;
  v43 = 0;
  if ( v4 || !lpFileName || !a2 )
  {
    v8 = -2147024809;
    *(_DWORD *)v42 = -2147024809;
    goto LABEL_56;
  }
  *a2 = 0;
  ResourceW = (HINSTANCE)Helpers::FindResourceW(0, (HINSTANCE)lpFileName, (LPCWSTR)2, 0, v29);
  if ( !ResourceW )
  {
    FileW = CreateFileW(lpFileName, 0x80000000, 0, 0, 3u, 0, 0);
    if ( FileW == (HANDLE)-1 )
    {
      if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        LastError = GetLastError();
        WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Du, &stru_1002FB8, LastError);
      }
      goto LABEL_6;
    }
    if ( ReadFile(FileW, Buffer, 0xEu, &NumberOfBytesRead, 0) && NumberOfBytesRead == 14 )
    {
      if ( ReadFile(FileW, v35, 0x28u, &NumberOfBytesRead, 0) && NumberOfBytesRead == 40 )
      {
        if ( !ReadFile(FileW, &v31, 0x400u, &NumberOfBytesRead, 0) || NumberOfBytesRead != 1024 )
        {
          if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          {
            v25 = GetLastError();
            WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x20u, &stru_1002FB8, v25);
          }
          Helpers::CloseHandle(FileW, 0, v30);
          goto LABEL_6;
        }
        Helpers::CloseHandle(FileW, 0, v30);
        if ( v35[0] == 40 && (unsigned __int16)v36 <= 8u )
        {
          v20 = v37;
          if ( !v37 )
            v20 = 1 << v36;
        }
        else
        {
          v20 = 0;
        }
        for ( i = 0; i < v20; *v22 = v24 )
        {
          if ( i >= 0x100 )
            break;
          v22 = (char *)&v33[i];
          v23 = &v31 + 4 * i;
          v24 = *v23;
          *v23 = *v22;
          ++i;
        }
        *(_DWORD *)v42 = (*(int (__stdcall **)(_DWORD, int, char *, struct IDirectDrawPalette **, _DWORD))(**((_DWORD **)v40 + 1) + 20))(
                           *((_DWORD *)v40 + 1),
                           4,
                           &v31,
                           a2,
                           0);
        if ( *(int *)v42 < 0
          && WPP_GLOBAL_Control != &WPP_GLOBAL_Control
          && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
        {
          WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x21u, &stru_1002FB8, v42[0]);
        }
LABEL_21:
        v8 = *(_DWORD *)v42;
        goto LABEL_56;
      }
      if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      {
        v26 = GetLastError();
        WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Fu, &stru_1002FB8, v26);
      }
    }
    else if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
    {
      v27 = GetLastError();
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Eu, &stru_1002FB8, v27);
    }
    Helpers::CloseHandle(FileW, 0, v30);
    goto LABEL_6;
  }
  Resource = Helpers::LoadResource(0, ResourceW, 0, v30);
  v7 = LockResource(Resource);
  if ( v7 )
  {
    v9 = *v7 < 0x28u;
    v10 = (char *)v7 + *v7;
    v39 = v10;
    if ( v9 || (v11 = *((_WORD *)v7 + 7), v11 > 8u) )
    {
      lpFileNamea = 0;
    }
    else
    {
      v12 = v7[8];
      if ( !v12 )
        v12 = 1 << v11;
      lpFileNamea = (LPCWSTR)v12;
    }
    v13 = 0;
    if ( lpFileNamea )
    {
      v14 = v10 + 1;
      v15 = (_BYTE *)(&v31 - v10);
      v16 = (_BYTE *)(&v32 - v10);
      v17 = (char *)((char *)v33 - v39);
      do
      {
        if ( v13 >= 0x100 )
          break;
        *(&v31 + 4 * v13) = v14[1];
        v14[(_DWORD)v15] = *v14;
        v14[(_DWORD)v16] = *(v14 - 1);
        v14[(_DWORD)v17] = 0;
        ++v13;
        v14 += 4;
      }
      while ( v13 < (unsigned int)lpFileNamea );
    }
    *(_DWORD *)v42 = (*(int (__stdcall **)(_DWORD, int, char *, struct IDirectDrawPalette **, _DWORD))(**((_DWORD **)v40 + 1) + 20))(
                       *((_DWORD *)v40 + 1),
                       4,
                       &v31,
                       a2,
                       0);
    if ( *(int *)v42 < 0 && WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0x1Cu, &stru_1002FB8, v42[0]);
    goto LABEL_21;
  }
LABEL_6:
  v8 = -2147467259;
  *(_DWORD *)v42 = -2147467259;
LABEL_56:
  v43 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v38);
  return v8;
}
