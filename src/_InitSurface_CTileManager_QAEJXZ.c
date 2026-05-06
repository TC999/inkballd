int __thiscall CTileManager::InitSurface(CTileManager *this)
{
  int Surface; // eax
  int v3; // esi
  void *v5; // [esp-8h] [ebp-30h]
  unsigned int v6; // [esp-4h] [ebp-2Ch]
  _BYTE v7[8]; // [esp+10h] [ebp-18h] BYREF
  int v8[3]; // [esp+18h] [ebp-10h] BYREF
  int v9; // [esp+24h] [ebp-4h]

  v8[0] = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CTileManager::InitSurface", v8);
  v6 = *((_DWORD *)this + 4);
  v5 = (void *)*((_DWORD *)this + 3);
  v9 = 0;
  Surface = CDisplay::CreateSurface(g_pDisplay, &g_pTileManagerSurface, v5, v6);
  v9 = -1;
  v8[0] = Surface;
  v3 = Surface;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
  return v3;
}
