// DLL硃間.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "DLL硃間.h"


// This is an example of an exported variable
DLL_API int nDLL硃間=0;

// This is an example of an exported function.
DLL_API int fnDLL硃間(void)
{
	return 42;
}

// This is the constructor of a class that has been exported.
// see DLL硃間.h for the class definition
CDLL硃間::CDLL硃間()
{
	return;
}
