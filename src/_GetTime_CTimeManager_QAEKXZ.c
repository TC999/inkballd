unsigned int __thiscall CTimeManager::GetTime(CTimeManager *this)
{
  int v2; // esi
  _BYTE v4[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CTimeManager::GetTime", 0);
  v2 = *((_DWORD *)this + 9);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
