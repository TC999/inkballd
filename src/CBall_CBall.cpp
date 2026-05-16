//----- (010045D1) --------------------------------------------------------
CBall* CBall_ctor_raw(CBall* self, int a2, int a3, int a4, int a5)
{
  char *v6; // ecx
  BallPoints *v7; // eax
  int i; // eax
  const char *v10[6]; // [esp+10h] [ebp-1Ch] BYREF
  int v11; // [esp+28h] [ebp-4h]

  new (self) CMovingObject();
  *(_DWORD *)self = (uint32_t)(uintptr_t)&CBall_vftable;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBall::CBall", 0);
  v11 = 0;
  *((_DWORD *)self + 34) = 0;
  LOBYTE(v11) = 1;
  v6 = (char *)operator new(4u);
  v10[2] = v6;
  LOBYTE(v11) = 2;
  if ( v6 )
    new (v6) BallPoints();
  v7 = (BallPoints*)v6;
  *((_DWORD *)self + 31) = -1;
  *((_DWORD *)self + 30) = (uint32_t)(uintptr_t)v7;
  *((double *)self + 18) = 1.0;
  *((double *)self + 7) = 1.0;
  *((_DWORD *)self + 11) = a3;
  *((_DWORD *)self + 8) = a2;
  v11 = 0;
  *((_DWORD *)self + 32) = 0;
  *((_DWORD *)self + 33) = 32;
  *((_DWORD *)self + 35) = 0;
  *((_DWORD *)self + 38) = 0;
  *((_DWORD *)self + 6) = a5;
  *((_DWORD *)self + 7) = a5;
  *((_DWORD *)self + 28) = a5;
  *((_DWORD *)self + 29) = a5;
  *((_DWORD *)self + 39) = 0;
  *((_DWORD *)self + 40) = 0;
  for ( i = 0; i < 64; ++i )
    *((_DWORD *)self + i + 42) = 0;
  if ( a4 )
    AddBallToUpdateList(self);
  v11 = -1;
  ((Helpers::CLogBlock *)v10)->~CLogBlock();
  return self;
}
