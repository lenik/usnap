//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "u_Viewer.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmViewer *frmViewer;
//---------------------------------------------------------------------------
__fastcall TfrmViewer::TfrmViewer(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmViewer::TabSet1Change(TObject *Sender, int NewTab,
      bool &AllowChange)
{
    // TString selStr = TabSet1->Tabs->Strings[NewTab];

    Notebook1->PageIndex = NewTab;
}
//---------------------------------------------------------------------------
