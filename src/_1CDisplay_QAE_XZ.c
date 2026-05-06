void __thiscall CDisplay::~CDisplay(CDisplay *this)
{
  int v2; // eax
  _BYTE v3[8]; // [esp+10h] [ebp-18h] BYREF
  int v4[3]; // [esp+18h] [ebp-10h] BYREF
  int v5; // [esp+24h] [ebp-4h]

  v4[0] = 0;
  *(_DWORD *)this = &CDisplay::`vftable';
  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v3, "CDisplay::~CDisplay", v4);
  v5 = 0;
  v2 = CDisplay::DestroyObjects(this);
  v5 = -1;
  v4[0] = v2;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v3);
}
