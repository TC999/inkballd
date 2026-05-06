CBoardManager *__thiscall CBoardManager::CBoardManager(CBoardManager *this)
{
  HINSTANCE ResourceW; // eax
  HRSRC v2; // edi
  void *Resource; // ebx
  size_t v4; // edi
  const void *v5; // eax
  int *v7; // [esp+0h] [ebp-28h]
  int *v8; // [esp+0h] [ebp-28h]
  _BYTE v9[8]; // [esp+10h] [ebp-18h] BYREF
  CBoardManager *v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  v10 = this;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CBoardManager::CBoardManager", 0);
  v11 = 0;
  ResourceW = (HINSTANCE)Helpers::FindResourceW(0, (HINSTANCE)0x4E21, L"IKL", 0, v7);
  v2 = (HRSRC)ResourceW;
  if ( ResourceW )
  {
    Resource = Helpers::LoadResource(0, ResourceW, 0, v8);
    if ( Resource )
    {
      v4 = SizeofResource(0, v2);
      v5 = LockResource(Resource);
      if ( v4 <= 0x51C84 )
      {
        if ( v5 )
          memcpy(&g_BoardData, v5, v4);
      }
    }
  }
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
  return v10;
}
