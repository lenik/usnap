// Machine generated IDispatch wrapper class(es) created with ClassWizard

#include "stdafx.h"
#include "streamworkhelper01.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// _G1 properties

/////////////////////////////////////////////////////////////////////////////
// _G1 operations

long _G1::GetMagicNum()
{
	long result;
	InvokeHelper(0x40030000, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _G1::SetMagicNum(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x40030000, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

CString _G1::GetS_tempfile()
{
	CString result;
	InvokeHelper(0x40030001, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _G1::SetS_tempfile(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030001, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _G1::GetS_configfile()
{
	CString result;
	InvokeHelper(0x40030002, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _G1::SetS_configfile(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030002, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _G1::GetS_scoreplugfile()
{
	CString result;
	InvokeHelper(0x40030003, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _G1::SetS_scoreplugfile(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030003, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _G1::GetS_algor()
{
	CString result;
	InvokeHelper(0x40030004, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _G1::SetS_algor(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030004, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _G1::GetS_decor()
{
	CString result;
	InvokeHelper(0x40030005, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _G1::SetS_decor(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030005, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _G1::GetS_score()
{
	CString result;
	InvokeHelper(0x40030006, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _G1::SetS_score(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x40030006, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _G1::GetN_w1()
{
	long result;
	InvokeHelper(0x40030007, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _G1::SetN_w1(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x40030007, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

long _G1::GetN_d1()
{
	long result;
	InvokeHelper(0x40030008, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _G1::SetN_d1(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x40030008, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

float _G1::GetN_fuzzy()
{
	float result;
	InvokeHelper(0x40030009, DISPATCH_PROPERTYGET, VT_R4, (void*)&result, NULL);
	return result;
}

void _G1::SetN_fuzzy(float newValue)
{
	static BYTE parms[] =
		VTS_R4;
	InvokeHelper(0x40030009, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 newValue);
}

long _G1::GetN_precise()
{
	long result;
	InvokeHelper(0x4003000a, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _G1::SetN_precise(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4003000a, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _G1::GetB_dllfile()
{
	BOOL result;
	InvokeHelper(0x4003000b, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _G1::SetB_dllfile(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4003000b, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

BOOL _G1::GetB_activexfile()
{
	BOOL result;
	InvokeHelper(0x4003000c, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _G1::SetB_activexfile(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x4003000c, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

CString _G1::GetS_savetofile()
{
	CString result;
	InvokeHelper(0x4003000d, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _G1::SetS_savetofile(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x4003000d, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

CString _G1::GetCode_scorelist()
{
	CString result;
	InvokeHelper(0x4003000e, DISPATCH_PROPERTYGET, VT_BSTR, (void*)&result, NULL);
	return result;
}

void _G1::SetCode_scorelist(LPCTSTR lpszNewValue)
{
	static BYTE parms[] =
		VTS_BSTR;
	InvokeHelper(0x4003000e, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 lpszNewValue);
}

long _G1::GetCode_scorelist_num()
{
	long result;
	InvokeHelper(0x4003000f, DISPATCH_PROPERTYGET, VT_I4, (void*)&result, NULL);
	return result;
}

void _G1::SetCode_scorelist_num(long nNewValue)
{
	static BYTE parms[] =
		VTS_I4;
	InvokeHelper(0x4003000f, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 nNewValue);
}

BOOL _G1::GetB_showExcelWindow()
{
	BOOL result;
	InvokeHelper(0x40030010, DISPATCH_PROPERTYGET, VT_BOOL, (void*)&result, NULL);
	return result;
}

void _G1::SetB_showExcelWindow(BOOL bNewValue)
{
	static BYTE parms[] =
		VTS_BOOL;
	InvokeHelper(0x40030010, DISPATCH_PROPERTYPUT, VT_EMPTY, NULL, parms,
		 bNewValue);
}

void _G1::ClearCode()
{
	InvokeHelper(0x60030000, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}

CString _G1::AddScore(LPCTSTR objname, long match, long unmatch, long extra, long lost)
{
	CString result;
	static BYTE parms[] =
		VTS_BSTR VTS_I4 VTS_I4 VTS_I4 VTS_I4;
	InvokeHelper(0x60030001, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms,
		objname, match, unmatch, extra, lost);
	return result;
}

void _G1::Generate()
{
	InvokeHelper(0x60030002, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
}
