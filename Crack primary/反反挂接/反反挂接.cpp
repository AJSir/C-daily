// 反反挂接.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "反反挂接.h"


// This is an example of an exported variable
MY_API int n反反挂接=0;

// This is an example of an exported function.
MY_API int fn反反挂接(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see 反反挂接.h for the class definition
C反反挂接::C反反挂接()
{
	return;
}
