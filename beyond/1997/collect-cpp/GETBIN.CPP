#include "GetBin.h"
#include "GetBinT.cpp"

TGetBinApp::TGetBinApp(int argc, char **argv):TProgInit(&TGetBinApp::initStatusLine, &TGetBinApp::initMenuBar, &TGetBinApp::initDeskTop){
}

void TGetBinApp::handleEvent(TEvent &event){
  TApplication::handleEvent(event);
  if (event.what==evCommand) {
    switch (event.message.command){
      case AboutCmd:
	About();
	break;
    }
    clearEvent(event);
  }
}

TMenuBar *TGetBinApp::initMenuBar(TRect r){
  r.b.y=r.a.y+1;
  TSubMenu &_sysmenu=
    *new TSubMenu("~\x3~", 0, SysMenu)+
      *new TMenuItem("~P~uzzle", PuzzleCmd, kbNoKey, PuzzleCmd)+
      *new TMenuItem("Ca~l~endar", CalendarCmd, kbNoKey, CalendarCmd)+
      *new TMenuItem("~A~scii Table", AsciiTableCmd, kbNoKey, AsciiTableCmd)+
      *new TMenuItem("~C~alculator", CalculatorCmd, kbNoKey, CalculatorCmd);
  TSubMenu &_filemenu=
    *new TSubMenu("~F~ile", 0, FileMenu)+
      *new TMenuItem("~O~pen...", OpenCmd, kbF3, OpenCmd, "F3")+
      *new TMenuItem("~S~ave", SaveCmd, kbF2, OpenCmd, "F2")+
      *new TMenuItem("Save a~s~...", SaveAsCmd, kbNoKey, SaveAsCmd)+
      *new TMenuItem("E~x~it", cmQuit, cmQuit, hcNoContext, "Alt-X");

    TSubMenu &__arraysubmenu=
      *new TSubMenu("~A~rray", 0, ArrayMenu)+
	*new TMenuItem("~E~nable Array", ArrayCheckCmd, kbNoKey, ArrayCheckCmd)+
	*new TMenuItem("~I~nitializing Array...", InitArrayCmd, kbNoKey, InitArrayCmd);
    TSubMenu &__radixsubmenu=
      *new TSubMenu("~R~adix", 0, RadixMenu)+
	*new TMenuItem(" ~2~ Binary", RadixBinaryCheckCmd, kbNoKey, RadixBinaryCheckCmd)+
	*new TMenuItem(" ~8~ Octal", RadixOctalCheckCmd, kbNoKey, RadixOctalCheckCmd)+
	*new TMenuItem(" ~1~0 Decimal", RadixDecimalCheckCmd, kbNoKey, RadixDecimalCheckCmd)+
	*new TMenuItem("*1~6~ Hex", RadixHexCheckCmd, kbNoKey, RadixHexCheckCmd)+
	*new TMenuItem(" Other...", RadixOtherCheckCmd, kbNoKey, RadixOtherCheckCmd)+
	*new TMenuItem("~P~recede...", RadixPrecedeCmd, kbNoKey, RadixPrecedeCmd)+
	*new TMenuItem("~F~ollow...", RadixFollowCmd, kbNoKey, RadixFollowCmd);
  TSubMenu &_optionmenu=
    *new TSubMenu("~O~ption", 0, OptionMenu)+
      *new TMenuItem("Put ~C~ommas", CommasCheckCmd, kbNoKey, CommasCheckCmd)+
	   __arraysubmenu+
	   __radixsubmenu+
      *new TMenuItem("~E~ncyrpt...", RadixEncyrptCmd, kbNoKey, RadixEncyrptCmd)+
      *new TMenuItem("~C~ompress...", RadixCompressCmd, kbNoKey, RadixCompressCmd);
  TSubMenu &_windowmenu=
    *new TSubMenu("~W~indow", 0, WindowMenu)+
      *new TMenuItem("Re~S~ize/Move", cmResize, kbCtrlF5, cmResize, "Ctrl-F5")+
      *new TMenuItem("~Z~oom", cmZoom, kbF5, cmZoom, "F5")+
      *new TMenuItem("~C~ascade", cmCascade, kbNoKey, cmCascade)+
      *new TMenuItem("~T~ile", cmTile, kbNoKey, cmTile)+
      *new TMenuItem("~N~ext", cmNext, kbF6, cmNext, "F6")+
      *new TMenuItem("C~l~ose", cmClose, kbAltF3, cmClose, "Alt-F3")+
      //*new TMenuItem("Close ~A~ll", cmCloseAll, kbNoKey, cmCloseAll)+
       newLine()+
      *new TMenuItem("~B~inary File", WinBinaryFileCmd, kbNoKey, WinBinaryFileCmd)+
      *new TMenuItem("~O~utput File", WinOutputFileCmd, kbNoKey, WinOutputFileCmd);
  TSubMenu &_helpmenu=
    *new TSubMenu("~H~elp", 0, HelpMenu)+
      *new TMenuItem("~C~ontents", HelpContentsCmd, kbF1, HelpContentsCmd, "F1")+
      *new TMenuItem("~I~ndex", HelpIndexCmd, kbShiftF1, HelpIndexCmd, "Shift-F1")+
      *new TMenuItem("Help ~o~n Help", HelpOnHelpCmd, kbNoKey, HelpOnHelpCmd)+
       newLine()+
      *new TMenuItem("~A~bout", AboutCmd, kbNoKey, AboutCmd);
  return new TMenuBar(r, _sysmenu+_filemenu+_optionmenu+_windowmenu+_helpmenu);
}

TStatusLine *TGetBinApp::initStatusLine(TRect r){
  r.a.y=r.b.y-1;
  return new TStatusLine(r,
    *new TStatusDef(0, 0xffff)+
      *new TStatusItem("~Alt-X~ Exit", kbAltX, cmQuit)+
      *new TStatusItem("~F1~ Help", kbF1, HelpContentsCmd)+
      *new TStatusItem("~Ctrl-A~ Array", kbCtrlA, ArrayMenu)+
      *new TStatusItem("~Ctrl-R~ Radix", kbCtrlR, RadixMenu)+
      *new TStatusItem("~F10~ Menu", kbF10, cmMenu)
  );
}

void main(int argc, char **argv){
  TGetBinApp GetBinAppInst(argc, argv);
  GetBinAppInst.run();
  return;
}
