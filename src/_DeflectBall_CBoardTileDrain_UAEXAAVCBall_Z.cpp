void __thiscall CBoardTileDrain::DeflectBall(CBoardTileDrain *this, struct CBall *a2)
{
  int v3; // eax
  LONG right; // ecx
  LONG bottom; // ebx
  int v6; // eax
  int v7; // eax
  char *BitmapRect; // eax
  double v9; // st7
  long double v10; // st6
  long double v11; // st7
  int v12; // eax
  int v13; // ecx
  int v14; // edi
  long double v15; // st6
  void *v16; // eax
  struct tagRECT v17; // [esp+18h] [ebp-40h] BYREF
  _BYTE v18[8]; // [esp+28h] [ebp-30h] BYREF
  long double v19; // [esp+30h] [ebp-28h]
  struct tagPOINT v20; // [esp+38h] [ebp-20h] BYREF
  LONG v21; // [esp+40h] [ebp-18h]
  int v22; // [esp+44h] [ebp-14h]
  int v23; // [esp+48h] [ebp-10h]
  int v24; // [esp+54h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v18, "CBoardTileDrain::DeflectBall", 0);
  v24 = 0;
  CBoardObject::GetBoundingRect(this, &v17);
  v3 = *((_DWORD *)this + 17);
  if ( v3 == 2 || (right = v17.left, v3 == 4) )
    right = v17.right;
  v21 = right;
  if ( v3 == 2 || (bottom = v17.top, v3 == 3) )
    bottom = v17.bottom;
  CBoardObject::GetCenterPoint(a2, &v20);
  v22 = v20.y - bottom;
  v23 = v20.x - v21;
  v19 = sqrt((double)((v20.x - v21) * (v20.x - v21) + (v20.y - bottom) * (v20.y - bottom)));
  v6 = *((_DWORD *)a2 + 11);
  if ( v19 > 42.0 )
    v7 = v6 + 2;
  else
    v7 = v6 + 7;
  BitmapRect = CBitmapRects::GetBitmapRect(g_CBitmapRects, v7);
  v9 = (double)*((int *)a2 + 6);
  *((_DWORD *)a2 + 8) = BitmapRect;
  v10 = v9 * 0.5 + v19;
  v11 = v19;
  if ( v10 > 12.0 )
  {
    if ( v19 <= 32.0 )
    {
      v15 = 1.0 / (v19 * v19);
      *((long double *)a2 + 8) = *((double *)a2 + 8) * 0.993 - (double)v23 * v15 * 25.0;
      *((long double *)a2 + 9) = 0.993 * *((double *)a2 + 9) - 25.0 * (v15 * (double)v22);
      v16 = (void *)Round(0.0 - 3.0 / v11 * 8.0);
      CBall::SetTallness(a2, v16);
    }
  }
  else
  {
    v12 = *((_DWORD *)this + 11);
    v13 = *((_DWORD *)a2 + 11);
    if ( v12 != v13 && v12 && v13 )
    {
      KillPlayer(1);
    }
    else
    {
      ScoreBall(a2, *((_DWORD *)this + 11));
      *((_DWORD *)a2 + 39) = 0;
      v14 = *((_DWORD *)this + 11);
      if ( v14 && *((_DWORD *)a2 + 11) )
        ToggleRLWalls(v14);
    }
  }
  v24 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v18);
}
