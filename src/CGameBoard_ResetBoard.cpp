//----- (010093CD) --------------------------------------------------------
void __thiscall CGameBoard::ResetBoard(CGameBoard *self)
{
  CBall **v2; // ebx
  void **v3; // ebx
  _BYTE v4[8]; // [esp+10h] [ebp-18h] BYREF
  int v5; // [esp+18h] [ebp-10h]
  int v6; // [esp+24h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v4, "CGameBoard::ResetBoard", 0);
  v6 = 0;
  *(_DWORD *)self = 0;
  memset((char *)self + 4, 0, 0x4B0u);
  *((_DWORD *)self + 301) = 0;
  memset((char *)self + 1208, 0, 0x100u);
  *((_DWORD *)self + 366) = 0;
  memset((char *)self + 1468, 0, 0x484u);
  *((_DWORD *)self + 656) = 0;
  v2 = (CBall **)((char *)self + 2628);
  v5 = 64;
  do
  {
    if ( *v2 )
    {
      CBall::Release(*v2);
      *v2 = 0;
    }
    ++v2;
    --v5;
  }
  while ( v5 );
  *((_DWORD *)self + 2473) = 0;
  v3 = (void **)((char *)self + 2884);
  v5 = 289;
  do
  {
    if ( *v3 )
    {
      operator delete(*v3);
      *v3 = 0;
    }
    ++v3;
    --v5;
  }
  while ( v5 );
  CInk::ClearInk(*((CInk **)self + 2481));
  CDisplay::ClearInk(g_pDisplay, 0, 0);
  CDisplay::Clear(g_pDisplay, 0);
  v6 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v4);
}
