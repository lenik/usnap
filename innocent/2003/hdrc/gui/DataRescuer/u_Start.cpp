//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "u_Start.h"
#include "u_Viewer.h"
#include "u_Progress.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmStart *frmStart;
//---------------------------------------------------------------------------
__fastcall TfrmStart::TfrmStart(TComponent* Owner)
    : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TfrmStart::Button1Click(TObject *Sender)
{
    TfrmViewer *v = new TfrmViewer(this);
    v->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TfrmStart::Button2Click(TObject *Sender)
{
    TfrmProgress *v = new TfrmProgress(NULL);
    v->ShowModal();
}
//---------------------------------------------------------------------------
