//----- (01012C05) --------------------------------------------------------
Helpers::CLogBlock *__thiscall Helpers::CLogBlock::CLogBlock(Helpers::CLogBlock *this, const char *a2, int *a3)
{
  *((_DWORD *)this + 1) = a2;
  *(_DWORD *)this = a3;
  if ( WPP_GLOBAL_Control != &WPP_GLOBAL_Control && (*((_WORD *)WPP_GLOBAL_Control + 14) & 0x400) != 0 )
    WPP_SF_s(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xAu, &stru_10036F8, a2);
  return this;
}
