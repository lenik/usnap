//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("u_Start.cpp", frmStart);
USEFORM("u_Viewer.cpp", frmViewer);
USEFORM("u_Progress.cpp", frmProgress);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->Title = "ÖÇÄÜÓ²ÅÌÊý¾Ý»Ö¸´";
         Application->CreateForm(__classid(TfrmStart), &frmStart);
         Application->CreateForm(__classid(TfrmViewer), &frmViewer);
         Application->CreateForm(__classid(TfrmProgress), &frmProgress);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    catch (...)
    {
         try
         {
             throw Exception("");
         }
         catch (Exception &exception)
         {
             Application->ShowException(&exception);
         }
    }
    return 0;
}
//---------------------------------------------------------------------------
