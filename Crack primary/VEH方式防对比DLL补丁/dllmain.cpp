// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"



//VEH异常处理（堆中）
LONG CALLBACK VectoredHandler(_In_ PEXCEPTION_POINTERS ExceptionInfo)
{
	if (ExceptionInfo->ExceptionRecord->ExceptionAddress == (LPVOID)0x0041530D)
	{
		MessageBox(NULL, L"成功触发CC异常", L":)", MB_ICONINFORMATION);

		//修改EIP，使EIP指向Magic Jump下一句
		ExceptionInfo->ContextRecord->Eip = 0x00415216;

		//将原先设置的CC断点恢复成8B
		DWORD dwOldProtect = 0;
		VirtualProtect((LPVOID)0x0041530D, 0x1000, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		//开始修改CC，触发异常
		*(PBYTE)0x0041530D = 0x8b;

		//表示处理了异常
		return EXCEPTION_CONTINUE_EXECUTION;
	}

	//要注入的目标exe，自己可能也有许多异常处理，所以要返回继续扫描
	return EXCEPTION_CONTINUE_SEARCH;
}
/*
SEH异常处理（栈中）
_except(){

}
*/

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
		//添加VEH
		AddVectoredExceptionHandler(1, VectoredHandler);
		
		//修改内存分页权限
		DWORD dwOldProtect = 0;
		VirtualProtect((LPVOID)0x0041530D, 0x1000, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		//开始修改CC，触发异常
		*(PBYTE)0x0041530D = 0xcc;
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

