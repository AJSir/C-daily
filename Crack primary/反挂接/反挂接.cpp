// ���ҽ�.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
	DEBUG_EVENT tagDebugEvent = { 0 };

	puts("������Ŀ��PIDֵ:");
	DWORD dwPid = 0;
	scanf_s("%d", &dwPid, sizeof(DWORD));

	//�ú������ڹҽ�һ�����̣������������Խ��̵�
	if (0 == DebugActiveProcess(dwPid))
	{
		puts("�ҽ�ʧ��...");
		system("pause");
		return -1;
	}
	else
	{
		puts("�ҽӳɹ�...");
		while (true)
		{
			//�ȴ������¼�
			WaitForDebugEvent(&tagDebugEvent, INFINITE);
			//�������յ����¼�
			ContinueDebugEvent(
				tagDebugEvent.dwProcessId,
				tagDebugEvent.dwThreadId,
				DBG_CONTINUE);
		}
	}
		

	return 0;
}

