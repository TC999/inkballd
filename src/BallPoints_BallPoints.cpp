//----- (01004068) --------------------------------------------------------
BallPoints *__thiscall BallPoints::BallPoints(BallPoints *self, int a2)
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
  *(_DWORD *)self = v3;
  v9 = 0;
  if ( v3 )
  {
    v4 = (int)-v8;
    *v3 = v4;
    *(_DWORD *)(*(_DWORD *)self + 4) = 0;
    *(_DWORD *)(*(_DWORD *)self + 8) = (int)-(cosd(11.25) * v8);
    *(_DWORD *)(*(_DWORD *)self + 12) = (int)-(sind(11.25) * v8);
    *(_DWORD *)(*(_DWORD *)self + 16) = (int)-(cosd(22.5) * v8);
    *(_DWORD *)(*(_DWORD *)self + 20) = (int)-(sind(22.5) * v8);
    *(_DWORD *)(*(_DWORD *)self + 24) = (int)-(cosd(33.75) * v8);
    *(_DWORD *)(*(_DWORD *)self + 28) = (int)-(sind(33.75) * v8);
    *(_DWORD *)(*(_DWORD *)self + 32) = (int)-(cosd(45.0) * v8);
    *(_DWORD *)(*(_DWORD *)self + 36) = (int)-(sind(45.0) * v8);
    *(_DWORD *)(*(_DWORD *)self + 40) = (int)-(cosd(56.25) * v8);
    *(_DWORD *)(*(_DWORD *)self + 44) = (int)-(sind(56.25) * v8);
    *(_DWORD *)(*(_DWORD *)self + 48) = (int)-(cosd(67.5) * v8);
    *(_DWORD *)(*(_DWORD *)self + 52) = (int)-(sind(67.5) * v8);
    *(_DWORD *)(*(_DWORD *)self + 56) = (int)-(cosd(78.75) * v8);
    *(_DWORD *)(*(_DWORD *)self + 60) = (int)-(sind(78.75) * v8);
    *(_DWORD *)(*(_DWORD *)self + 64) = 0;
    *(_DWORD *)(*(_DWORD *)self + 68) = v4;
    *(_DWORD *)(*(_DWORD *)self + 72) = -*(_DWORD *)(*(_DWORD *)self + 56);
    *(_DWORD *)(*(_DWORD *)self + 76) = *(_DWORD *)(*(_DWORD *)self + 60);
    *(_DWORD *)(*(_DWORD *)self + 80) = -*(_DWORD *)(*(_DWORD *)self + 48);
    v5 = v8;
    *(_DWORD *)(*(_DWORD *)self + 84) = *(_DWORD *)(*(_DWORD *)self + 52);
    *(_DWORD *)(*(_DWORD *)self + 88) = -*(_DWORD *)(*(_DWORD *)self + 40);
    *(_DWORD *)(*(_DWORD *)self + 92) = *(_DWORD *)(*(_DWORD *)self + 44);
    *(_DWORD *)(*(_DWORD *)self + 96) = -*(_DWORD *)(*(_DWORD *)self + 32);
    *(_DWORD *)(*(_DWORD *)self + 100) = *(_DWORD *)(*(_DWORD *)self + 36);
    *(_DWORD *)(*(_DWORD *)self + 104) = -*(_DWORD *)(*(_DWORD *)self + 24);
    *(_DWORD *)(*(_DWORD *)self + 108) = *(_DWORD *)(*(_DWORD *)self + 28);
    *(_DWORD *)(*(_DWORD *)self + 112) = -*(_DWORD *)(*(_DWORD *)self + 16);
    *(_DWORD *)(*(_DWORD *)self + 116) = *(_DWORD *)(*(_DWORD *)self + 20);
    *(_DWORD *)(*(_DWORD *)self + 120) = -*(_DWORD *)(*(_DWORD *)self + 8);
    *(_DWORD *)(*(_DWORD *)self + 124) = *(_DWORD *)(*(_DWORD *)self + 12);
    *(_DWORD *)(*(_DWORD *)self + 128) = (int)v5;
    *(_DWORD *)(*(_DWORD *)self + 132) = 0;
    *(_DWORD *)(*(_DWORD *)self + 136) = *(_DWORD *)(*(_DWORD *)self + 120);
    *(_DWORD *)(*(_DWORD *)self + 140) = -*(_DWORD *)(*(_DWORD *)self + 124);
    *(_DWORD *)(*(_DWORD *)self + 144) = *(_DWORD *)(*(_DWORD *)self + 112);
    *(_DWORD *)(*(_DWORD *)self + 148) = -*(_DWORD *)(*(_DWORD *)self + 116);
    *(_DWORD *)(*(_DWORD *)self + 152) = *(_DWORD *)(*(_DWORD *)self + 104);
    *(_DWORD *)(*(_DWORD *)self + 156) = -*(_DWORD *)(*(_DWORD *)self + 108);
    *(_DWORD *)(*(_DWORD *)self + 160) = *(_DWORD *)(*(_DWORD *)self + 96);
    *(_DWORD *)(*(_DWORD *)self + 164) = -*(_DWORD *)(*(_DWORD *)self + 100);
    *(_DWORD *)(*(_DWORD *)self + 168) = *(_DWORD *)(*(_DWORD *)self + 88);
    *(_DWORD *)(*(_DWORD *)self + 172) = -*(_DWORD *)(*(_DWORD *)self + 92);
    *(_DWORD *)(*(_DWORD *)self + 176) = *(_DWORD *)(*(_DWORD *)self + 80);
    *(_DWORD *)(*(_DWORD *)self + 180) = -*(_DWORD *)(*(_DWORD *)self + 84);
    *(_DWORD *)(*(_DWORD *)self + 184) = *(_DWORD *)(*(_DWORD *)self + 72);
    *(_DWORD *)(*(_DWORD *)self + 188) = -*(_DWORD *)(*(_DWORD *)self + 76);
    *(_DWORD *)(*(_DWORD *)self + 192) = 0;
    *(_DWORD *)(*(_DWORD *)self + 196) = (int)v5;
    *(_DWORD *)(*(_DWORD *)self + 200) = -*(_DWORD *)(*(_DWORD *)self + 184);
    *(_DWORD *)(*(_DWORD *)self + 204) = *(_DWORD *)(*(_DWORD *)self + 188);
    *(_DWORD *)(*(_DWORD *)self + 208) = -*(_DWORD *)(*(_DWORD *)self + 176);
    *(_DWORD *)(*(_DWORD *)self + 212) = *(_DWORD *)(*(_DWORD *)self + 180);
    *(_DWORD *)(*(_DWORD *)self + 216) = -*(_DWORD *)(*(_DWORD *)self + 168);
    *(_DWORD *)(*(_DWORD *)self + 220) = *(_DWORD *)(*(_DWORD *)self + 172);
    *(_DWORD *)(*(_DWORD *)self + 224) = -*(_DWORD *)(*(_DWORD *)self + 160);
    *(_DWORD *)(*(_DWORD *)self + 228) = *(_DWORD *)(*(_DWORD *)self + 164);
    *(_DWORD *)(*(_DWORD *)self + 232) = -*(_DWORD *)(*(_DWORD *)self + 152);
    *(_DWORD *)(*(_DWORD *)self + 236) = *(_DWORD *)(*(_DWORD *)self + 156);
    *(_DWORD *)(*(_DWORD *)self + 240) = -*(_DWORD *)(*(_DWORD *)self + 144);
    *(_DWORD *)(*(_DWORD *)self + 244) = *(_DWORD *)(*(_DWORD *)self + 148);
    *(_DWORD *)(*(_DWORD *)self + 248) = -*(_DWORD *)(*(_DWORD *)self + 136);
    *(_DWORD *)(*(_DWORD *)self + 252) = *(_DWORD *)(*(_DWORD *)self + 140);
  }
  v9 = -1;
  Helpers::CLogBlock::~CLogBlock(v7);
  return self;
}
