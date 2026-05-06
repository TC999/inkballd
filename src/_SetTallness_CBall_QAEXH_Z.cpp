void __thiscall CBall::SetTallness(CBall *this, void *a2)
{
  bool v3; // zf
  int v4; // eax
  double v5; // st7
  int v6; // eax
  double v7; // st6
  BallPoints *v8; // ecx
  BallPoints *v9; // edi
  void **v10; // ecx
  _BYTE v11[20]; // [esp+10h] [ebp-18h] BYREF
  int v12; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v11, "CBall::SetTallness", 0);
  v4 = (int)a2 - *((_DWORD *)this + 35);
  v3 = a2 == *((void **)this + 35);
  v12 = 0;
  if ( !v3 )
  {
    v5 = (double)v4;
    v6 = 2 * v4;
    v7 = *((double *)this + 1);
    *((_DWORD *)this + 6) += v6;
    *((_DWORD *)this + 7) += v6;
    *((double *)this + 1) = v7 - v5;
    *((double *)this + 2) = *((double *)this + 2) - v5;
    CBall::CheckBoardBounds(this);
    *((_DWORD *)this + 35) = a2;
    LOBYTE(v12) = 1;
    v8 = (BallPoints *)operator new(4u);
    LOBYTE(v12) = 2;
    if ( v8 )
      v9 = BallPoints::BallPoints(v8, *((_DWORD *)this + 6));
    else
      v9 = 0;
    v10 = (void **)*((_DWORD *)this + 30);
    LOBYTE(v12) = 1;
    if ( v10 )
    {
      BallPoints::`scalar deleting destructor'(v10, 1);
      *((_DWORD *)this + 30) = 0;
    }
    *((_DWORD *)this + 30) = v9;
  }
  v12 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v11);
}
