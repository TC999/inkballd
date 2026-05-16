//----- (01009B11) --------------------------------------------------------
void __thiscall CBallManager::Init(CBallManager *this, int a2, int a3, unsigned int a4, int a5, int a6)
{
  _BYTE v7[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBallManager::Init", 0);
  *((_DWORD *)this + 20) = 0;
  *((_DWORD *)this + 9) = a2;
  *((_DWORD *)this + 10) = a3;
  *((_DWORD *)this + 11) = a4;
  *((_DWORD *)this + 324) = a5;
  *((_DWORD *)this + 325) = a6;
  memset((char *)this + 84, 0, 0x4B0u);
  *((_DWORD *)this + 323) = 0;
  *((_DWORD *)this + 321) = 1;
  *((_DWORD *)this + 322) = 4000;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v7);
}
