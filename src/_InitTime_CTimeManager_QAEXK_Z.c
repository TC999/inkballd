void __thiscall CTimeManager::InitTime(CTimeManager *this, unsigned int a2)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CTimeManager::InitTime", 0);
  *((_DWORD *)this + 9) = a2;
  if ( a2 != -1 && a2 > 0xF3E58 )
    *((_DWORD *)this + 9) = 999000;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 14) = 0;
  *((_DWORD *)this + 12) = 1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
