void __thiscall CTileManager::ResetTileCount(CTileManager *this)
{
  int v2; // eax
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CTileManager::ResetTileCount", 0);
  v2 = *(_DWORD *)this;
  v4 = 0;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  (*(void (__thiscall **)(CTileManager *))(v2 + 4))(this);
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
