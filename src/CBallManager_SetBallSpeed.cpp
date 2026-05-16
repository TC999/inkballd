//----- (01005278) --------------------------------------------------------
void __thiscall CBallManager::SetBallSpeed(CBallManager *this, struct CBall *a2, double a3)
{
  int v4; // eax
  int v5; // ecx
  double v6; // st7
  struct CBall *v7; // esi
  double v8; // st7
  double v9; // st7
  double v10; // st7
  double v11; // st7
  double v12; // st7
  _BYTE v13[8]; // [esp+18h] [ebp-1Ch] BYREF
  double v14; // [esp+20h] [ebp-14h]
  int v15; // [esp+30h] [ebp-4h]
  double v16; // [esp+40h] [ebp+Ch]
  double v17; // [esp+40h] [ebp+Ch]
  double v18; // [esp+40h] [ebp+Ch]
  double v19; // [esp+40h] [ebp+Ch]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v13, "CBallManager::SetBallSpeed", 0);
  v4 = *((_DWORD *)this + 325);
  v5 = *((_DWORD *)this + 324);
  v15 = 0;
  HIDWORD(v14) = v4;
  if ( v4 != v5 )
    HIDWORD(v14) = *((_DWORD *)this + 324) + GetRandomNumber(v4 - v5);
  v14 = (double)SHIDWORD(v14);
  v6 = a3;
  if ( a3 != -1.0 )
  {
    if ( 0.0 == a3 )
      v6 = 360.0;
    if ( v6 <= 90.0 )
    {
      v16 = 90.0 - v6;
      v7 = a2;
      *((double *)a2 + 8) = cosd(v16) * v14;
      v10 = sind(v16);
LABEL_18:
      v9 = v10 * v14;
      goto LABEL_19;
    }
    if ( v6 > 180.0 )
    {
      if ( v6 > 270.0 )
      {
        v19 = 360.0 - v6;
        v7 = a2;
        *((double *)a2 + 8) = -(sind(v19) * v14);
        v10 = cosd(v19);
        goto LABEL_18;
      }
      v18 = 270.0 - v6;
      v7 = a2;
      *((double *)a2 + 8) = -(cosd(v18) * v14);
      v11 = sind(v18);
    }
    else
    {
      v17 = 180.0 - v6;
      v7 = a2;
      *((double *)a2 + 8) = sind(v17) * v14;
      v11 = cosd(v17);
    }
    v12 = v11 * v14;
LABEL_20:
    *((double *)v7 + 9) = v12;
    goto LABEL_21;
  }
  v7 = a2;
  v8 = (double)GetRandomNumber(100) / 100.0 * v14;
  *((double *)a2 + 8) = v8;
  *((long double *)a2 + 9) = sqrt(v14 * v14 - v8 * v8);
  if ( GetRandomNumber(2) )
    *((double *)a2 + 8) = -*((double *)a2 + 8);
  if ( GetRandomNumber(2) )
  {
    v9 = *((double *)a2 + 9);
LABEL_19:
    v12 = -v9;
    goto LABEL_20;
  }
LABEL_21:
  v15 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v13);
}
