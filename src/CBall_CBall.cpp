//----- (010045D1) --------------------------------------------------------
CBall *__thiscall CBall::CBall(CBall *this, int a2, int a3, int a4, int a5)
{
  char *v6; // ecx
  BallPoints *v7; // eax
  int i; // eax
  const char *v10[6]; // [esp+10h] [ebp-1Ch] BYREF
  int v11; // [esp+28h] [ebp-4h]

  CMovingObject::CMovingObject(this);
  *(_DWORD *)this = &CBall::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBall::CBall", 0);
  v11 = 0;
  *((_DWORD *)this + 34) = 0;
  LOBYTE(v11) = 1;
  v6 = (char *)operator new(4u);
  v10[2] = v6;
  LOBYTE(v11) = 2;
  if ( v6 )
    v7 = BallPoints::BallPoints((BallPoints *)v6, a5);
  else
    v7 = 0;
  *((_DWORD *)this + 31) = -1;
  *((_DWORD *)this + 30) = v7;
  *((double *)this + 18) = 1.0;
  *((double *)this + 7) = 1.0;
  *((_DWORD *)this + 11) = a3;
  *((_DWORD *)this + 8) = a2;
  v11 = 0;
  *((_DWORD *)this + 32) = 0;
  *((_DWORD *)this + 33) = 32;
  *((_DWORD *)this + 35) = 0;
  *((_DWORD *)this + 38) = 0;
  *((_DWORD *)this + 6) = a5;
  *((_DWORD *)this + 7) = a5;
  *((_DWORD *)this + 28) = a5;
  *((_DWORD *)this + 29) = a5;
  *((_DWORD *)this + 39) = 0;
  *((_DWORD *)this + 40) = 0;
  for ( i = 0; i < 64; ++i )
    *((_DWORD *)this + i + 42) = 0;
  if ( a4 )
    AddBallToUpdateList(this);
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock(v10);
  return this;
}
