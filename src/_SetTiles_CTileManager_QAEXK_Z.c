void __thiscall CTileManager::SetTiles(CTileManager *this, unsigned int a2)
{
  unsigned int v3; // eax
  unsigned int v4; // ecx
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CTileManager::SetTiles", 0);
  v6 = 0;
  if ( a2 )
  {
    v3 = a2 - *((_DWORD *)this + 10);
    v4 = *((_DWORD *)this + 11);
    if ( v3 >= v4 )
    {
      *((_DWORD *)this + 9) += v3 / v4;
      *((_DWORD *)this + 10) = v4 * (a2 / v4);
      (*(void (__fastcall **)(CTileManager *, unsigned int))(*(_DWORD *)this + 4))(this, a2 % v4);
    }
  }
  else
  {
    *((_DWORD *)this + 10) = 0;
  }
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
