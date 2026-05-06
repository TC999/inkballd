struct tagRECT *__thiscall CGameBoard::GetPlayingAreaRect(CGameBoard *this)
{
  _BYTE v3[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CGameBoard::GetPlayingAreaRect", 0);
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
  return (struct tagRECT *)((char *)this + 4040);
}
