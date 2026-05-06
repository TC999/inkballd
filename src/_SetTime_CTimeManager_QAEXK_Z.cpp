void __thiscall CTimeManager::SetTime(CTimeManager *this, unsigned int a2)
{
  _BYTE v3[16]; // [esp+10h] [ebp-14h] BYREF
  int v4; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CTimeManager::SetTime", 0);
  v4 = 0;
  *((_DWORD *)this + 13) = 0;
  *((_DWORD *)this + 9) = a2;
  (*(void (__thiscall **)(CTimeManager *))(*(_DWORD *)this + 4))(this);
  v4 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
