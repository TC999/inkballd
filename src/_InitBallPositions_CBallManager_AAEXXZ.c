void __thiscall CBallManager::InitBallPositions(CBallManager *this)
{
  char *v2; // eax
  int v3; // edx
  int v4; // ecx
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBallManager::InitBallPositions", 0);
  *(double *)(*((_DWORD *)this + 14) + 8) = 104.0;
  *(double *)(*((_DWORD *)this + 14) + 16) = 14.0;
  v2 = (char *)this + 60;
  v3 = 5;
  do
  {
    *(double *)(*(_DWORD *)v2 + 8) = (double)*(int *)(*((_DWORD *)v2 - 1) + 24)
                                   + *(double *)(*((_DWORD *)v2 - 1) + 8)
                                   + 0.0;
    v4 = *(_DWORD *)v2;
    v2 += 4;
    *(double *)(v4 + 16) = 14.0;
    *((_DWORD *)this + 13) = 0;
    --v3;
  }
  while ( v3 );
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
}
