//----- (01012C4B) --------------------------------------------------------
void __thiscall Helpers::CLogBlock::~CLogBlock(const char **this)
{
  const char *v2; // eax
  int v3; // ecx
  PVOID *v4; // eax

  v2 = *this;
  if ( !*this )
    goto LABEL_6;
  v3 = *(_DWORD *)v2;
  if ( *(int *)v2 >= 0 )
    goto LABEL_6;
  v4 = (PVOID *)WPP_GLOBAL_Control;
  if ( WPP_GLOBAL_Control == &WPP_GLOBAL_Control )
    return;
  if ( (*((_BYTE *)WPP_GLOBAL_Control + 28) & 4) != 0 )
  {
    WPP_SF_sL(*((_QWORD *)WPP_GLOBAL_Control + 2), 0xBu, &stru_10036F8, this[1], v3);
LABEL_6:
    v4 = (PVOID *)WPP_GLOBAL_Control;
  }
  if ( v4 != &WPP_GLOBAL_Control && ((_WORD)v4[7] & 0x400) != 0 )
    WPP_SF_s(*((_QWORD *)v4 + 2), 0xCu, &stru_10036F8, this[1]);
}
