// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the VEHDLL_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// VEHDLL_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef VEHDLL_EXPORTS
#define VEHDLL_API __declspec(dllexport)
#else
#define VEHDLL_API __declspec(dllimport)
#endif

// This class is exported from the VEH方式防对比DLL补丁.dll
class VEHDLL_API CVEH方式防对比DLL补丁 {
public:
	CVEH方式防对比DLL补丁(void);
	// TODO: add your methods here.
};

extern VEHDLL_API int nVEH方式防对比DLL补丁;

VEHDLL_API int fnVEH方式防对比DLL补丁(void);
