//----- (01004068) --------------------------------------------------------
BallPoints *__thiscall BallPoints::BallPoints(BallPoints *this, int a2)
{
  int *v3; // eax
  int v4; // edi
  double v5; // st7
  const char *v7[2]; // [esp+18h] [ebp-20h] BYREF
  double v8; // [esp+20h] [ebp-18h]
  int v9; // [esp+34h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock *)v7, "BallPoints::BallPoints", 0);
  v9 = 1;
  v8 = (double)a2 * 0.5;
  v3 = (int *)operator new[](0x100u);
  *(_DWORD *)this = v3;
  v9 = 0;
  if ( v3 )
  {
    v4 = (int)-v8;
    *v3 = v4;
    *(_DWORD *)(*(_DWORD *)this + 4) = 0;
    *(_DWORD *)(*(_DWORD *)this + 8) = (int)-(cosd(11.25) * v8);
    *(_DWORD *)(*(_DWORD *)this + 12) = (int)-(sind(11.25) * v8);
    *(_DWORD *)(*(_DWORD *)this + 16) = (int)-(cosd(22.5) * v8);
    *(_DWORD *)(*(_DWORD *)this + 20) = (int)-(sind(22.5) * v8);
    *(_DWORD *)(*(_DWORD *)this + 24) = (int)-(cosd(33.75) * v8);
    *(_DWORD *)(*(_DWORD *)this + 28) = (int)-(sind(33.75) * v8);
    *(_DWORD *)(*(_DWORD *)this + 32) = (int)-(cosd(45.0) * v8);
    *(_DWORD *)(*(_DWORD *)this + 36) = (int)-(sind(45.0) * v8);
    *(_DWORD *)(*(_DWORD *)this + 40) = (int)-(cosd(56.25) * v8);
    *(_DWORD *)(*(_DWORD *)this + 44) = (int)-(sind(56.25) * v8);
    *(_DWORD *)(*(_DWORD *)this + 48) = (int)-(cosd(67.5) * v8);
    *(_DWORD *)(*(_DWORD *)this + 52) = (int)-(sind(67.5) * v8);
    *(_DWORD *)(*(_DWORD *)this + 56) = (int)-(cosd(78.75) * v8);
    *(_DWORD *)(*(_DWORD *)this + 60) = (int)-(sind(78.75) * v8);
    *(_DWORD *)(*(_DWORD *)this + 64) = 0;
    *(_DWORD *)(*(_DWORD *)this + 68) = v4;
    *(_DWORD *)(*(_DWORD *)this + 72) = -*(_DWORD *)(*(_DWORD *)this + 56);
    *(_DWORD *)(*(_DWORD *)this + 76) = *(_DWORD *)(*(_DWORD *)this + 60);
    *(_DWORD *)(*(_DWORD *)this + 80) = -*(_DWORD *)(*(_DWORD *)this + 48);
    v5 = v8;
    *(_DWORD *)(*(_DWORD *)this + 84) = *(_DWORD *)(*(_DWORD *)this + 52);
    *(_DWORD *)(*(_DWORD *)this + 88) = -*(_DWORD *)(*(_DWORD *)this + 40);
    *(_DWORD *)(*(_DWORD *)this + 92) = *(_DWORD *)(*(_DWORD *)this + 44);
    *(_DWORD *)(*(_DWORD *)this + 96) = -*(_DWORD *)(*(_DWORD *)this + 32);
    *(_DWORD *)(*(_DWORD *)this + 100) = *(_DWORD *)(*(_DWORD *)this + 36);
    *(_DWORD *)(*(_DWORD *)this + 104) = -*(_DWORD *)(*(_DWORD *)this + 24);
    *(_DWORD *)(*(_DWORD *)this + 108) = *(_DWORD *)(*(_DWORD *)this + 28);
    *(_DWORD *)(*(_DWORD *)this + 112) = -*(_DWORD *)(*(_DWORD *)this + 16);
    *(_DWORD *)(*(_DWORD *)this + 116) = *(_DWORD *)(*(_DWORD *)this + 20);
    *(_DWORD *)(*(_DWORD *)this + 120) = -*(_DWORD *)(*(_DWORD *)this + 8);
    *(_DWORD *)(*(_DWORD *)this + 124) = *(_DWORD *)(*(_DWORD *)this + 12);
    *(_DWORD *)(*(_DWORD *)this + 128) = (int)v5;
    *(_DWORD *)(*(_DWORD *)this + 132) = 0;
    *(_DWORD *)(*(_DWORD *)this + 136) = *(_DWORD *)(*(_DWORD *)this + 120);
    *(_DWORD *)(*(_DWORD *)this + 140) = -*(_DWORD *)(*(_DWORD *)this + 124);
    *(_DWORD *)(*(_DWORD *)this + 144) = *(_DWORD *)(*(_DWORD *)this + 112);
    *(_DWORD *)(*(_DWORD *)this + 148) = -*(_DWORD *)(*(_DWORD *)this + 116);
    *(_DWORD *)(*(_DWORD *)this + 152) = *(_DWORD *)(*(_DWORD *)this + 104);
    *(_DWORD *)(*(_DWORD *)this + 156) = -*(_DWORD *)(*(_DWORD *)this + 108);
    *(_DWORD *)(*(_DWORD *)this + 160) = *(_DWORD *)(*(_DWORD *)this + 96);
    *(_DWORD *)(*(_DWORD *)this + 164) = -*(_DWORD *)(*(_DWORD *)this + 100);
    *(_DWORD *)(*(_DWORD *)this + 168) = *(_DWORD *)(*(_DWORD *)this + 88);
    *(_DWORD *)(*(_DWORD *)this + 172) = -*(_DWORD *)(*(_DWORD *)this + 92);
    *(_DWORD *)(*(_DWORD *)this + 176) = *(_DWORD *)(*(_DWORD *)this + 80);
    *(_DWORD *)(*(_DWORD *)this + 180) = -*(_DWORD *)(*(_DWORD *)this + 84);
    *(_DWORD *)(*(_DWORD *)this + 184) = *(_DWORD *)(*(_DWORD *)this + 72);
    *(_DWORD *)(*(_DWORD *)this + 188) = -*(_DWORD *)(*(_DWORD *)this + 76);
    *(_DWORD *)(*(_DWORD *)this + 192) = 0;
    *(_DWORD *)(*(_DWORD *)this + 196) = (int)v5;
    *(_DWORD *)(*(_DWORD *)this + 200) = -*(_DWORD *)(*(_DWORD *)this + 184);
    *(_DWORD *)(*(_DWORD *)this + 204) = *(_DWORD *)(*(_DWORD *)this + 188);
    *(_DWORD *)(*(_DWORD *)this + 208) = -*(_DWORD *)(*(_DWORD *)this + 176);
    *(_DWORD *)(*(_DWORD *)this + 212) = *(_DWORD *)(*(_DWORD *)this + 180);
    *(_DWORD *)(*(_DWORD *)this + 216) = -*(_DWORD *)(*(_DWORD *)this + 168);
    *(_DWORD *)(*(_DWORD *)this + 220) = *(_DWORD *)(*(_DWORD *)this + 172);
    *(_DWORD *)(*(_DWORD *)this + 224) = -*(_DWORD *)(*(_DWORD *)this + 160);
    *(_DWORD *)(*(_DWORD *)this + 228) = *(_DWORD *)(*(_DWORD *)this + 164);
    *(_DWORD *)(*(_DWORD *)this + 232) = -*(_DWORD *)(*(_DWORD *)this + 152);
    *(_DWORD *)(*(_DWORD *)this + 236) = *(_DWORD *)(*(_DWORD *)this + 156);
    *(_DWORD *)(*(_DWORD *)this + 240) = -*(_DWORD *)(*(_DWORD *)this + 144);
    *(_DWORD *)(*(_DWORD *)this + 244) = *(_DWORD *)(*(_DWORD *)this + 148);
    *(_DWORD *)(*(_DWORD *)this + 248) = -*(_DWORD *)(*(_DWORD *)this + 136);
    *(_DWORD *)(*(_DWORD *)this + 252) = *(_DWORD *)(*(_DWORD *)this + 140);
  }
  v9 = -1;
  Helpers::CLogBlock::~CLogBlock(v7);
  return this;
}
