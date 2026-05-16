//----- (01009B11) --------------------------------------------------------
void CBallManager::Init(CBallManager *self, int a2, int a3, unsigned int a4, int a5, int a6)
{
  _BYTE v7[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "CBallManager::Init", 0);
  *((_DWORD *)self + 20) = 0;
  *((_DWORD *)self + 9) = a2;
  *((_DWORD *)self + 10) = a3;
  *((_DWORD *)self + 11) = a4;
  *((_DWORD *)self + 324) = a5;
  *((_DWORD *)self + 325) = a6;
  memset((char *)self + 84, 0, 0x4B0u);
  *((_DWORD *)self + 323) = 0;
  *((_DWORD *)self + 321) = 1;
  *((_DWORD *)self + 322) = 4000;
  ((Helpers::CLogBlock *)v7)->~CLogBlock();
}
