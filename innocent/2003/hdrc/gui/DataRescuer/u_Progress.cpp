//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "u_Progress.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmProgress *frmProgress;
//---------------------------------------------------------------------------
__fastcall TfrmProgress::TfrmProgress(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmProgress::TabSet1Change(TObject *Sender, int NewTab,
      bool &AllowChange)
{
    Notebook1->PageIndex = NewTab;
}
//---------------------------------------------------------------------------
