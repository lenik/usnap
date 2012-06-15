//$$---- Active Form HDR ---- (stActiveFormHdr)
//---------------------------------------------------------------------------


#ifndef SmallHexEditImpl1H
#define SmallHexEditImpl1H
//---------------------------------------------------------------------------
#include <classes.hpp>
#include <controls.hpp>
#include <stdCtrls.hpp>
#include <forms.hpp>
#include "HDR_Controls_TLB.h"
#include <AxCtrls.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
//---------------------------------------------------------------------------
class TSmallHexEdit : public TActiveForm
{
__published:	// IDE-managed Components
    TImage *imgSheCaret;
private:	// User declarations
public:		// User declarations
    __fastcall TSmallHexEdit(HWND ParentWindow);
    __fastcall TSmallHexEdit(TComponent* AOwner): TActiveForm(AOwner) {};

    void shit() {
        WindowProc;
    }

public:
    void __fastcall (__closure *X_OnCreate)();
};
//---------------------------------------------------------------------------
extern PACKAGE TSmallHexEdit *SmallHexEdit;
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------
#define DISPIMPL \
    public IDispatchImpl<ISmallHexEdit, &IID_ISmallHexEdit, LIBID_OF_SmallHexEdit>
class ATL_NO_VTABLE TSmallHexEditImpl:
    public TVclControlImpl<
        TSmallHexEditImpl,
        TSmallHexEdit,
        &CLSID_SmallHexEdit,
        &IID_ISmallHexEdit,
        &DIID_ISmallHexEditEvents,
        LIBID_OF_SmallHexEdit
        >,
    DISPIMPL,
