//----- (01003CBB) --------------------------------------------------------
int CBall::MovingTowards(CBall* self, void* a2)
{
  BOOL v3; // esi
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CBall::MovingTowards", 0);
  v3 = (*((double *)a2 + 2) - *((double *)self + 2)) * *((double *)self + 9)
     + (*((double *)a2 + 1) - *((double *)self + 1)) * *((double *)self + 8) > 0.0;
  ((Helpers::CLogBlock *)v5)->~CLogBlock();
  return v3;
}
