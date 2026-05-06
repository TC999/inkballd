int __thiscall CBall::CBall(int this, int a2, int a3, int a4, int a5)
{
  void *v6; // ecx
  BallPoints *v7; // eax
  int i; // eax
  _BYTE v10[8]; // [esp+10h] [ebp-1Ch] BYREF
  void *v11; // [esp+18h] [ebp-14h]
  int v12; // [esp+28h] [ebp-4h]

  CMovingObject::CMovingObject((CMovingObject *)this);
  *(_DWORD *)this = &CBall::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CBall::CBall", 0);
  v12 = 0;
  *(_DWORD *)(this + 136) = 0;
  LOBYTE(v12) = 1;
  v6 = operator new(4u);
  v11 = v6;
  LOBYTE(v12) = 2;
  if ( v6 )
    v7 = BallPoints::BallPoints((BallPoints *)v6, a5);
  else
    v7 = 0;
  *(_DWORD *)(this + 124) = -1;
  *(_DWORD *)(this + 120) = v7;
  *(double *)(this + 144) = 1.0;
  *(double *)(this + 56) = 1.0;
  *(_DWORD *)(this + 44) = a3;
  *(_DWORD *)(this + 32) = a2;
  v12 = 0;
  *(_DWORD *)(this + 128) = 0;
  *(_DWORD *)(this + 132) = 32;
  *(_DWORD *)(this + 140) = 0;
  *(_DWORD *)(this + 152) = 0;
  *(_DWORD *)(this + 24) = a5;
  *(_DWORD *)(this + 28) = a5;
  *(_DWORD *)(this + 112) = a5;
  *(_DWORD *)(this + 116) = a5;
  *(_DWORD *)(this + 156) = 0;
  *(_DWORD *)(this + 160) = 0;
  for ( i = 0; i < 64; ++i )
    *(_DWORD *)(this + 4 * i + 168) = 0;
  if ( a4 )
    AddBallToUpdateList((struct CBall *)this);
  v12 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
  return this;
}
