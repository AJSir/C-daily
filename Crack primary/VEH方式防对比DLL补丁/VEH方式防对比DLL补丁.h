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

// This class is exported from the VEH��ʽ���Ա�DLL����.dll
class VEHDLL_API CVEH��ʽ���Ա�DLL���� {
public:
	CVEH��ʽ���Ա�DLL����(void);
	// TODO: add your methods here.
};

extern VEHDLL_API int nVEH��ʽ���Ա�DLL����;

VEHDLL_API int fnVEH��ʽ���Ա�DLL����(void);
