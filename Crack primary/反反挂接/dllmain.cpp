// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	{
		HWND hwnd = FindWindow(NULL, L"第7课 神秘调试器 作业");
		DWORD dwPid = 0;
		GetWindowThreadProcessId(hwnd, &dwPid);

		//调试当前指定进程，这里的功能为安全脱离父子关系
		DebugActiveProcess(dwPid);

	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

