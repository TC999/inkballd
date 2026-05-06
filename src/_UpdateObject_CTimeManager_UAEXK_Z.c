void __thiscall CTimeManager::UpdateObject(CTimeManager *this, unsigned int a2)
{
  bool v3; // zf
  unsigned int v4; // ecx
  unsigned int v5; // ecx
  unsigned int v6; // ecx
  unsigned int v7; // eax
  unsigned int v8; // eax
  _BYTE v9[8]; // [esp+10h] [ebp-18h] BYREF
  int v10; // [esp+18h] [ebp-10h]
  int v11; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v9, "CTimeManager::UpdateObject", 0);
  v3 = *((_DWORD *)this + 14) == 0;
  v11 = 0;
  v10 = 0;
  if ( !v3 )
  {
    if ( *((_DWORD *)this + 13) )
    {
      KillPlayer(0);
    }
    else
    {
      v4 = *((_DWORD *)this + 9);
      if ( v4 != -1 )
      {
        if ( v4 > a2 )
        {
          v5 = v4 - a2;
          *((_DWORD *)this + 9) = v5;
          if ( v5 < 0x2AF8 )
          {
            *((_DWORD *)this + 10) += a2;
            v6 = *((_DWORD *)this + 10);
            *((_DWORD *)this + 11) += a2;
            v7 = *((_DWORD *)this + 11);
            if ( v6 >= 0x14D )
            {
              v3 = *((_DWORD *)this + 12) == 0;
              *((_DWORD *)this + 10) = 0;
              v10 = 1;
              *((_DWORD *)this + 12) = v3;
            }
            if ( v7 >= 0x3E8 )
              *((_DWORD *)this + 11) = 0;
          }
        }
        else
        {
          *((_DWORD *)this + 9) = 0;
          *((_DWORD *)this + 12) = 1;
        }
      }
    }
    v8 = *((_DWORD *)this + 9);
    if ( v8 >= 0x3E8 || *((_DWORD *)this + 13) )
    {
      v3 = v10 == 1;
      *((_DWORD *)this + 13) = 0;
      if ( !v3 && v8 / 0x3E8 == dword_105C81C / 0x3E8u )
        goto LABEL_18;
    }
    else
    {
      *((_DWORD *)this + 12) = 1;
      *((_DWORD *)this + 13) = 1;
    }
    (*(void (__thiscall **)(CTimeManager *))(*(_DWORD *)this + 4))(this);
LABEL_18:
    dword_105C81C = *((_DWORD *)this + 9);
  }
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
}
