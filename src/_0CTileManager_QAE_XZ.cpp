CTileManager *__thiscall CTileManager::CTileManager(CTileManager *this)
{
  _BYTE pExceptionObject[12]; // [esp+10h] [ebp-20h] BYREF
  _BYTE v4[16]; // [esp+1Ch] [ebp-14h] BYREF
  int v5; // [esp+2Ch] [ebp-4h]

  *(_DWORD *)this = &CTileManager::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CTileManager::CTileManager", 0);
  *((_DWORD *)this + 1) = 445;
  *((_DWORD *)this + 5) = 445;
  v5 = 0;
  *((_DWORD *)this + 2) = 0;
  *((_DWORD *)this + 3) = 42;
  *((_DWORD *)this + 4) = 42;
  *((_DWORD *)this + 6) = 0;
  *((_DWORD *)this + 7) = 487;
  *((_DWORD *)this + 8) = 42;
  if ( CTileManager::InitSurface(this) < 0 )
  {
    std::bad_alloc::bad_alloc((std::bad_alloc *)pExceptionObject);
    _CxxThrowException(pExceptionObject, (_ThrowInfo *)&_TI2_AVbad_alloc_std__);
  }
  v5 = -1;
  *((_DWORD *)this + 9) = 0;
  *((_DWORD *)this + 10) = 0;
  *((_DWORD *)this + 11) = 1600;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return this;
}
