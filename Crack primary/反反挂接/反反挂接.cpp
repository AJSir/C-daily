// �����ҽ�.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "�����ҽ�.h"


// This is an example of an exported variable
MY_API int n�����ҽ�=0;

// This is an example of an exported function.
MY_API int fn�����ҽ�(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see �����ҽ�.h for the class definition
C�����ҽ�::C�����ҽ�()
{
	return;
}
