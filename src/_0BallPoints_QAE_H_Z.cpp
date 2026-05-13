#include "global_types.h"
#include <cstdint>
#include <new>
#include <cmath>
#include "math_utils.h"

BallPoints* BallPoints_ctor(BallPoints* this_ptr, int radius)
{
    uint8_t log_buffer[8];
    double radius_half;
    int log_state;

    new (log_buffer) Helpers::CLogBlock(log_buffer, "BallPoints::BallPoints", 0);
    log_state = 1;
    radius_half = static_cast<double>(radius) * 0.5;

    auto data_array = reinterpret_cast<uint32_t*>(operator new[](0x100u));
    this_ptr->data_array = data_array;
    log_state = 0;

    if (data_array)
    {
        int negative_radius = static_cast<int>(-radius_half);
        data_array[0] = negative_radius;
        data_array[1] = 0;
        data_array[2] = static_cast<int>(-cosd(11.25) * radius_half);
        data_array[3] = static_cast<int>(-sind(11.25) * radius_half);
        data_array[4] = static_cast<int>(-cosd(22.5) * radius_half);
        data_array[5] = static_cast<int>(-sind(22.5) * radius_half);
        data_array[6] = static_cast<int>(-cosd(33.75) * radius_half);
        data_array[7] = static_cast<int>(-sind(33.75) * radius_half);
        data_array[8] = static_cast<int>(-cosd(45.0) * radius_half);
        data_array[9] = static_cast<int>(-sind(45.0) * radius_half);
        data_array[10] = static_cast<int>(-cosd(56.25) * radius_half);
        data_array[11] = static_cast<int>(-sind(56.25) * radius_half);
        data_array[12] = static_cast<int>(-cosd(67.5) * radius_half);
        data_array[13] = static_cast<int>(-sind(67.5) * radius_half);
        data_array[14] = static_cast<int>(-cosd(78.75) * radius_half);
        data_array[15] = static_cast<int>(-sind(78.75) * radius_half);
        data_array[16] = 0;
        data_array[17] = negative_radius;
        data_array[18] = -data_array[14];
        data_array[19] = data_array[15];
        data_array[20] = -data_array[12];
        radius_half = radius_half;
        data_array[21] = data_array[13];
        data_array[22] = -data_array[10];
        data_array[23] = data_array[11];
        data_array[24] = -data_array[8];
        data_array[25] = data_array[9];
        data_array[26] = -data_array[6];
        data_array[27] = data_array[7];
        data_array[28] = -data_array[4];
        data_array[29] = data_array[5];
        data_array[30] = -data_array[2];
        data_array[31] = data_array[3];
        data_array[32] = static_cast<int>(radius_half);
        data_array[33] = 0;
        data_array[34] = data_array[30];
        data_array[35] = -data_array[31];
        data_array[36] = data_array[28];
        data_array[37] = -data_array[29];
        data_array[38] = data_array[26];
        data_array[39] = -data_array[27];
        data_array[40] = data_array[24];
        data_array[41] = -data_array[25];
        data_array[42] = data_array[22];
        data_array[43] = -data_array[23];
        data_array[44] = data_array[20];
        data_array[45] = -data_array[21];
        data_array[46] = data_array[18];
        data_array[47] = -data_array[19];
        data_array[48] = 0;
        data_array[49] = static_cast<int>(radius_half);
        data_array[50] = -data_array[46];
        data_array[51] = data_array[47];
        data_array[52] = -data_array[44];
        data_array[53] = data_array[45];
        data_array[54] = -data_array[42];
        data_array[55] = data_array[43];
        data_array[56] = -data_array[40];
        data_array[57] = data_array[41];
        data_array[58] = -data_array[38];
        data_array[59] = data_array[39];
        data_array[60] = -data_array[36];
        data_array[61] = data_array[37];
        data_array[62] = -data_array[34];
        data_array[63] = data_array[35];
    }
    log_state = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
    return this_ptr;
}
