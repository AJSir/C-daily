// 破解初级.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void m_getLocalTime(LPSYSTEMTIME tagTime);

int _tmain(int argc, _TCHAR* argv[])
{
	SYSTEMTIME tagOldTime = { 0 };
	SYSTEMTIME tagNewTime = { 0 };
	GetLocalTime(&tagNewTime);
	while (true)
	{
		m_getLocalTime(&tagOldTime);
		if (tagOldTime.wMinute==tagNewTime.wMinute+1)
		{
			MessageBox(NULL, L"本次的使用时间已经到期", L"管理员", MB_ICONERROR);
			return 0;
		}
		Sleep(1000);
	}
	return 0;
}

void m_getLocalTime(LPSYSTEMTIME tagTime){
	GetLocalTime(tagTime);
	printf("%d年%d月%d日 星期%d %d:%d:%d:%d\r\n",
		tagTime->wYear,
		tagTime->wMonth,
		tagTime->wDay,
		tagTime->wDayOfWeek,
		tagTime->wHour,
		tagTime->wMinute,
		tagTime->wSecond,
		tagTime->wMilliseconds);
}