//    public IDispatchImpl<ISmallHexEdit, &IID_ISmallHexEdit, LIBID_OF_SmallHexEdit>,
    public TEvents_SmallHexEdit<TSmallHexEditImpl>
{
    void __fastcall __raw_CreateEvent();

    void __fastcall ActivateEvent(TObject *Sender);
    void __fastcall ClickEvent(TObject *Sender);
    void __fastcall DblClickEvent(TObject *Sender);
    void __fastcall DeactivateEvent(TObject *Sender);
    void __fastcall DestroyEvent(TObject *Sender);
    void __fastcall KeyPressEvent(TObject *Sender, char &Key);
    void __fastcall KeyDownEvent(TObject *Sender, WORD &Key, TShiftState Shift);
    void __fastcall MouseDownEvent(TObject *Sender, TMouseButton Button, TShiftState Shift, int X, int Y);
    void __fastcall PaintEvent(TObject *Sender);
public:

  void InitializeControl()
  {
    m_VclCtl->OnActivate = ActivateEvent;
    m_VclCtl->OnClick = ClickEvent;
    m_VclCtl->OnDblClick = DblClickEvent;
    m_VclCtl->OnDeactivate = DeactivateEvent;
    m_VclCtl->OnDestroy = DestroyEvent;
    m_VclCtl->OnKeyPress = KeyPressEvent;
    m_VclCtl->OnKeyDown = KeyDownEvent;
    m_VclCtl->OnMouseDown = MouseDownEvent;
    m_VclCtl->OnPaint = PaintEvent;

    // OnCreate goes here::
  }

// The COM MAP entries declares the interfaces your object exposes (through
// QueryInterface). CComRootObjectEx::InternalQueryInterface only returns
// pointers for interfaces in the COM map. VCL controls exposed as OCXes
// have a minimum set of interfaces defined by the
// VCL_CONTROL_COM_INTERFACE_ENTRIES macro. Add other interfaces supported
// by your object with additional COM_INTERFACE_ENTRY[_xxx] macros.
//
BEGIN_COM_MAP(TSmallHexEditImpl)
  VCL_CONTROL_COM_INTERFACE_ENTRIES(ISmallHexEdit)
END_COM_MAP()



// The PROPERTY map stores property descriptions, property DISPIDs,
// property page CLSIDs and IDispatch IIDs. You may use use
// IPerPropertyBrowsingImpl, IPersistPropertyBagImpl, IPersistStreamInitImpl,
// and ISpecifyPropertyPageImpl to utilize the information in you property
// map.
//
// NOTE: The BCB Wizard does *NOT* maintain your PROPERTY_MAP table. You must
//       add or remove entries manually.
//
BEGIN_PROPERTY_MAP(TSmallHexEditImpl)
  // PROP_PAGE(CLSID_SmallHexEditPage)
END_PROPERTY_MAP()

/* DECLARE_VCL_CONTROL_PERSISTENCE(CppClass, VclClass) is needed for VCL
 * controls to persist via the VCL streaming mechanism and not the ATL mechanism.
 * The macro adds static IPersistStreamInit_Load and IPersistStreamInit_Save
 * methods to your implementation class, overriding the methods in IPersistStreamImpl.
 * This macro must be manually undefined or removed if you port to C++Builder 4.0. */

DECLARE_VCL_CONTROL_PERSISTENCE(TSmallHexEditImpl, TSmallHexEdit);

// The DECLARE_ACTIVEXCONTROL_REGISTRY macro declares a static 'UpdateRegistry'
// routine which registers the basic information about your control. The
// parameters expected by the macro are the ProgId & the ToolboxBitmap ID of
// your control.
//
DECLARE_ACTIVEXCONTROL_REGISTRY("HDR_Controls.SmallHexEdit", 1);

protected:
  STDMETHOD(_set_Font(IFontDisp** Value));
  STDMETHOD(AboutBox());
  STDMETHOD(get_Active(VARIANT_BOOL* Value));
  STDMETHOD(get_AlignDisabled(VARIANT_BOOL* Value));
  STDMETHOD(get_AutoScroll(VARIANT_BOOL* Value));
  STDMETHOD(get_AutoSize(VARIANT_BOOL* Value));
  STDMETHOD(get_AxBorderStyle(TxActiveFormBorderStyle* Value));
  STDMETHOD(get_BorderWidth(long* Value));
  STDMETHOD(get_Caption(BSTR* Value));
  STDMETHOD(get_Color(::OLE_COLOR* Value));
  STDMETHOD(get_DoubleBuffered(VARIANT_BOOL* Value));
  STDMETHOD(get_DropTarget(VARIANT_BOOL* Value));
  STDMETHOD(get_Enabled(VARIANT_BOOL* Value));
  STDMETHOD(get_Font(IFontDisp** Value));
  STDMETHOD(get_HelpFile(BSTR* Value));
  STDMETHOD(get_KeyPreview(VARIANT_BOOL* Value));
  STDMETHOD(get_PixelsPerInch(long* Value));
  STDMETHOD(get_PrintScale(TxPrintScale* Value));
  STDMETHOD(get_Scaled(VARIANT_BOOL* Value));
  STDMETHOD(get_Visible(VARIANT_BOOL* Value));
  STDMETHOD(get_VisibleDockClientCount(long* Value));
  STDMETHOD(set_AutoScroll(VARIANT_BOOL Value));
  STDMETHOD(set_AutoSize(VARIANT_BOOL Value));
  STDMETHOD(set_AxBorderStyle(TxActiveFormBorderStyle Value));
  STDMETHOD(set_BorderWidth(long Value));
  STDMETHOD(set_Caption(BSTR Value));
  STDMETHOD(set_Color(::OLE_COLOR Value));
  STDMETHOD(set_DoubleBuffered(VARIANT_BOOL Value));
  STDMETHOD(set_DropTarget(VARIANT_BOOL Value));
  STDMETHOD(set_Enabled(VARIANT_BOOL Value));
  STDMETHOD(set_Font(IFontDisp* Value));
  STDMETHOD(set_HelpFile(BSTR Value));
  STDMETHOD(set_KeyPreview(VARIANT_BOOL Value));
  STDMETHOD(set_PixelsPerInch(long Value));
  STDMETHOD(set_PrintScale(TxPrintScale Value));
  STDMETHOD(set_Scaled(VARIANT_BOOL Value));
  STDMETHOD(set_Visible(VARIANT_BOOL Value));
  STDMETHOD(get_AsiaSupport(VARIANT_BOOL* Value));
  STDMETHOD(get_BinaryPointer(long* Value));
  STDMETHOD(get_Columns(int* Value));
  STDMETHOD(get_Dirty(VARIANT_BOOL* Value));
  STDMETHOD(get_Length(long* Value));
  STDMETHOD(get_ReadOnly(VARIANT_BOOL* Value));
  STDMETHOD(get_Rows(int* Value));
  STDMETHOD(set_AsiaSupport(VARIANT_BOOL Value));
  STDMETHOD(set_Columns(int Value));
  STDMETHOD(set_Length(long Value));
  STDMETHOD(set_ReadOnly(VARIANT_BOOL Value));
  STDMETHOD(set_Rows(int Value));

  STDMETHOD(SetBinary(void* BinaryPointer, long Length));

  STDMETHOD(get_LeftMargin(int* Value));
  STDMETHOD(get_TopMargin(int* Value));
  STDMETHOD(set_LeftMargin(int Value));
  STDMETHOD(set_TopMargin(int Value));

protected:
    BOOL        m_bInited;
    HDC         m_hDC;
    TEXTMETRIC  m_tm;
    HBITMAP     m_bmCaret;

protected:
    int     m_nRows;
    int     m_nColumns;
    BYTE *  m_pbBinary;
    long    m_nLength;

    BOOL    m_bDirty;
    BOOL    m_bReadOnly;

    BOOL    m_bAsiaSupport;

    long    m_nOffset;
    int     m_nColumn;
    int     m_nRow;
    int     m_iWord;

    int     m_nLeftMargin;
    int     m_nTopMargin;

    BOOL    m_bAsciiView;


protected:
    void    SetCurrentPos(int Row, int Column);

    long    ViewToOffset(int Row, int Column);
    void    OffsetToView(long AbsoluteOffset, int& Row, int& Column);

    int     ViewRows();
    int     ViewColumns(int Row);

    void    InitView();
    void    ClearView();
    void    UpdateView();
    void    EnableCaret();
    void    DisableCaret();
    void    UpdateCaret();

    void    ScrollUp();
    void    ScrollDown();
    void    MoveToEnd();

    BYTE *  GetCurrentByte();

public:
    TSmallHexEditImpl();
};
//---------------------------------------------------------------------------
#endif
