#if !defined(AFX_AUTOFILTER_H__F3B3359B_C576_4AA3_B430_9838245BDAE2__INCLUDED_)
#define AFX_AUTOFILTER_H__F3B3359B_C576_4AA3_B430_9838245BDAE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Machine generated IDispatch wrapper class(es) created by Microsoft Visual C++

// NOTE: Do not modify the contents of this file.  If this class is regenerated by
//  Microsoft Visual C++, your modifications will be overwritten.


// Dispatch interfaces referenced by this interface
class CFilters;
class CRange;

/////////////////////////////////////////////////////////////////////////////
// CAutoFilter wrapper class

class CAutoFilter : public COleDispatchDriver
{
public:
	CAutoFilter() {}		// Calls COleDispatchDriver default constructor
	CAutoFilter(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CAutoFilter(const CAutoFilter& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

// Attributes
public:

// Operations
public:
	void Apply();
	CFilters GetFilters();
	CRange GetRange();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOFILTER_H__F3B3359B_C576_4AA3_B430_9838245BDAE2__INCLUDED_)
