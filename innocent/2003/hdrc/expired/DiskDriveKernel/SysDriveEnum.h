// SysDriveEnum.h : Declaration of the CSysDriveEnum

#ifndef __SYSDRIVEENUM_H_
#define __SYSDRIVEENUM_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSysDriveEnum
class ATL_NO_VTABLE CSysDriveEnum :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CSysDriveEnum, &CLSID_SysDriveEnum>,
	public IConnectionPointContainerImpl<CSysDriveEnum>,
	public IDispatchImpl<ISysDriveEnum, &IID_ISysDriveEnum, &LIBID_DiskDriveKernel>
{
public:
	CSysDriveEnum()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_SYSDRIVEENUM)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CSysDriveEnum)
	COM_INTERFACE_ENTRY(ISysDriveEnum)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CSysDriveEnum)
END_CONNECTION_POINT_MAP()


// ISysDriveEnum
public:
};

#endif //__SYSDRIVEENUM_H_
