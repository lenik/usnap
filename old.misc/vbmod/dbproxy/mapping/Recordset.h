// Recordset.h : Declaration of the CRecordset

#ifndef __RECORDSET_H_
#define __RECORDSET_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRecordset
class ATL_NO_VTABLE CRecordset :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRecordset, &CLSID_P_Recordset>,
	public ISupportErrorInfo,
	public IConnectionPointContainerImpl<CRecordset>,
	public IDispatchImpl<IRecordset, &IID_IRecordset, &LIBID_ADOMapping>
{
public:
	CRecordset()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_RECORDSET)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRecordset)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
	COM_INTERFACE_ENTRY(IConnectionPointContainer)
	COM_INTERFACE_ENTRY(IRecordset)
END_COM_MAP()
BEGIN_CONNECTION_POINT_MAP(CRecordset)
END_CONNECTION_POINT_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IRecordset
public:
	STDMETHOD(get_Properties)(Properties * * pVal);
	STDMETHOD(get_AbsolutePosition)(PositionEnum_Param * pl);
	STDMETHOD(put_AbsolutePosition)(PositionEnum_Param pl);
	STDMETHOD(putref_ActiveConnection)(IDispatch * pvar);
	STDMETHOD(put_ActiveConnection)(VARIANT pvar);
	STDMETHOD(get_ActiveConnection)(VARIANT * pvar);
	STDMETHOD(get_BOF)(VARIANT_BOOL * pb);
	STDMETHOD(get_Bookmark)(VARIANT * pvBookmark);
	STDMETHOD(put_Bookmark)(VARIANT pvBookmark);
	STDMETHOD(get_CacheSize)(LONG * pl);
	STDMETHOD(put_CacheSize)(LONG pl);
	STDMETHOD(get_CursorType)(CursorTypeEnum * plCursorType);
	STDMETHOD(put_CursorType)(CursorTypeEnum plCursorType);
	STDMETHOD(get_EOF)(VARIANT_BOOL * pb);
	STDMETHOD(get_Fields)(Fields * * ppvObject);
	STDMETHOD(get_LockType)(LockTypeEnum * plLockType);
	STDMETHOD(put_LockType)(LockTypeEnum plLockType);
	STDMETHOD(get_MaxRecords)(long * plMaxRecords);
	STDMETHOD(put_MaxRecords)(long plMaxRecords);
	STDMETHOD(get_RecordCount)(long * pl);
	STDMETHOD(putref_Source)(IDispatch * pvSource);
	STDMETHOD(put_Source)(BSTR pvSource);
	STDMETHOD(get_Source)(VARIANT * pvSource);
	STDMETHOD(AddNew)(VARIANT FieldList, VARIANT Values);
	STDMETHOD(CancelUpdate)();
	STDMETHOD(Close)();
	STDMETHOD(Delete)(AffectEnum AffectRecords);
	STDMETHOD(GetRows)(LONG Rows, VARIANT Start, VARIANT Fields, VARIANT * pvar);
	STDMETHOD(Move)(long NumRecords, VARIANT Start);
	STDMETHOD(MoveNext)();
	STDMETHOD(MovePrevious)();
	STDMETHOD(MoveFirst)();
	STDMETHOD(MoveLast)();
	STDMETHOD(Open)(VARIANT Source, VARIANT ActiveConnection, CursorTypeEnum CursorType, LockTypeEnum LockType, LONG Options);
	STDMETHOD(Requery)(LONG Options);
	STDMETHOD(xxResync)(AffectEnum AffectRecords);
	STDMETHOD(Update)(VARIANT Fields, VARIANT Values);
	STDMETHOD(get_AbsolutePage)(PositionEnum_Param * pl);
	STDMETHOD(put_AbsolutePage)(PositionEnum_Param pl);
	STDMETHOD(get_EditMode)(EditModeEnum * pl);
	STDMETHOD(get_Filter)(VARIANT * Criteria);
	STDMETHOD(put_Filter)(VARIANT Criteria);
	STDMETHOD(get_PageCount)(long * pl);
	STDMETHOD(get_PageSize)(LONG * pl);
	STDMETHOD(put_PageSize)(LONG pl);
	STDMETHOD(get_Sort)(BSTR * Criteria);
	STDMETHOD(put_Sort)(BSTR Criteria);
	STDMETHOD(get_Status)(LONG * pl);
	STDMETHOD(get_State)(LONG * plObjState);
	STDMETHOD(xxClone)(_Recordset * * ppvObject);
	STDMETHOD(UpdateBatch)(AffectEnum AffectRecords);
	STDMETHOD(CancelBatch)(AffectEnum AffectRecords);
	STDMETHOD(get_CursorLocation)(CursorLocationEnum * plCursorLoc);
	STDMETHOD(put_CursorLocation)(CursorLocationEnum plCursorLoc);
	STDMETHOD(NextRecordset)(VARIANT * RecordsAffected, _Recordset * * ppiRs);
	STDMETHOD(Supports)(CursorOptionEnum CursorOptions, VARIANT_BOOL * pb);
	STDMETHOD(get_Collect)(VARIANT Index, VARIANT *var);
	STDMETHOD(put_Collect)(VARIANT Index, VARIANT var);
	STDMETHOD(get_MarshalOptions)(MarshalOptionsEnum * peMarshal);
	STDMETHOD(put_MarshalOptions)(MarshalOptionsEnum peMarshal);
	STDMETHOD(Find)(BSTR Criteria, long SkipRecords, SearchDirectionEnum SearchDirection, VARIANT Start);
	STDMETHOD(Cancel)();
	STDMETHOD(get_DataSource)(IUnknown * * ppunkDataSource);
	STDMETHOD(putref_DataSource)(IUnknown * ppunkDataSource);
	STDMETHOD(xxSave)(BSTR FileName, PersistFormatEnum PersistFormat);
	STDMETHOD(get_ActiveCommand)(IDispatch * * ppCmd);
	STDMETHOD(put_StayInSync)(VARIANT_BOOL pbStayInSync);
	STDMETHOD(get_StayInSync)(VARIANT_BOOL * pbStayInSync);
	STDMETHOD(GetString)(StringFormatEnum StringFormat, LONG NumRows, BSTR ColumnDelimeter, BSTR RowDelimeter, BSTR NullExpr, BSTR * pRetString);
	STDMETHOD(get_DataMember)(BSTR * pbstrDataMember);
	STDMETHOD(put_DataMember)(BSTR pbstrDataMember);
	STDMETHOD(CompareBookmarks)(VARIANT Bookmark1, VARIANT Bookmark2, CompareEnum * pCompare);
	STDMETHOD(Clone)(LockTypeEnum LockType, _Recordset * * ppvObject);
	STDMETHOD(Resync)(AffectEnum AffectRecords, ResyncEnum ResyncValues);
	STDMETHOD(Seek)(VARIANT KeyValues, SeekEnum SeekOption);
	STDMETHOD(put_Index)(BSTR pbstrIndex);
	STDMETHOD(get_Index)(BSTR * pbstrIndex);
	STDMETHOD(Save)(VARIANT Destination, PersistFormatEnum PersistFormat);
};

#endif //__RECORDSET_H_
