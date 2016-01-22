// VEH方式防对比DLL补丁.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "VEH方式防对比DLL补丁.h"


// This is an example of an exported variable
VEHDLL_API int nVEH方式防对比DLL补丁=0;

// This is an example of an exported function.
VEHDLL_API int fnVEH方式防对比DLL补丁(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see VEH方式防对比DLL补丁.h for the class definition
CVEH方式防对比DLL补丁::CVEH方式防对比DLL补丁()
{
	return;
}
