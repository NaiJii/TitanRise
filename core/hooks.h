#pragma once

#include "../sdk/sdk.h"
#include "../utilities/memory.h"

#pragma comment (lib, "d3d11.lib")
#include <d3d11.h>

#define DEFINE_HOOK( name, retType, ... ) \
using name##_t = retType(*)( __VA_ARGS__ ); \
inline name##_t m_o##name; \
retType name(__VA_ARGS__)

#define DEFINE_HOOK_EX( name, convention, retType, ... ) \
using name##_t = retType(convention*)( __VA_ARGS__ ); \
inline name##_t m_o##name; \
retType name(__VA_ARGS__)

namespace Hooks {
	bool Setup();
	bool Detour(Address_t module, std::string_view moduleName, std::string_view functionName, uintptr_t function, uintptr_t detour, uintptr_t* original = nullptr);

	DEFINE_HOOK(CreateMove, uint32_t, CInput*, int, float, bool);
	DEFINE_HOOK(RunCommand, void, CInput*, int, float, bool);
	DEFINE_HOOK(CLMove, void, float, bool);
	DEFINE_HOOK(PaintTraverse, void, void*, void*, bool, bool);
	DEFINE_HOOK(Command, void, CEngineClient*, const char*);
	DEFINE_HOOK(SendCLCScreenShotMessage, void);

	/*
	// 40 57 48 81 EC ? ? ? ? 48 8B 0D
	*/

	DEFINE_HOOK_EX(Present, WINAPI, HRESULT, IDXGISwapChain*, UINT, UINT);
	DEFINE_HOOK_EX(BitBlt_, WINAPI, BOOL, HDC, int, int, int, int, HDC, int, int, DWORD);
	DEFINE_HOOK_EX(StretchBlt_, WINAPI, BOOL, HDC, int, int, int, int, HDC, int, int, int, int, DWORD);
}