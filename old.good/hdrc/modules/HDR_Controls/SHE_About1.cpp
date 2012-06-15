//$$---- activex aboutbox source ---- (stAboutBoxSource)
//---------------------------------------------------------------------------


#include <vcl.h>
#pragma hdrstop

#include "SHE_About1.h"
//
// - Unable to find "COMSUPP.LIB"
//
// #include <startinc.h>
//---------------------------------------------------------------------------


#pragma package(smart_init)
#pragma resource "*.dfm"
//---------------------------------------------------------------------------
void ShowSmallHexEditAbout(void)
{
  TSmallHexEditAbout* Form;
  Form = new TSmallHexEditAbout(NULL);
  try
  {
    Form->ShowModal();
  }
  catch(...)
  {
    Form->Free();
    return;
  }
  Form->Free();
}
//---------------------------------------------------------------------------
__fastcall TSmallHexEditAbout::TSmallHexEditAbout(TComponent* Owner)
    : TForm(Owner)
{
}
