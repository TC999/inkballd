//----- (01004F54) --------------------------------------------------------
void __thiscall CBallManager::UpdateBallPositions(CBallManager *this, unsigned int a2)
{
  double v3; // st7
  int v4; // eax
  double v5; // st6
  char *v6; // ecx
  int v7; // eax
  _BYTE v8[8]; // [esp+4h] [ebp-8h] BYREF
  signed int i; // [esp+14h] [ebp+8h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBallManager::UpdateBallPositions", 0);
  v3 = (double)a2 / 1000.0;
  v4 = *((_DWORD *)this + 14);
  if ( *(double *)(v4 + 8) > 6.0 )
  {
    v5 = 0.0;
    *(double *)(v4 + 64) = *(double *)(v4 + 64) - 6.0;
    *(double *)(*((_DWORD *)this + 14) + 8) = *(double *)(*((_DWORD *)this + 14) + 64) * v3
                                            + *(double *)(*((_DWORD *)this + 14) + 8);
    *(double *)(*((_DWORD *)this + 14) + 16) = *(double *)(*((_DWORD *)this + 14) + 72) * v3
                                             + *(double *)(*((_DWORD *)this + 14) + 16);
  }
  else
  {
    *(double *)(v4 + 64) = 0.0;
    v5 = 0.0;
    *(double *)(*((_DWORD *)this + 14) + 8) = 6.0;
  }
  v6 = (char *)this + 60;
  for ( i = 5; i > 0; --i )
  {
    v7 = *(_DWORD *)v6;
    if ( (double)*(int *)(*((_DWORD *)v6 - 1) + 24) + *(double *)(*((_DWORD *)v6 - 1) + 8) + v5 < *(double *)(*(_DWORD *)v6 + 8) )
    {
      *(double *)(v7 + 64) = *(double *)(v7 + 64) - (double)i;
      *(double *)(*(_DWORD *)v6 + 8) = *(double *)(*(_DWORD *)v6 + 64) * v3 + *(double *)(*(_DWORD *)v6 + 8);
      *(double *)(*(_DWORD *)v6 + 16) = *(double *)(*(_DWORD *)v6 + 72) * v3 + *(double *)(*(_DWORD *)v6 + 16);
    }
    else
    {
      *(double *)(v7 + 64) = v5;
      *(double *)(*(_DWORD *)v6 + 8) = (double)*(int *)(*((_DWORD *)v6 - 1) + 24)
                                     + *(double *)(*((_DWORD *)v6 - 1) + 8)
                                     + v5;
    }
    v6 += 4;
  }
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
