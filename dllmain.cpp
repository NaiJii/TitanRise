#include "includes.h"

#include "utilities/memory.h"
#include "sdk/sdk.h"
#include "core/hooks.h"
#include "core/render.h"

#if 1
#pragma region( "Linker" )
#pragma comment(linker,"/export:AVIBuildFilter=avifil.AVIBuildFilter,@1")
#pragma comment(linker,"/export:AVIBuildFilterA=avifil.AVIBuildFilterA,@2")
#pragma comment(linker,"/export:AVIBuildFilterW=avifil.AVIBuildFilterW,@3")
#pragma comment(linker,"/export:AVIClearClipboard=avifil.AVIClearClipboard,@4")
#pragma comment(linker,"/export:AVIFileAddRef=avifil.AVIFileAddRef,@5")
#pragma comment(linker,"/export:AVIFileCreateStream=avifil.AVIFileCreateStream,@6")
#pragma comment(linker,"/export:AVIFileCreateStreamA=avifil.AVIFileCreateStreamA,@7")
#pragma comment(linker,"/export:AVIFileCreateStreamW=avifil.AVIFileCreateStreamW,@8")
#pragma comment(linker,"/export:AVIFileEndRecord=avifil.AVIFileEndRecord,@9")
#pragma comment(linker,"/export:AVIFileExit=avifil.AVIFileExit,@10")
#pragma comment(linker,"/export:AVIFileGetStream=avifil.AVIFileGetStream,@11")
#pragma comment(linker,"/export:AVIFileInfo=avifil.AVIFileInfo,@12")
#pragma comment(linker,"/export:AVIFileInfoA=avifil.AVIFileInfoA,@13")
#pragma comment(linker,"/export:AVIFileInfoW=avifil.AVIFileInfoW,@14")
#pragma comment(linker,"/export:AVIFileInit=avifil.AVIFileInit,@15")
#pragma comment(linker,"/export:AVIFileOpen=avifil.AVIFileOpen,@16")
#pragma comment(linker,"/export:AVIFileOpenA=avifil.AVIFileOpenA,@17")
#pragma comment(linker,"/export:AVIFileOpenW=avifil.AVIFileOpenW,@18")
#pragma comment(linker,"/export:AVIFileReadData=avifil.AVIFileReadData,@19")
#pragma comment(linker,"/export:AVIFileRelease=avifil.AVIFileRelease,@20")
#pragma comment(linker,"/export:AVIFileWriteData=avifil.AVIFileWriteData,@21")
#pragma comment(linker,"/export:AVIGetFromClipboard=avifil.AVIGetFromClipboard,@22")
#pragma comment(linker,"/export:AVIMakeCompressedStream=avifil.AVIMakeCompressedStream,@23")
#pragma comment(linker,"/export:AVIMakeFileFromStreams=avifil.AVIMakeFileFromStreams,@24")
#pragma comment(linker,"/export:AVIMakeStreamFromClipboard=avifil.AVIMakeStreamFromClipboard,@25")
#pragma comment(linker,"/export:AVIPutFileOnClipboard=avifil.AVIPutFileOnClipboard,@26")
#pragma comment(linker,"/export:AVISave=avifil.AVISave,@27")
#pragma comment(linker,"/export:AVISaveA=avifil.AVISaveA,@28")
#pragma comment(linker,"/export:AVISaveOptions=avifil.AVISaveOptions,@29")
#pragma comment(linker,"/export:AVISaveOptionsFree=avifil.AVISaveOptionsFree,@30")
#pragma comment(linker,"/export:AVISaveV=avifil.AVISaveV,@31")
#pragma comment(linker,"/export:AVISaveVA=avifil.AVISaveVA,@32")
#pragma comment(linker,"/export:AVISaveVW=avifil.AVISaveVW,@33")
#pragma comment(linker,"/export:AVISaveW=avifil.AVISaveW,@34")
#pragma comment(linker,"/export:AVIStreamAddRef=avifil.AVIStreamAddRef,@35")
#pragma comment(linker,"/export:AVIStreamBeginStreaming=avifil.AVIStreamBeginStreaming,@36")
#pragma comment(linker,"/export:AVIStreamCreate=avifil.AVIStreamCreate,@37")
#pragma comment(linker,"/export:AVIStreamEndStreaming=avifil.AVIStreamEndStreaming,@38")
#pragma comment(linker,"/export:AVIStreamFindSample=avifil.AVIStreamFindSample,@39")
#pragma comment(linker,"/export:AVIStreamGetFrame=avifil.AVIStreamGetFrame,@40")
#pragma comment(linker,"/export:AVIStreamGetFrameClose=avifil.AVIStreamGetFrameClose,@41")
#pragma comment(linker,"/export:AVIStreamGetFrameOpen=avifil.AVIStreamGetFrameOpen,@42")
#pragma comment(linker,"/export:AVIStreamInfo=avifil.AVIStreamInfo,@43")
#pragma comment(linker,"/export:AVIStreamInfoA=avifil.AVIStreamInfoA,@44")
#pragma comment(linker,"/export:AVIStreamInfoW=avifil.AVIStreamInfoW,@45")
#pragma comment(linker,"/export:AVIStreamLength=avifil.AVIStreamLength,@46")
#pragma comment(linker,"/export:AVIStreamOpenFromFile=avifil.AVIStreamOpenFromFile,@47")
#pragma comment(linker,"/export:AVIStreamOpenFromFileA=avifil.AVIStreamOpenFromFileA,@48")
#pragma comment(linker,"/export:AVIStreamOpenFromFileW=avifil.AVIStreamOpenFromFileW,@49")
#pragma comment(linker,"/export:AVIStreamRead=avifil.AVIStreamRead,@50")
#pragma comment(linker,"/export:AVIStreamReadData=avifil.AVIStreamReadData,@51")
#pragma comment(linker,"/export:AVIStreamReadFormat=avifil.AVIStreamReadFormat,@52")
#pragma comment(linker,"/export:AVIStreamRelease=avifil.AVIStreamRelease,@53")
#pragma comment(linker,"/export:AVIStreamSampleToTime=avifil.AVIStreamSampleToTime,@54")
#pragma comment(linker,"/export:AVIStreamSetFormat=avifil.AVIStreamSetFormat,@55")
#pragma comment(linker,"/export:AVIStreamStart=avifil.AVIStreamStart,@56")
#pragma comment(linker,"/export:AVIStreamTimeToSample=avifil.AVIStreamTimeToSample,@57")
#pragma comment(linker,"/export:AVIStreamWrite=avifil.AVIStreamWrite,@58")
#pragma comment(linker,"/export:AVIStreamWriteData=avifil.AVIStreamWriteData,@59")
#pragma comment(linker,"/export:CreateEditableStream=avifil.CreateEditableStream,@60")
#pragma comment(linker,"/export:DllCanUnloadNow=avifil.DllCanUnloadNow,@61")
#pragma comment(linker,"/export:DllGetClassObject=avifil.DllGetClassObject,@62")
#pragma comment(linker,"/export:EditStreamClone=avifil.EditStreamClone,@63")
#pragma comment(linker,"/export:EditStreamCopy=avifil.EditStreamCopy,@64")
#pragma comment(linker,"/export:EditStreamCut=avifil.EditStreamCut,@65")
#pragma comment(linker,"/export:EditStreamPaste=avifil.EditStreamPaste,@66")
#pragma comment(linker,"/export:EditStreamSetInfo=avifil.EditStreamSetInfo,@67")
#pragma comment(linker,"/export:EditStreamSetInfoA=avifil.EditStreamSetInfoA,@68")
#pragma comment(linker,"/export:EditStreamSetInfoW=avifil.EditStreamSetInfoW,@69")
#pragma comment(linker,"/export:EditStreamSetName=avifil.EditStreamSetName,@70")
#pragma comment(linker,"/export:EditStreamSetNameA=avifil.EditStreamSetNameA,@71")
#pragma comment(linker,"/export:EditStreamSetNameW=avifil.EditStreamSetNameW,@72")
#pragma comment(linker,"/export:IID_IAVIEditStream=avifil.IID_IAVIEditStream,@73")
#pragma comment(linker,"/export:IID_IAVIFile=avifil.IID_IAVIFile,@74")
#pragma comment(linker,"/export:IID_IAVIStream=avifil.IID_IAVIStream,@75")
#pragma comment(linker,"/export:IID_IGetFrame=avifil.IID_IGetFrame,@76")
#pragma endregion
#endif

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