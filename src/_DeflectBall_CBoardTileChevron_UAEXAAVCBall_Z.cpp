void __thiscall CBoardTileChevron::DeflectBall(CBoardTileChevron *this, struct CBall *a2)
{
  int v3; // eax
  double *v4; // ecx
  long double v5; // st7
  double *v6; // ecx
  long double v7; // st7
  _BYTE v8[16]; // [esp+18h] [ebp-14h] BYREF
  int v9; // [esp+28h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v8, "CBoardTileChevron::DeflectBall", 0);
  v3 = *((_DWORD *)this + 22);
  v9 = 0;
  if ( v3 )
  {
    if ( v3 != 1 )
    {
      if ( v3 == 2 )
      {
        v6 = (double *)a2;
        v7 = *((double *)a2 + 8) - 3.0;
      }
      else
      {
        if ( v3 != 3 )
          goto LABEL_11;
        v6 = (double *)a2;
        v7 = *((double *)a2 + 8) + 3.0;
      }
      v6[8] = v7;
      CBall::SetXVel((CBall *)v6, v7);
      goto LABEL_11;
    }
    v4 = (double *)a2;
    v5 = *((double *)a2 + 9) + 3.0;
  }
  else
  {
    v4 = (double *)a2;
    v5 = *((double *)a2 + 9) - 3.0;
  }
  v4[9] = v5;
  CBall::SetYVel((CBall *)v4, v5);
LABEL_11:
  v9 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v8);
}
