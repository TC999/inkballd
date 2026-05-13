#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" int CalcUnsqrtDistance(POINT* point1, POINT* point2);

void CBoardTile::SetClosestSide(CBoardTile *this, POINT* test_point)
{
    RECT bounding_rect;
    POINT test_point_top;
    POINT test_point_right;
    POINT test_point_bottom;
    POINT test_point_left;
    uint8_t log_buffer[8];
    int flag;

    Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(&log_buffer), "CBoardTile::SetClosestSide", 0);
    flag = 0;
    
    CBoardObject::GetBoundingRect(reinterpret_cast<uint32_t>(this), &bounding_rect);
    
    // Calculate distances to all four sides
    test_point_top.x = test_point->x;
    test_point_top.y = bounding_rect.top;
    CalcUnsqrtDistance(test_point, &test_point_top);
    
    test_point_right.x = bounding_rect.right;
    test_point_right.y = test_point->y;
    CalcUnsqrtDistance(test_point, &test_point_right);
    
    test_point_bottom.x = test_point->x;
    test_point_bottom.y = bounding_rect.bottom;
    CalcUnsqrtDistance(test_point, &test_point_bottom);
    
    test_point_left.x = bounding_rect.left;
    test_point_left.y = test_point->y;
    CalcUnsqrtDistance(test_point, &test_point_left);
    
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(&log_buffer)->~CLogBlock();
}
