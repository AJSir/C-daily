// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the MY_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// MY_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef MY_EXPORTS
#define MY_API __declspec(dllexport)
#else
#define MY_API __declspec(dllimport)
#endif

// This class is exported from the �����ҽ�.dll
class MY_API C�����ҽ� {
public:
	C�����ҽ�(void);
	// TODO: add your methods here.
};

extern MY_API int n�����ҽ�;

MY_API int fn�����ҽ�(void);
