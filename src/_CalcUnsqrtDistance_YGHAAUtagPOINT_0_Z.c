int __stdcall CalcUnsqrtDistance(struct tagPOINT *a1, struct tagPOINT *a2)
{
  int v2; // eax
  int v3; // esi
  _BYTE v5[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v5, "CalcUnsqrtDistance", 0);
  v2 = a1->y - a2->y;
  v3 = v2 * v2 + (a1->x - a2->x) * (a1->x - a2->x);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v5);
  return v3;
}
