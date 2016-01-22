
// FILE验证.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CFILE验证App:
// See FILE验证.cpp for the implementation of this class
//

class CFILE验证App : public CWinApp
{
public:
	CFILE验证App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CFILE验证App theApp;