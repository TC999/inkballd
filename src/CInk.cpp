#include "global_types.h"
#include <cstdint>
#include <windows.h>

extern "C" void* CInk_vftable;

CInk::CInk(HWND window_handle)
{
  int* unused_ptr;
  uint8_t log_buffer[16];
  int cleanup_flag;

  *((uint32_t*)this + 0) = reinterpret_cast<uint32_t>(&CInk_vftable);
  Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CInk::CInk", 0);
  cleanup_flag = 0;
  GetClientRect(window_handle, &g_rcClient);
  cleanup_flag = -1;
  dword_10B0664 = 10 * (dword_10B0674 - g_rcClient.left);
  g_hWnd = window_handle;
  dword_10B0668 = 10 * (dword_10B0678 - dword_10B0670);
  *((uint32_t*)this + 1) = 0;
  reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}

CInk::~CInk()
{
	uint8_t log_buffer[16];
	int cleanup_flag;

	*((uint32_t*)this + 0) = reinterpret_cast<uint32_t>(&CInk_vftable);
	Helpers::CLogBlock::CLogBlock(reinterpret_cast<Helpers::CLogBlock*>(log_buffer), "CInk::~CInk", 0);
	cleanup_flag = 0;
	CInk_Cleanup(this);
	cleanup_flag = -1;
	reinterpret_cast<Helpers::CLogBlock*>(log_buffer)->~CLogBlock();
}