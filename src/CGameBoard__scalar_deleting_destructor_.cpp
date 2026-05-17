//----- (01009BE7) --------------------------------------------------------
CGameBoard *__thiscall CGameBoard::`scalar deleting destructor'(CGameBoard *this, char a2)
{
  CGameBoard::~CGameBoard(this);
  if ( (a2 & 1) != 0 )
    operator delete(this);
  return this;
}
