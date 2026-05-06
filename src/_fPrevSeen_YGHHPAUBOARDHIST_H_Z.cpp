int __stdcall fPrevSeen(int a1, struct BOARDHIST *a2, int a3)
{
  int v3; // edx
  int v4; // ecx
  int v5; // ecx
  int v6; // esi
  _BYTE v8[16]; // [esp+10h] [ebp-14h] BYREF
  int v9; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "fPrevSeen", 0);
  v3 = *((_DWORD *)a2 + 10);
  v4 = 0;
  if ( v3 <= 0 )
  {
LABEL_4:
    if ( (unsigned int)v3 < 0xA && v3 + 1 < a3 )
      *((_DWORD *)a2 + 10) = v3 + 1;
    v5 = *((_DWORD *)a2 + 10);
    if ( v5 > 1 )
    {
      while ( --v5 > 0 )
        *((_DWORD *)a2 + v5) = *((_DWORD *)a2 + v5 - 1);
    }
    *(_DWORD *)a2 = a1;
    v6 = 0;
  }
  else
  {
    while ( a1 != *((_DWORD *)a2 + v4) )
    {
      if ( ++v4 >= v3 )
        goto LABEL_4;
    }
    v6 = 1;
  }
  v9 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v6;
}
