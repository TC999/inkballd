int __thiscall CSurface::Clear(CSurface *this, unsigned int a2)
{
  int v3; // esi
  int v4; // eax
  int v5; // esi
  _DWORD v7[25]; // [esp+10h] [ebp-7Ch] BYREF
  _BYTE v8[8]; // [esp+74h] [ebp-18h] BYREF
  int v9[3]; // [esp+7Ch] [ebp-10h] BYREF
  int v10; // [esp+88h] [ebp-4h]

  v9[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CSurface::Clear", v9);
  v3 = *(_DWORD *)this;
  v10 = 0;
  if ( v3 )
  {
    memset(v7, 0, sizeof(v7));
    v7[0] = 100;
    v7[20] = a2;
    v4 = (*(int (__stdcall **)(int, _DWORD, _DWORD, _DWORD, int, _DWORD *))(*(_DWORD *)v3 + 20))(v3, 0, 0, 0, 1024, v7);
  }
  else
  {
    v4 = -2147467261;
  }
  v10 = -1;
  v5 = v4;
  v9[0] = v4;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
  return v5;
}
