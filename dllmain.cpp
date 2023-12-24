#include "includes.h"

#include "utilities/memory.h"
#include "sdk/sdk.h"
#include "core/hooks.h"
#include "core/render.h"

DWORD WINAPI Main(LPVOID lpParam)
{
	AllocConsole();
	if (freopen("CONOUT$", "w", stdout) == NULL)
		return 0;

	printf("Hello from DLL!\n");

	Sleep(6000);

	if (!Mem::Setup(lpParam)) {
		printf("Mem::Setup() failed!\n");
		return 0;
	}

	if (!SDK::Setup()) {
		printf("SDK::Setup() failed!\n");
		return 0;
	}

	if (!Render::Setup())
		return 0;

	if (!Hooks::Setup()) {
		printf("Hooks::Setup() failed!\n");
		return 0;
	}

	while (GetAsyncKeyState(VK_END) == 0)
		Sleep(100);

	FreeConsole();
	FreeLibraryAndExitThread((HMODULE)lpParam, 0);

	return 0;
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH) {
		DisableThreadLibraryCalls(hModule);
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)Main, hModule, NULL, NULL);
	}

	return TRUE;
}
