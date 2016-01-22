// 反挂接.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
	DEBUG_EVENT tagDebugEvent = { 0 };

	puts("请输入目标PID值:");
	DWORD dwPid = 0;
	scanf_s("%d", &dwPid, sizeof(DWORD));

	//该函数用于挂接一个进程，就是用来调试进程的
	if (0 == DebugActiveProcess(dwPid))
	{
		puts("挂接失败...");
		system("pause");
		return -1;
	}
	else
	{
		puts("挂接成功...");
		while (true)
		{
			//等待调试事件
			WaitForDebugEvent(&tagDebugEvent, INFINITE);
			//继续接收调试事件
			ContinueDebugEvent(
				tagDebugEvent.dwProcessId,
				tagDebugEvent.dwThreadId,
				DBG_CONTINUE);
		}
	}
		

	return 0;
}

