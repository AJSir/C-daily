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
		MessageBox(NULL, L"dll注入成功", L":)", MB_ICONINFORMATION);
		DWORD dwOldProtect = 0;
		VirtualProtect((LPVOID)0x00415211, 0x1000, PAGE_EXECUTE_READWRITE, &dwOldProtect);
		*(PBYTE)0x00415211 = 0x85;
		//VirtualProtect((LPVOID)0x00415211, 0x1000, dwOldProtect, &dwOldProtect);
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
	{
		MessageBox(NULL, L"dll分离陈功", L":)", MB_ICONINFORMATION);
	}
		break;
	}
	return TRUE;
}

