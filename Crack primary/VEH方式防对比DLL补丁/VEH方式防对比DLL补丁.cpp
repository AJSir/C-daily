// VEH��ʽ���Ա�DLL����.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "VEH��ʽ���Ա�DLL����.h"


// This is an example of an exported variable
VEHDLL_API int nVEH��ʽ���Ա�DLL����=0;

// This is an example of an exported function.
VEHDLL_API int fnVEH��ʽ���Ա�DLL����(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see VEH��ʽ���Ա�DLL����.h for the class definition
CVEH��ʽ���Ա�DLL����::CVEH��ʽ���Ա�DLL����()
{
	return;
}
