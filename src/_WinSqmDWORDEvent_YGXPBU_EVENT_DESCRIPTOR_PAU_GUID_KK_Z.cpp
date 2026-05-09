#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" {
    void __stdcall _WinSqmDWORDEvent(const EVENT_DESCRIPTOR* event_desc, GUID* guid, char param1, char param2)
    {
      GUID* target_guid; // eax
      uint64_t data_buffer[6]; // [esp+8h] [ebp-30h] BYREF

      memset(data_buffer, 0, sizeof(data_buffer));
      if (WinSqmEventEnabled(event_desc, guid))
      {
        target_guid = guid;
        if (!guid)
          target_guid = reinterpret_cast<GUID*>(&unk_105C840);
        data_buffer[0] = reinterpret_cast<uint64_t>(target_guid);
        data_buffer[2] = reinterpret_cast<uint64_t>(&param1);
        data_buffer[4] = reinterpret_cast<uint64_t>(&param2);
        data_buffer[1] = 16;
        data_buffer[3] = 4;
        data_buffer[5] = 4;
        WinSqmEventWrite(event_desc, 3, data_buffer);
      }
    }
}
