void __thiscall CRegistryManager::WriteDifficulty(CRegistryManager *this, BYTE Data)
{
  _BYTE v2[16]; // [esp+10h] [ebp-14h] BYREF
  int v3; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CRegistryManager::WriteDifficulty", 0);
  v3 = 0;
  if ( !WriteRegValueDWORD(HKEY_CURRENT_USER, (HKEY)&SubKey, (HKEY)&stru_1002CD8, Data) )
  {
    CreateInkballKey();
    WriteRegValueDWORD(HKEY_CURRENT_USER, (HKEY)&SubKey, (HKEY)&stru_1002CD8, Data);
  }
  v3 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
