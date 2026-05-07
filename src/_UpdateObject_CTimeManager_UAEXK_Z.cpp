#include <cstdint>

extern "C" {
    void CTimeManager::UpdateObject(CTimeManager* this_ptr, uint32_t delta_time)
    {
      bool is_active; // zf
      uint32_t remaining_time; // ecx
      uint32_t adjusted_time; // ecx
      uint32_t centiseconds; // ecx
      uint32_t milliseconds; // eax
      uint32_t total_milliseconds; // eax
      uint8_t log_buffer[8]; // [esp+10h] [ebp-18h] BYREF
      int should_update_display; // [esp+18h] [ebp-10h]
      int cleanup_flag; // [esp+24h] [ebp-4h]

      Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CTimeManager::UpdateObject", 0);
      is_active = *reinterpret_cast<uint32_t*>(this_ptr + 14) == 0;
      cleanup_flag = 0;
      should_update_display = 0;
      if (!is_active)
      {
        if (*reinterpret_cast<uint32_t*>(this_ptr + 13))
        {
          KillPlayer(0);
        }
        else
        {
          remaining_time = *reinterpret_cast<uint32_t*>(this_ptr + 9);
          if (remaining_time != -1)
          {
            if (remaining_time > delta_time)
            {
              adjusted_time = remaining_time - delta_time;
              *reinterpret_cast<uint32_t*>(this_ptr + 9) = adjusted_time;
              if (adjusted_time < 0x2AF8) // 11000ms
              {
                *reinterpret_cast<uint32_t*>(this_ptr + 10) += delta_time;
                centiseconds = *reinterpret_cast<uint32_t*>(this_ptr + 10);
                *reinterpret_cast<uint32_t*>(this_ptr + 11) += delta_time;
                milliseconds = *reinterpret_cast<uint32_t*>(this_ptr + 11);
                if (centiseconds >= 0x14D) // 333ms
                {
                  is_active = *reinterpret_cast<uint32_t*>(this_ptr + 12) == 0;
                  *reinterpret_cast<uint32_t*>(this_ptr + 10) = 0;
                  should_update_display = 1;
                  *reinterpret_cast<uint32_t*>(this_ptr + 12) = is_active;
                }
                if (milliseconds >= 0x3E8) // 1000ms
                  *reinterpret_cast<uint32_t*>(this_ptr + 11) = 0;
              }
            }
            else
            {
              *reinterpret_cast<uint32_t*>(this_ptr + 9) = 0;
              *reinterpret_cast<uint32_t*>(this_ptr + 12) = 1;
            }
          }
        }
        total_milliseconds = *reinterpret_cast<uint32_t*>(this_ptr + 9);
        if (total_milliseconds >= 0x3E8 || *reinterpret_cast<uint32_t*>(this_ptr + 13)) // 1000ms
        {
          is_active = should_update_display == 1;
          *reinterpret_cast<uint32_t*>(this_ptr + 13) = 0;
          if (!is_active && total_milliseconds / 0x3E8 == dword_105C81C / 0x3E8u)
            goto LABEL_18;
        }
        else
        {
          *reinterpret_cast<uint32_t*>(this_ptr + 12) = 1;
          *reinterpret_cast<uint32_t*>(this_ptr + 13) = 1;
        }
        (*(void(__thiscall **)(CTimeManager*))(*reinterpret_cast<uint32_t*>(this_ptr + 4)))(this_ptr);
LABEL_18:
        dword_105C81C = *reinterpret_cast<uint32_t*>(this_ptr + 9);
      }
      cleanup_flag = -1;
      Helpers::CLogBlock::~CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer));
    }
}
    else
    {
      v4 = *((_DWORD *)this + 9);
      if ( v4 != -1 )
      {
        if ( v4 > a2 )
        {
          v5 = v4 - a2;
          *((_DWORD *)this + 9) = v5;
          if ( v5 < 0x2AF8 )
          {
            *((_DWORD *)this + 10) += a2;
            v6 = *((_DWORD *)this + 10);
            *((_DWORD *)this + 11) += a2;
            v7 = *((_DWORD *)this + 11);
            if ( v6 >= 0x14D )
            {
              v3 = *((_DWORD *)this + 12) == 0;
              *((_DWORD *)this + 10) = 0;
              v10 = 1;
              *((_DWORD *)this + 12) = v3;
            }
            if ( v7 >= 0x3E8 )
              *((_DWORD *)this + 11) = 0;
          }
        }
        else
        {
          *((_DWORD *)this + 9) = 0;
          *((_DWORD *)this + 12) = 1;
        }
      }
    }
    v8 = *((_DWORD *)this + 9);
    if ( v8 >= 0x3E8 || *((_DWORD *)this + 13) )
    {
      v3 = v10 == 1;
      *((_DWORD *)this + 13) = 0;
      if ( !v3 && v8 / 0x3E8 == dword_105C81C / 0x3E8u )
        goto LABEL_18;
    }
    else
    {
      *((_DWORD *)this + 12) = 1;
      *((_DWORD *)this + 13) = 1;
    }
    (*(void (__thiscall **)(CTimeManager *))(*(_DWORD *)this + 4))(this);
LABEL_18:
    dword_105C81C = *((_DWORD *)this + 9);
  }
  v11 = -1;
  Helpers::CLogBlock::~CLogBlock((Helpers::CLogBlock *)v9);
}
