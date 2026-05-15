#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void* g_pBallManagerSurface;
extern "C" void* g_pGamePiecesSurface;
extern "C" void* g_CBitmapRects;

void DrawToSurface_CBallManager(CBallManager* self)
{
    IDirectDrawSurface7* ddraw_surface;
    IDirectDrawSurface7Vtbl* surface_vtable;
    IDirectDrawSurface7* game_pieces_surface;
    CBoardObject** ball_object_ptr;
    RECT* bitmap_rect;
    RECT bounding_rect;
    uint32_t rect_left;
    uint32_t rect_top;
    uint32_t rect_right;
    uint32_t rect_bottom;
    IDirectDrawSurface7* target_surface;
    IDirectDrawSurface7Vtbl* target_vtable;
    CBoardObject* current_ball;
    IDirectDrawSurface7* source_surface;
    uint8_t log_buffer[16];
    CBallManager* manager;
    RECT* update_rect;
    int ball_index;
    int flag;

    manager = self;
    Helpers::CLogBlock::CLogBlock((Helpers::CLogBlock*)log_buffer, "CBallManager::DrawToSurface", 0);
    flag = 0;
    
    ddraw_surface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pBallManagerSurface);
    surface_vtable = ddraw_surface->lpVtbl;
    update_rect = reinterpret_cast<RECT*>(reinterpret_cast<uint8_t*>(self) + 20);
    bitmap_rect = (RECT*)CBitmapRects::GetBitmapRect(g_CBitmapRects, 106);
    game_pieces_surface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
    surface_vtable->Blt(ddraw_surface, update_rect, game_pieces_surface, bitmap_rect, 0, 0);
    
    for (ball_index = 0; ball_index < 6; ++ball_index)
    {
        ball_object_ptr = reinterpret_cast<CBoardObject**>(reinterpret_cast<uint8_t*>(manager) + 4 * ball_index + 56);
        CBoardObject* ball_object = *ball_object_ptr;
        
        if (ball_object->update_flags && (ball_index || !manager->hidden_flag))
        {
            CBoardObject::GetBoundingRect(ball_object, &bounding_rect);
            bitmap_rect = (RECT*)CBitmapRects::GetBitmapRect(g_CBitmapRects, ball_object->tile_type + 12);
            rect_left = (uint32_t)bitmap_rect->left;
            rect_top = (uint32_t)bitmap_rect->top;
            rect_right = (uint32_t)bitmap_rect->right;
            rect_bottom = (uint32_t)bitmap_rect->bottom;
            
            if (bounding_rect.left < 104)
            {
                if (bounding_rect.right > 104)
                    rect_right += 104 - (uint32_t)bounding_rect.right;
                    
                target_surface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pBallManagerSurface);
                target_vtable = target_surface->lpVtbl;
                current_ball = ball_object;
                source_surface = target_surface;
                game_pieces_surface = (IDirectDrawSurface7*)CSurface::GetDDrawSurface(g_pGamePiecesSurface);
                
                double* dbl_ptr = reinterpret_cast<double*>(reinterpret_cast<uint8_t*>(current_ball) + 16);
                int xPos = (int)dbl_ptr[0];
                RECT srcRect = { xPos, 0, xPos + 64, 64 };
                target_vtable->BltFast(source_surface, 
                    (int)dbl_ptr[0], 0,
                    game_pieces_surface,
                    &srcRect,
                    0);
            }
        }
    }
    
    AddDisplayUpdateRect(update_rect);
    flag = -1;
    reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}
