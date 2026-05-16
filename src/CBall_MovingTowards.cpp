//----- (01003CBB) --------------------------------------------------------
BOOL __thiscall CBall::MovingTowards(CBall *this, struct CBall *a2)
{
  BOOL v3; // esi
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::MovingTowards", 0);
  v3 = (*((double *)a2 + 2) - *((double *)this + 2)) * *((double *)this + 9)
     + (*((double *)a2 + 1) - *((double *)this + 1)) * *((double *)this + 8) > 0.0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v3;
}
