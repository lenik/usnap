//$$---- activex aboutbox header ---- (stAboutBoxHeader)
//---------------------------------------------------------------------------


#ifndef SHE_About1H
#define SHE_About1H
//---------------------------------------------------------------------------
#include <classes.hpp>
#include <controls.hpp>
#include <stdCtrls.hpp>
#include <forms.hpp>
#include <Buttons.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
//---------------------------------------------------------------------------
class TSmallHexEditAbout : public TForm
{
__published:	// IDE-managed Components
        TSpeedButton *CtlImage;
        TLabel *NameLbl;
        TLabel *DescLbl;
        TLabel *CopyrightLbl;
        TButton *OkBtn;
private:	// User declarations
public:		// User declarations
    __fastcall TSmallHexEditAbout(TComponent* Owner);
};
//---------------------------------------------------------------------------
void ShowSmallHexEditAbout(void);
//---------------------------------------------------------------------------
#endif
