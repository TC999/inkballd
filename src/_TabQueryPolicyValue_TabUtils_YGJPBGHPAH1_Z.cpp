int __stdcall TabUtils::TabQueryPolicyValue(
        LPCWSTR pszValue,
        const unsigned __int16 *pvData,
        _DWORD *a3,
        int *a4,
        int *a5)
{
  int ValueW; // eax
  int v6; // eax
  int v7; // esi
  const char *v9[2]; // [esp+Ch] [ebp-10h] BYREF
  DWORD pcbData; // [esp+14h] [ebp-8h] BYREF
  int v11; // [esp+18h] [ebp-4h] BYREF

  v11 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "TabUtils::TabQueryPolicyValue", &v11);
  if ( pszValue && a3 )
  {
    *a3 = pvData;
    pvData = 0;
    pcbData = 4;
    ValueW = SHRegGetValueW(
               HKEY_LOCAL_MACHINE,
               L"SOFTWARE\\Policies\\Microsoft\\TabletPC",
               pszValue,
               536870936,
               0,
               &pvData,
               &pcbData);
    if ( ValueW )
    {
      if ( ValueW == 2 )
      {
        pcbData = 4;
        pvData = 0;
        v6 = SHRegGetValueW(
               HKEY_CURRENT_USER,
               L"SOFTWARE\\Policies\\Microsoft\\TabletPC",
               pszValue,
               536870936,
               0,
               &pvData,
               &pcbData);
        if ( v6 )
        {
          if ( v6 != 2 )
          {
            if ( v6 > 0 )
              v6 = (unsigned __int16)v6 | 0x80070000;
            v11 = v6;
            if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
              WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xCu, &stru_1003974, v11);
          }
        }
        else
        {
          *a3 = pvData != 0;
          if ( a4 )
            *a4 = 0;
        }
      }
      else
      {
        if ( ValueW > 0 )
          ValueW = (unsigned __int16)ValueW | 0x80070000;
        v11 = ValueW;
        if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
          WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xBu, &stru_1003974, v11);
      }
    }
    else
    {
      *a3 = pvData != 0;
      if ( a4 )
        *a4 = 1;
    }
  }
  else
  {
    v11 = -2147467261;
    if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
      WPP_SF_d(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, &stru_1003974, 3);
  }
  v7 = v11;
  Helpers::CLogBlock::~CLogBlock(v9);
  return v7;
}
