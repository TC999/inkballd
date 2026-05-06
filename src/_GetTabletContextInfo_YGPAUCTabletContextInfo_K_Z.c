struct CTabletContextInfo *__stdcall GetTabletContextInfo(unsigned int a1)
{
  char *v1; // edi
  int v2; // eax
  _DWORD *v3; // esi
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  v1 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "GetTabletContextInfo", 0);
  v2 = 0;
  if ( dword_10B068C > 0 )
  {
    v3 = (char *)g_arrTCI + 8;
    while ( *v3 != a1 )
    {
      ++v2;
      v3 += 6;
      if ( v2 >= dword_10B068C )
        goto LABEL_7;
    }
    v1 = (char *)g_arrTCI + 24 * v2;
  }
LABEL_7:
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return (struct CTabletContextInfo *)v1;
}
