//---------------------------------------------------------------------------

#ifndef u_ViewerH
#define u_ViewerH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <Tabs.hpp>
#include <ToolWin.hpp>
//---------------------------------------------------------------------------
class TfrmViewer : public TForm
{
__published:	// IDE-managed Components
    TTabSet *TabSet1;
    TNotebook *Notebook1;
    TToolBar *ToolBar1;
    TImageList *ImageList1;
    TToolButton *ToolButton1;
    TToolButton *ToolButton2;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *ToolButton5;
    TToolButton *ToolButton6;
    void __fastcall TabSet1Change(TObject *Sender, int NewTab,
          bool &AllowChange);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmViewer(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmViewer *frmViewer;
//---------------------------------------------------------------------------
#endif
