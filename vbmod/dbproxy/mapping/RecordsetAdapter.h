// RecordsetAdapter.h : Declaration of the CRecordsetAdapter

#ifndef __RECORDSETADAPTER_H_
#define __RECORDSETADAPTER_H_

#include "resource.h"       // main symbols
#include "msado15CP.h"

/////////////////////////////////////////////////////////////////////////////
// CRecordsetAdapter
class ATL_NO_VTABLE CRecordsetAdapter :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRecordsetAdapter, &CLSID_RecordsetAdapter>,
	public IDispatchImpl<IRecordsetAdapter, &IID_IRecordsetAdapter, &LIBID_ADOMapping>,
	public IDispatchImpl<_ADO, &IID__ADO, &LIBID_ADODB>,
	public IDispatchImpl<_Recordset, &IID__Recordset, &LIBID_ADODB>,
	public IDispatchImpl<Recordset15, &IID_Recordset15, &LIBID_ADODB>,
	public IDispatchImpl<Recordset20, &IID_Recordset20, &LIBID_ADODB>,
	public IDispatchImpl<Recordset21, &IID_Recordset21, &LIBID_ADODB>,
	public RecordsetEventsVt,
	public CProxyRecordsetEvents< CRecordsetAdapter >,
	public IConnectionPointContainerImpl<CRecordsetAdapter>
{
    IRecordset *m_Impl;

public:
    CRecordsetAdapter() {}
    CRecordsetAdapter(IRecordset *impl) {
        setImpl(impl);
    }
    ~CRecordsetAdapter() {
        SAFE_RELEASE(m_Impl);
    }
    void setImpl(IRecordset *impl) {
        _assert_(impl);
        m_Impl = impl;
        m_Impl->AddRef();
    }

DECLARE_REGISTRY_RESOURCEID(IDR_RECORDSETADAPTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRecordsetAdapter)
	COM_INTERFACE_ENTRY(IRecordsetAdapter)
//DEL 	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IRecordsetAdapter)
	COM_INTERFACE_ENTRY(_Recordset)
	COM_INTERFACE_ENTRY2(_ADO, _Recordset)
	COM_INTERFACE_ENTRY2(Recordset15, _Recordset)
	COM_INTERFACE_ENTRY2(Recordset20, _Recordset)
	COM_INTERFACE_ENTRY2(Recordset21, _Recordset)
	COM_INTERFACE_ENTRY(RecordsetEventsVt)
	COM_INTERFACE_ENTRY_IMPL(IConnectionPointContainer)
END_COM_MAP()

// IRecordsetAdapter
public:
// _ADO
	STDMETHOD(get_Properties)(Properties * * ppvObject)
	{
		if (ppvObject == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_Properties(ppvObject);
	}
// _Recordset
	STDMETHOD(Save)(VARIANT Destination, PersistFormatEnum PersistFormat)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->Save(Destination, PersistFormat);
	}
// Recordset15
	STDMETHOD(get_AbsolutePosition)(PositionEnum_Param * pl)
	{
		if (pl == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_AbsolutePosition(pl);
	}
	STDMETHOD(put_AbsolutePosition)(PositionEnum_Param pl)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_AbsolutePosition(pl);
	}
	STDMETHOD(putref_ActiveConnection)(IDispatch * pvar)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->putref_ActiveConnection(pvar);
	}
	STDMETHOD(put_ActiveConnection)(VARIANT pvar)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_ActiveConnection(pvar);
	}
	STDMETHOD(get_ActiveConnection)(VARIANT * pvar)
	{
		if (pvar == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_ActiveConnection(pvar);
	}
	STDMETHOD(get_BOF)(VARIANT_BOOL * pb)
	{
		if (pb == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_BOF(pb);
	}
	STDMETHOD(get_Bookmark)(VARIANT * pvBookmark)
	{
		if (pvBookmark == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_Bookmark(pvBookmark);
	}
	STDMETHOD(put_Bookmark)(VARIANT pvBookmark)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_Bookmark(pvBookmark);
	}
	STDMETHOD(get_CacheSize)(LONG * pl)
	{
		if (pl == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_CacheSize(pl);
	}
	STDMETHOD(put_CacheSize)(LONG pl)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_CacheSize(pl);
	}
	STDMETHOD(get_CursorType)(CursorTypeEnum * plCursorType)
	{
		if (plCursorType == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_CursorType(plCursorType);
	}
	STDMETHOD(put_CursorType)(CursorTypeEnum plCursorType)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_CursorType(plCursorType);
	}
	STDMETHOD(get_EOF)(VARIANT_BOOL * pb)
	{
		if (pb == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_EOF(pb);
	}
	STDMETHOD(get_Fields)(Fields * * ppvObject)
	{
		if (ppvObject == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_Fields(ppvObject);
	}
	STDMETHOD(get_LockType)(LockTypeEnum * plLockType)
	{
		if (plLockType == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_LockType(plLockType);
	}
	STDMETHOD(put_LockType)(LockTypeEnum plLockType)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_LockType(plLockType);
	}
	STDMETHOD(get_MaxRecords)(ADO_LONGPTR * plMaxRecords)
	{
		if (plMaxRecords == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_MaxRecords(plMaxRecords);
	}
	STDMETHOD(put_MaxRecords)(ADO_LONGPTR plMaxRecords)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_MaxRecords(plMaxRecords);
	}
	STDMETHOD(get_RecordCount)(ADO_LONGPTR * pl)
	{
		if (pl == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_RecordCount(pl);
	}
	STDMETHOD(putref_Source)(IDispatch *pvSource)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->putref_Source(new _variant_t(pvSource));
	}
	STDMETHOD(put_Source)(BSTR pvSource)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_Source(_variant_t(pvSource));
	}
	STDMETHOD(get_Source)(VARIANT * pvSource)
	{
		if (pvSource == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_Source(pvSource);
	}
	STDMETHOD(AddNew)(VARIANT FieldList, VARIANT Values)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->AddNew(FieldList, Values);
	}
	STDMETHOD(CancelUpdate)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->CancelUpdate();
	}
	STDMETHOD(Close)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->Close();
	}
	STDMETHOD(Delete)(AffectEnum AffectRecords)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->Delete(AffectRecords);
	}
	STDMETHOD(GetRows)(LONG Rows, VARIANT Start, VARIANT Fields, VARIANT * pvar)
	{
		if (pvar == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->GetRows(Rows, Start, Fields, pvar);
	}
	STDMETHOD(Move)(ADO_LONGPTR NumRecords, VARIANT Start)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->Move(NumRecords, Start);
	}
	STDMETHOD(MoveNext)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->MoveNext();
	}
	STDMETHOD(MovePrevious)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->MovePrevious();
	}
	STDMETHOD(MoveFirst)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->MoveFirst();
	}
	STDMETHOD(MoveLast)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->MoveLast();
	}
	STDMETHOD(Open)(VARIANT Source, VARIANT ActiveConnection, CursorTypeEnum CursorType, LockTypeEnum LockType, LONG Options)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->Open(Source, ActiveConnection, CursorType, LockType, Options);
	}
	STDMETHOD(Requery)(LONG Options)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->Requery(Options);
	}
	STDMETHOD(_xResync)(AffectEnum AffectRecords)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->xxResync(AffectRecords);
	}
	STDMETHOD(Update)(VARIANT Fields, VARIANT Values)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->Update(Fields, Values);
	}
	STDMETHOD(get_AbsolutePage)(PositionEnum_Param * pl)
	{
		if (pl == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_AbsolutePage(pl);
	}
	STDMETHOD(put_AbsolutePage)(PositionEnum_Param pl)
	{
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->put_AbsolutePage(pl);
	}
	STDMETHOD(get_EditMode)(EditModeEnum * pl)
	{
		if (pl == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
		return m_Impl->get_EditMode(pl);
	}
	STDMETHOD(get_Filter)(VARIANT * Criteria)
	{
		if (Criteria == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_Filter(Criteria);
	}
	STDMETHOD(put_Filter)(VARIANT Criteria)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_Filter(Criteria);
	}
	STDMETHOD(get_PageCount)(ADO_LONGPTR * pl)
	{
		if (pl == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_PageCount(pl);
	}
	STDMETHOD(get_PageSize)(LONG * pl)
	{
		if (pl == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_PageSize(pl);
	}
	STDMETHOD(put_PageSize)(LONG pl)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_PageSize(pl);
	}
	STDMETHOD(get_Sort)(BSTR * Criteria)
	{
		if (Criteria == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_Sort(Criteria);
	}
	STDMETHOD(put_Sort)(BSTR Criteria)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_Sort(Criteria);
	}
	STDMETHOD(get_Status)(LONG * pl)
	{
		if (pl == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_Status(pl);
	}
	STDMETHOD(get_State)(LONG * plObjState)
	{
		if (plObjState == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_State(plObjState);
	}
	STDMETHOD(_xClone)(_Recordset * * ppvObject)
	{
		if (ppvObject == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->xxClone(ppvObject);
	}
	STDMETHOD(UpdateBatch)(AffectEnum AffectRecords)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->UpdateBatch(AffectRecords);
	}
	STDMETHOD(CancelBatch)(AffectEnum AffectRecords)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->CancelBatch(AffectRecords);
	}
	STDMETHOD(get_CursorLocation)(CursorLocationEnum * plCursorLoc)
	{
		if (plCursorLoc == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_CursorLocation(plCursorLoc);
	}
	STDMETHOD(put_CursorLocation)(CursorLocationEnum plCursorLoc)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_CursorLocation(plCursorLoc);
	}
	STDMETHOD(NextRecordset)(VARIANT * RecordsAffected, _Recordset * * ppiRs)
	{
		if (RecordsAffected == NULL)
			return E_POINTER;
		if (ppiRs == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->NextRecordset(RecordsAffected, ppiRs);
	}
	STDMETHOD(Supports)(CursorOptionEnum CursorOptions, VARIANT_BOOL * pb)
	{
		if (pb == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Supports(CursorOptions, pb);
	}
	STDMETHOD(get_Collect)(VARIANT Index, VARIANT * pvar)
	{
		if (pvar == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_Collect(Index, pvar);
	}
	STDMETHOD(put_Collect)(VARIANT Index, VARIANT pvar)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_Collect(Index, pvar);
	}
	STDMETHOD(get_MarshalOptions)(MarshalOptionsEnum * peMarshal)
	{
		if (peMarshal == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_MarshalOptions(peMarshal);
	}
	STDMETHOD(put_MarshalOptions)(MarshalOptionsEnum peMarshal)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_MarshalOptions(peMarshal);
	}
	STDMETHOD(Find)(BSTR Criteria, ADO_LONGPTR SkipRecords, SearchDirectionEnum SearchDirection, VARIANT Start)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Find(Criteria, SkipRecords, SearchDirection, Start);
	}
// Recordset20
	STDMETHOD(Cancel)()
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Cancel();
	}
	STDMETHOD(get_DataSource)(IUnknown * * ppunkDataSource)
	{
		if (ppunkDataSource == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        HRESULT hr;
        IDispatch *datasrc = NULL;
        hr = m_Impl->get_DataSource(&datasrc);
        if (SUCCEEDED(hr))
            *ppunkDataSource = datasrc;
        return hr;
	}
	STDMETHOD(putref_DataSource)(IUnknown * ppunkDataSource)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        IDispatch *datasrc = NULL;
        HRESULT hr;
        if (ppunkDataSource != NULL) {
            hr = ppunkDataSource->QueryInterface(IID_IDispatch, (void **)&datasrc);
            if (FAILED(hr))
                return E_INVALIDARG;
        }
        hr = m_Impl->putref_DataSource(datasrc);
        if (datasrc != NULL)
            datasrc->Release();
        return hr;
	}
	STDMETHOD(_xSave)(BSTR FileName, PersistFormatEnum PersistFormat)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->xxSave(FileName, PersistFormat);
	}
	STDMETHOD(get_ActiveCommand)(IDispatch * * ppCmd)
	{
		if (ppCmd == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_ActiveCommand(ppCmd);
	}
	STDMETHOD(put_StayInSync)(VARIANT_BOOL pbStayInSync)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_StayInSync(pbStayInSync);
	}
	STDMETHOD(get_StayInSync)(VARIANT_BOOL * pbStayInSync)
	{
		if (pbStayInSync == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_StayInSync(pbStayInSync);
	}
	STDMETHOD(GetString)(StringFormatEnum StringFormat, LONG NumRows, BSTR ColumnDelimeter, BSTR RowDelimeter, BSTR NullExpr, BSTR * pRetString)
	{
		if (pRetString == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->GetString(StringFormat, NumRows, ColumnDelimeter, RowDelimeter, NullExpr, pRetString);
	}
	STDMETHOD(get_DataMember)(BSTR * pbstrDataMember)
	{
		if (pbstrDataMember == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_DataMember(pbstrDataMember);
	}
	STDMETHOD(put_DataMember)(BSTR pbstrDataMember)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_DataMember(pbstrDataMember);
	}
	STDMETHOD(CompareBookmarks)(VARIANT Bookmark1, VARIANT Bookmark2, CompareEnum * pCompare)
	{
		if (pCompare == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->CompareBookmarks(Bookmark1, Bookmark2, pCompare);
	}
	STDMETHOD(Clone)(LockTypeEnum LockType, _Recordset * * ppvObject)
	{
		if (ppvObject == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Clone(LockType, ppvObject);
	}
	STDMETHOD(Resync)(AffectEnum AffectRecords, ResyncEnum ResyncValues)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Resync(AffectRecords, ResyncValues);
	}
// Recordset21
	STDMETHOD(Seek)(VARIANT KeyValues, SeekEnum SeekOption)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->Seek(KeyValues, SeekOption);
	}
	STDMETHOD(put_Index)(BSTR pbstrIndex)
	{
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->put_Index(pbstrIndex);
	}
	STDMETHOD(get_Index)(BSTR * pbstrIndex)
	{
		if (pbstrIndex == NULL)
			return E_POINTER;
        if (m_Impl == NULL)
            return E_FAIL;
        return m_Impl->get_Index(pbstrIndex);
	}
// RecordsetEventsVt
	STDMETHOD(WillChangeField)(LONG cFields, VARIANT Fields, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_WillChangeField(cFields, Fields, adStatus, pRecordset);
	}
	STDMETHOD(FieldChangeComplete)(LONG cFields, VARIANT Fields, ADODB::Error * pError, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_FieldChangeComplete(cFields, Fields, pError, adStatus, pRecordset);
	}
	STDMETHOD(WillChangeRecord)(EventReasonEnum adReason, LONG cRecords, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_WillChangeRecord(adReason, cRecords, adStatus, pRecordset);
	}
	STDMETHOD(RecordChangeComplete)(EventReasonEnum adReason, LONG cRecords, ADODB::Error * pError, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_RecordChangeComplete(adReason, cRecords, pError, adStatus, pRecordset);
	}
	STDMETHOD(WillChangeRecordset)(EventReasonEnum adReason, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_WillChangeRecordset(adReason, adStatus, pRecordset);
	}
	STDMETHOD(RecordsetChangeComplete)(EventReasonEnum adReason, ADODB::Error * pError, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_RecordsetChangeComplete(adReason, pError, adStatus, pRecordset);
	}
	STDMETHOD(WillMove)(EventReasonEnum adReason, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_WillMove(adReason, adStatus, pRecordset);
	}
	STDMETHOD(MoveComplete)(EventReasonEnum adReason, ADODB::Error * pError, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_MoveComplete(adReason, pError, adStatus, pRecordset);
	}
	STDMETHOD(EndOfRecordset)(VARIANT_BOOL * fMoreData, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (fMoreData == NULL)
			return E_POINTER;
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_EndOfRecordset(fMoreData, adStatus, pRecordset);
	}
	STDMETHOD(FetchProgress)(LONG Progress, LONG MaxProgress, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_FetchProgress(Progress, MaxProgress, adStatus, pRecordset);
	}
	STDMETHOD(FetchComplete)(ADODB::Error * pError, EventStatusEnum * adStatus, _Recordset * pRecordset)
	{
		if (adStatus == NULL)
			return E_POINTER;
        return Fire_FetchComplete(pError, adStatus, pRecordset);
	}
public :

BEGIN_CONNECTION_POINT_MAP(CRecordsetAdapter)
	CONNECTION_POINT_ENTRY(DIID_RecordsetEvents)
END_CONNECTION_POINT_MAP()

};

typedef CComObject<CRecordsetAdapter> CRecordsetAdapterObject;

#endif //__RECORDSETADAPTER_H_
