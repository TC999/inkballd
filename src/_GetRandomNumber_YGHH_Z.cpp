int __stdcall GetRandomNumber(int a1)
{
  int RandomNumber; // eax
  int v2; // esi
  _BYTE v4[16]; // [esp+10h] [ebp-14h] BYREF
  int v5; // [esp+20h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "GetRandomNumber", 0);
  v5 = 0;
  RandomNumber = CGameBoard::GetRandomNumber(g_pCGameBoard, a1);
  v5 = -1;
  v2 = RandomNumber;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
  return v2;
}
