// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"



//VEH�쳣�������У�
LONG CALLBACK VectoredHandler(_In_ PEXCEPTION_POINTERS ExceptionInfo)
{
	if (ExceptionInfo->ExceptionRecord->ExceptionAddress == (LPVOID)0x0041530D)
	{
		MessageBox(NULL, L"�ɹ�����CC�쳣", L":)", MB_ICONINFORMATION);

		//�޸�EIP��ʹEIPָ��Magic Jump��һ��
		ExceptionInfo->ContextRecord->Eip = 0x00415216;

		//��ԭ�����õ�CC�ϵ�ָ���8B
		DWORD dwOldProtect = 0;
		VirtualProtect((LPVOID)0x0041530D, 0x1000, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		//��ʼ�޸�CC�������쳣
		*(PBYTE)0x0041530D = 0x8b;

		//��ʾ�������쳣
		return EXCEPTION_CONTINUE_EXECUTION;
	}

	//Ҫע���Ŀ��exe���Լ�����Ҳ������쳣��������Ҫ���ؼ���ɨ��
	return EXCEPTION_CONTINUE_SEARCH;
}
/*
SEH�쳣����ջ�У�
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
		MessageBox(NULL, L"dllע��ɹ�", L":)", MB_ICONINFORMATION);
		//���VEH
		AddVectoredExceptionHandler(1, VectoredHandler);
		
		//�޸��ڴ��ҳȨ��
		DWORD dwOldProtect = 0;
		VirtualProtect((LPVOID)0x0041530D, 0x1000, PAGE_EXECUTE_READWRITE, &dwOldProtect);

		//��ʼ�޸�CC�������쳣
		*(PBYTE)0x0041530D = 0xcc;
	}
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
	{
		MessageBox(NULL, L"dll����¹�", L":)", MB_ICONINFORMATION);
	}
	break;
	}
	return TRUE;
}

