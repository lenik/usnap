// RemoteFSO.h : Declaration of the CRemoteFSO

#ifndef __REMOTEFSO_H_
#define __REMOTEFSO_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRemoteFSO
class ATL_NO_VTABLE CRemoteFSO :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRemoteFSO, &CLSID_RemoteFSO>,
	public IDispatchImpl<IRemoteFSO, &IID_IRemoteFSO, &LIBID_NetToolsLib>,
	public IDispatchImpl<IFileSystem, &IID_IFileSystem, &LIBID_Scripting>
{
public:
	CRemoteFSO()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_REMOTEFSO)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRemoteFSO)
	COM_INTERFACE_ENTRY(IRemoteFSO)
//DEL 	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY2(IDispatch, IRemoteFSO)
	COM_INTERFACE_ENTRY(IFileSystem)
END_COM_MAP()

// IRemoteFSO
public:
// IFileSystem
	STDMETHOD(get_Drives)(IDriveCollection * * ppdrives)
	{
		if (ppdrives == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(BuildPath)(BSTR Path, BSTR Name, BSTR * pbstrResult)
	{
		if (pbstrResult == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetDriveName)(BSTR Path, BSTR * pbstrResult)
	{
		if (pbstrResult == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetParentFolderName)(BSTR Path, BSTR * pbstrResult)
	{
		if (pbstrResult == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetFileName)(BSTR Path, BSTR * pbstrResult)
	{
		if (pbstrResult == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetBaseName)(BSTR Path, BSTR * pbstrResult)
	{
		if (pbstrResult == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetExtensionName)(BSTR Path, BSTR * pbstrResult)
	{
		if (pbstrResult == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetAbsolutePathName)(BSTR Path, BSTR * pbstrResult)
	{
		if (pbstrResult == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetTempName)(BSTR * pbstrResult)
	{
		if (pbstrResult == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(DriveExists)(BSTR DriveSpec, VARIANT_BOOL * pfExists)
	{
		if (pfExists == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(FileExists)(BSTR FileSpec, VARIANT_BOOL * pfExists)
	{
		if (pfExists == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(FolderExists)(BSTR FolderSpec, VARIANT_BOOL * pfExists)
	{
		if (pfExists == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetDrive)(BSTR DriveSpec, IDrive * * ppdrive)
	{
		if (ppdrive == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetFile)(BSTR FilePath, IFile * * ppfile)
	{
		if (ppfile == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetFolder)(BSTR FolderPath, IFolder * * ppfolder)
	{
		if (ppfolder == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(GetSpecialFolder)(SpecialFolderConst SpecialFolder, IFolder * * ppfolder)
	{
		if (ppfolder == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(DeleteFile)(BSTR FileSpec, VARIANT_BOOL Force)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(DeleteFolder)(BSTR FolderSpec, VARIANT_BOOL Force)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(MoveFile)(BSTR Source, BSTR Destination)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(MoveFolder)(BSTR Source, BSTR Destination)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(CopyFile)(BSTR Source, BSTR Destination, VARIANT_BOOL OverWriteFiles)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(CopyFolder)(BSTR Source, BSTR Destination, VARIANT_BOOL OverWriteFiles)
	{
		return E_NOTIMPL;
	}
	STDMETHOD(CreateFolder)(BSTR Path, IFolder * * ppfolder)
	{
		if (ppfolder == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(CreateTextFile)(BSTR FileName, VARIANT_BOOL Overwrite, VARIANT_BOOL Unicode, ITextStream * * ppts)
	{
		if (ppts == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
	STDMETHOD(OpenTextFile)(BSTR FileName, IOMode IOMode, VARIANT_BOOL Create, Tristate Format, ITextStream * * ppts)
	{
		if (ppts == NULL)
			return E_POINTER;

		return E_NOTIMPL;
	}
};

#endif //__REMOTEFSO_H_
