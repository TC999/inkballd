BOOL __stdcall WriteRegValueDWORD(HKEY hKey, HKEY lpSubKey, HKEY lpValueName, BYTE Data)
{
  BOOL v4; // edi
  int *v6; // [esp+0h] [ebp-28h]
  int *v7; // [esp+0h] [ebp-28h]
  int *v8; // [esp+0h] [ebp-28h]
  _BYTE v9[8]; // [esp+10h] [ebp-18h] BYREF
  HKEY phkResult; // [esp+18h] [ebp-10h] BYREF
  int v11; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "WriteRegValueDWORD", 0);
  v11 = 0;
  v4 = 0;
  if ( !Helpers::RegOpenKeyExW(hKey, lpSubKey, 0, 0x2001Fu, &phkResult, 0, v6) )
  {
    v4 = Helpers::RegSetValueExW(phkResult, lpValueName, 0, 4u, &Data, 4u, 0, v7) == 0;
    Helpers::RegCloseKey(phkResult, 0, v8);
  }
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
  return v4;
}
