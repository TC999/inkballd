int __thiscall CTileManager::GetTileCount(CTileManager *this)
{
  int v2; // eax
  int v3; // esi
  _BYTE v5[16]; // [esp+10h] [ebp-14h] BYREF
  int v6; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CTileManager::GetTileCount", 0);
  v2 = *((_DWORD *)this + 9);
  v6 = 0;
  if ( v2 )
  {
    *((_DWORD *)this + 9) = v2 - 1;
    (*(void (__thiscall **)(CTileManager *))(*(_DWORD *)this + 4))(this);
    v3 = 1;
  }
  else
  {
    v3 = 0;
  }
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v3;
}
