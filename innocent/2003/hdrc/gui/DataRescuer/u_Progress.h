//---------------------------------------------------------------------------

#ifndef u_ProgressH
#define u_ProgressH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Tabs.hpp>
//---------------------------------------------------------------------------
class TfrmProgress : public TForm
{
__published:	// IDE-managed Components
    TTabSet *TabSet1;
    TNotebook *Notebook1;
    TLabel *Label1;
    TLabel *Label2;
    TLabel *Label3;
    TLabel *Label4;
    TLabel *lblCylinder;
    TLabel *lblHead;
    TLabel *lblSector;
    TLabel *lblStatus;
    TTimer *Timer1;
    void __fastcall TabSet1Change(TObject *Sender, int NewTab,
          bool &AllowChange);
    void __fastcall Notebook1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmProgress(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmProgress *frmProgress;
//---------------------------------------------------------------------------
#endif
