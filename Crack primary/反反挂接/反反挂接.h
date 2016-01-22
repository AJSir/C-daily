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

// This class is exported from the 反反挂接.dll
class MY_API C反反挂接 {
public:
	C反反挂接(void);
	// TODO: add your methods here.
};

extern MY_API int n反反挂接;

MY_API int fn反反挂接(void);
