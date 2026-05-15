//----- (0100953E) --------------------------------------------------------
void __thiscall CGameBoard::RandomizeBallOrder(CGameBoard *self)
{
  int v2; // ebx
  int v3; // eax
  int *v4; // edi
  int RandomNumber; // eax
  int v6; // ecx
  int *v7; // eax
  int v8; // eax
  char *v9; // ecx
  _BYTE v10[16]; // [esp+10h] [ebp-14h] BYREF
  int v11; // [esp+20h] [ebp-4h]

  v2 = 0;
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v10, "CGameBoard::RandomizeBallOrder", 0);
  v3 = *((_DWORD *)self + 656);
  v11 = 0;
  if ( v3 > 0 )
  {
    v4 = (int *)((char *)self + 2628);
    do
    {
      RandomNumber = CGameBoard::GetRandomNumber(self, v3);
      v6 = *v4;
      v7 = (int *)((char *)self + 4 * RandomNumber + 2628);
      *v4 = *v7;
      *v7 = v6;
      v3 = *((_DWORD *)self + 656);
      ++v2;
      ++v4;
    }
    while ( v2 < v3 );
  }
  v8 = 0;
  if ( *((int *)self + 656) > 0 )
  {
    v9 = (char *)self + 2628;
    do
    {
      *(_DWORD *)(*(_DWORD *)v9 + 164) = v8++;
      v9 += 4;
    }
    while ( v8 < *((_DWORD *)self + 656) );
  }
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v10);
}
