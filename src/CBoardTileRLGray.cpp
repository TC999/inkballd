#include "global_types.h"
#include <new>
#include <cstdint>
#include <cstring>
#include <cstdlib>
#include <windows.h>

extern void* CBoardTileRLGray_vftable;
extern void __stdcall AddGameObjectToUpdateList(void* game_object);
CBoardTile* CBoardTileRLGray_CBoardTileRLGray(CBoardTileRLGray* self,
    int a2,
    int a3,
    int a4,
    int a5,
    int a6,
    int a7,
    int a8)
{
    uint8_t v10[16];

    new ((CBoardTile*)self) CBoardTile();
    *reinterpret_cast<uint32_t*>(self) = reinterpret_cast<uint32_t>(&CBoardTileRLGray_vftable);
    new (v10) Helpers::CLogBlock(v10, "CBoardTileRLGray::CBoardTileRLGray", 0);
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 76) = a2;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 80) = a3;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 32) = a4;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 44) = a5;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 100) = a7;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 104) = a8;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 72) = a6;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 68) = 7;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 96) = (a6 != 0) ? 2 : 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 64) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 88) = 0;
    *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(self) + 92) = 0;
    AddGameObjectToUpdateList(self);
    reinterpret_cast<Helpers::CLogBlock*>(v10)->~CLogBlock();
    return (CBoardTile*)self;
}
