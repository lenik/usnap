// Recordset.cpp : Implementation of CRecordset
#include "stdafx.h"
#include "Mapping.h"
#include "Recordset.h"

/////////////////////////////////////////////////////////////////////////////
// CRecordset

STDMETHODIMP CRecordset::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] =
	{
		&IID_IRecordset
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}
STDMETHODIMP CRecordset::get_Properties(Properties * * pVal)
{
	if (pVal == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_AbsolutePosition(PositionEnum_Param * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_AbsolutePosition(PositionEnum_Param pl)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::putref_ActiveConnection(IDispatch * pvar)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_ActiveConnection(VARIANT pvar)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_ActiveConnection(VARIANT * pvar)
{
	if (pvar == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_BOF(VARIANT_BOOL * pb)
{
	if (pb == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_Bookmark(VARIANT * pvBookmark)
{
	if (pvBookmark == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_Bookmark(VARIANT pvBookmark)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_CacheSize(LONG * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_CacheSize(LONG pl)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_CursorType(CursorTypeEnum * plCursorType)
{
	if (plCursorType == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_CursorType(CursorTypeEnum plCursorType)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_EOF(VARIANT_BOOL * pb)
{
	if (pb == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_Fields(Fields * * ppvObject)
{
	if (ppvObject == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_LockType(LockTypeEnum * plLockType)
{
	if (plLockType == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_LockType(LockTypeEnum plLockType)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_MaxRecords(long * plMaxRecords)
{
	if (plMaxRecords == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_MaxRecords(long plMaxRecords)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_RecordCount(long * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::putref_Source(IDispatch * pvSource)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_Source(BSTR pvSource)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_Source(VARIANT * pvSource)
{
	if (pvSource == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::AddNew(VARIANT FieldList, VARIANT Values)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::CancelUpdate()
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Close()
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Delete(AffectEnum AffectRecords)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::GetRows(LONG Rows, VARIANT Start, VARIANT Fields, VARIANT * pvar)
{
	if (pvar == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Move(long NumRecords, VARIANT Start)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::MoveNext()
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::MovePrevious()
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::MoveFirst()
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::MoveLast()
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Open(VARIANT Source, VARIANT ActiveConnection, CursorTypeEnum CursorType, LockTypeEnum LockType, LONG Options)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Requery(LONG Options)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::xxResync(AffectEnum AffectRecords)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Update(VARIANT Fields, VARIANT Values)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_AbsolutePage(PositionEnum_Param * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_AbsolutePage(PositionEnum_Param pl)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_EditMode(EditModeEnum * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_Filter(VARIANT * Criteria)
{
	if (Criteria == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_Filter(VARIANT Criteria)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_PageCount(long * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_PageSize(LONG * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_PageSize(LONG pl)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_Sort(BSTR * Criteria)
{
	if (Criteria == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_Sort(BSTR Criteria)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_Status(LONG * pl)
{
	if (pl == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_State(LONG * plObjState)
{
	if (plObjState == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::xxClone(_Recordset * * ppvObject)
{
	if (ppvObject == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::UpdateBatch(AffectEnum AffectRecords)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::CancelBatch(AffectEnum AffectRecords)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_CursorLocation(CursorLocationEnum * plCursorLoc)
{
	if (plCursorLoc == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_CursorLocation(CursorLocationEnum plCursorLoc)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::NextRecordset(VARIANT * RecordsAffected, _Recordset * * ppiRs)
{
	if (RecordsAffected == NULL)
		return E_POINTER;

	if (ppiRs == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Supports(CursorOptionEnum CursorOptions, VARIANT_BOOL * pb)
{
	if (pb == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_Collect(VARIANT Index, VARIANT * pvar)
{
	if (pvar == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_Collect(VARIANT Index, VARIANT pvar)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_MarshalOptions(MarshalOptionsEnum * peMarshal)
{
	if (peMarshal == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_MarshalOptions(MarshalOptionsEnum peMarshal)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Find(BSTR Criteria, long SkipRecords, SearchDirectionEnum SearchDirection, VARIANT Start)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Cancel()
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_DataSource(IUnknown * * ppunkDataSource)
{
	if (ppunkDataSource == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::putref_DataSource(IUnknown * ppunkDataSource)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::xxSave(BSTR FileName, PersistFormatEnum PersistFormat)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_ActiveCommand(IDispatch * * ppCmd)
{
	if (ppCmd == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_StayInSync(VARIANT_BOOL pbStayInSync)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_StayInSync(VARIANT_BOOL * pbStayInSync)
{
	if (pbStayInSync == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::GetString(StringFormatEnum StringFormat, LONG NumRows, BSTR ColumnDelimeter, BSTR RowDelimeter, BSTR NullExpr, BSTR * pRetString)
{
	if (pRetString == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_DataMember(BSTR * pbstrDataMember)
{
	if (pbstrDataMember == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_DataMember(BSTR pbstrDataMember)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::CompareBookmarks(VARIANT Bookmark1, VARIANT Bookmark2, CompareEnum * pCompare)
{
	if (pCompare == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Clone(LockTypeEnum LockType, _Recordset * * ppvObject)
{
	if (ppvObject == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Resync(AffectEnum AffectRecords, ResyncEnum ResyncValues)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Seek(VARIANT KeyValues, SeekEnum SeekOption)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::put_Index(BSTR pbstrIndex)
{
	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::get_Index(BSTR * pbstrIndex)
{
	if (pbstrIndex == NULL)
		return E_POINTER;

	return E_NOTIMPL;
}
STDMETHODIMP CRecordset::Save(VARIANT Destination, PersistFormatEnum PersistFormat)
{
	return E_NOTIMPL;
}
