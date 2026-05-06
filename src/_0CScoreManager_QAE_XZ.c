CScoreManager *__thiscall CScoreManager::CScoreManager(CScoreManager *this)
{
  int HiScore; // eax
  _BYTE pExceptionObject[12]; // [esp+10h] [ebp-20h] BYREF
  _BYTE v5[16]; // [esp+1Ch] [ebp-14h] BYREF
  int v6; // [esp+2Ch] [ebp-4h]

  *(_DWORD *)this = &CScoreManager::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CScoreManager::CScoreManager", 0);
  *((_DWORD *)this + 1) = 104;
  *((_DWORD *)this + 5) = 104;
  v6 = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 341;
  *((_DWORD *)this + 4) = 42;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 445;
  *((_DWORD *)this + 8) = 42;
  if ( CScoreManager::InitSurface(this) < 0 )
  {
    std::bad_alloc::bad_alloc((std::bad_alloc *)pExceptionObject);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  CSurface::Clear(g_pScoreManagerSurface, 0);
  *((_DWORD *)this + 10) = 0;
  HiScore = CRegistryManager::ReadHiScore((CRegistryManager *)&g_CRegistryManager);
  v6 = -1;
  *((_DWORD *)this + 9) = HiScore;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return this;
}
