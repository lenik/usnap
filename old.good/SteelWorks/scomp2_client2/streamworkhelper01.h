// Machine generated IDispatch wrapper class(es) created with ClassWizard
/////////////////////////////////////////////////////////////////////////////
// _G1 wrapper class

class _G1 : public COleDispatchDriver
{
public:
	_G1() {}		// Calls COleDispatchDriver default constructor
	_G1(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	_G1(const _G1& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	long GetMagicNum();
	void SetMagicNum(long nNewValue);
	CString GetS_tempfile();
	void SetS_tempfile(LPCTSTR lpszNewValue);
	CString GetS_configfile();
	void SetS_configfile(LPCTSTR lpszNewValue);
	CString GetS_scoreplugfile();
	void SetS_scoreplugfile(LPCTSTR lpszNewValue);
	CString GetS_algor();
	void SetS_algor(LPCTSTR lpszNewValue);
	CString GetS_decor();
	void SetS_decor(LPCTSTR lpszNewValue);
	CString GetS_score();
	void SetS_score(LPCTSTR lpszNewValue);
	long GetN_w1();
	void SetN_w1(long nNewValue);
	long GetN_d1();
	void SetN_d1(long nNewValue);
	float GetN_fuzzy();
	void SetN_fuzzy(float newValue);
	long GetN_precise();
	void SetN_precise(long nNewValue);
	BOOL GetB_dllfile();
	void SetB_dllfile(BOOL bNewValue);
	BOOL GetB_activexfile();
	void SetB_activexfile(BOOL bNewValue);
	CString GetS_savetofile();
	void SetS_savetofile(LPCTSTR lpszNewValue);
	CString GetCode_scorelist();
	void SetCode_scorelist(LPCTSTR lpszNewValue);
	long GetCode_scorelist_num();
	void SetCode_scorelist_num(long nNewValue);
	BOOL GetB_showExcelWindow();
	void SetB_showExcelWindow(BOOL bNewValue);
	void ClearCode();
	CString AddScore(LPCTSTR objname, long match, long unmatch, long extra, long lost);
	void Generate();
};
