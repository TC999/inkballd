//----- (01004068) --------------------------------------------------------
#include "global_types.h"
#include "math_utils.h"
#include <cstdint>
#include <new>

BallPoints* BallPoints_BallPoints(BallPoints *self, int a2)
{
  int *v3; // eax
  int v4; // edi
  double v5; // st7
  uint8_t v7[8]; // [esp+18h] [ebp-20h] BYREF
  double v8; // [esp+20h] [ebp-18h]
  int v9; // [esp+34h] [ebp-4h]

  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(v7), "BallPoints::BallPoints", 0);
  v9 = 1;
  v8 = (double)a2 * 0.5;
  v3 = (int *)operator new[](0x100u);
  self->data_array = (uint32_t*)v3;
  v9 = 0;
  if ( v3 )
  {
    v4 = (int)-v8;
    *v3 = v4;
    self->data_array[1] = 0;
    self->data_array[2] = (int)-(cosd(11.25) * v8);
    self->data_array[3] = (int)-(sind(11.25) * v8);
    self->data_array[4] = (int)-(cosd(22.5) * v8);
    self->data_array[5] = (int)-(sind(22.5) * v8);
    self->data_array[6] = (int)-(cosd(33.75) * v8);
    self->data_array[7] = (int)-(sind(33.75) * v8);
    self->data_array[8] = (int)-(cosd(45.0) * v8);
    self->data_array[9] = (int)-(sind(45.0) * v8);
    self->data_array[10] = (int)-(cosd(56.25) * v8);
    self->data_array[11] = (int)-(sind(56.25) * v8);
    self->data_array[12] = (int)-(cosd(67.5) * v8);
    self->data_array[13] = (int)-(sind(67.5) * v8);
    self->data_array[14] = (int)-(cosd(78.75) * v8);
    self->data_array[15] = (int)-(sind(78.75) * v8);
    self->data_array[16] = 0;
    self->data_array[17] = v4;
    self->data_array[18] = -self->data_array[14];
    self->data_array[19] = self->data_array[15];
    self->data_array[20] = -self->data_array[12];
    v5 = v8;
    self->data_array[21] = self->data_array[13];
    self->data_array[22] = -self->data_array[10];
    self->data_array[23] = self->data_array[11];
    self->data_array[24] = -self->data_array[8];
    self->data_array[25] = self->data_array[9];
    self->data_array[26] = -self->data_array[6];
    self->data_array[27] = self->data_array[7];
    self->data_array[28] = -self->data_array[4];
    self->data_array[29] = self->data_array[5];
    self->data_array[30] = -self->data_array[2];
    self->data_array[31] = self->data_array[3];
    self->data_array[32] = (int)v5;
    self->data_array[33] = 0;
    self->data_array[34] = self->data_array[30];
    self->data_array[35] = -self->data_array[31];
    self->data_array[36] = self->data_array[28];
    self->data_array[37] = -self->data_array[29];
    self->data_array[38] = self->data_array[26];
    self->data_array[39] = -self->data_array[27];
    self->data_array[40] = self->data_array[24];
    self->data_array[41] = -self->data_array[25];
    self->data_array[42] = self->data_array[22];
    self->data_array[43] = -self->data_array[23];
    self->data_array[44] = self->data_array[20];
    self->data_array[45] = -self->data_array[21];
    self->data_array[46] = self->data_array[18];
    self->data_array[47] = -self->data_array[19];
    self->data_array[48] = 0;
    self->data_array[49] = (int)v5;
    self->data_array[50] = -self->data_array[46];
    self->data_array[51] = self->data_array[47];
    self->data_array[52] = -self->data_array[44];
    self->data_array[53] = self->data_array[45];
    self->data_array[54] = -self->data_array[42];
    self->data_array[55] = self->data_array[43];
    self->data_array[56] = -self->data_array[40];
    self->data_array[57] = self->data_array[41];
    self->data_array[58] = -self->data_array[38];
    self->data_array[59] = self->data_array[39];
    self->data_array[60] = -self->data_array[36];
    self->data_array[61] = self->data_array[37];
    self->data_array[62] = -self->data_array[34];
    self->data_array[63] = self->data_array[35];
  }
  v9 = -1;
  reinterpret_cast<Helpers::CLogBlock*>(v7)->~CLogBlock();
  return self;
}
