void __thiscall CBoardTileRLColored::ToggleState(CBoardTileRLColored *this)
{
  _BYTE v2[8]; // [esp+4h] [ebp-8h] BYREF

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v2, "CBoardTileRLColored::ToggleState", 0);
  *((_DWORD *)this + 23) = *((_DWORD *)this + 23) == 0;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v2);
}
