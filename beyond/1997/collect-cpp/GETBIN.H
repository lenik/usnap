#define Uses_TKeys
#define Uses_TApplication
#define Uses_TEvent
#define Uses_TRect
#define Uses_TDialog
#define Uses_TStaticText
#define Uses_TButton
#define Uses_TMenuBar
#define Uses_TSubMenu
#define Uses_TMenuItem
#define Uses_TStatusLine
#define Uses_TStatusItem
#define Uses_TStatusDef
#define Uses_TDeskTop
#include <tv.h>

const int SysMenu		=100;
const int PuzzleCmd		=110;
const int CalendarCmd		=120;
const int AsciiTableCmd		=130;
const int CalculatorCmd		=140;

const int FileMenu		=200;
const int OpenCmd		=210;
const int SaveCmd		=220;
const int SaveAsCmd		=230;
const int ExitCmd		=240;

const int OptionMenu		=300;
const int ArrayMenu		=310;
const int ArrayCheckCmd		=311;
const int ArrayLevelCmd		=312;
const int InitArrayCmd		=313;
const int CommasCheckCmd	=320;
const int RadixMenu		=330;
const int RadixBinaryCheckCmd	=331;
const int RadixOctalCheckCmd	=332;
const int RadixDecimalCheckCmd	=333;
const int RadixHexCheckCmd	=334;
const int RadixOtherCheckCmd	=335;
const int RadixPrecedeCmd	=336;
const int RadixFollowCmd	=337;
const int RadixEncyrptCmd	=340;
const int RadixCompressCmd	=350;

const int WindowMenu		=400;
const int WinBinaryFileCmd	=480;
const int WinOutputFileCmd	=490;

const int HelpMenu		=500;
const int HelpContentsCmd	=510;
const int HelpIndexCmd		=520;
const int HelpOnHelpCmd		=530;
const int AboutCmd		=540;

class ArrayTree{
  ArrayTree **Sub;
  ArrayTree *Parent;
  int Value;
  ArrayTree(int v=1) { Value=v; }
  void newSub(int n){
    (*Sub)=new ArrayTree[n];
  }
};

/*
->Array: 4_
->Config? Y_
->Array[1]: 12_
->Config? N_
->Array[2]: 2_
->Config? Y_
->Array[2][1]: 1_
->Array[2][2]: 1_
->Array[3]: 1_
->Array[4]: 1_
*/

/*
Game  	 File            Option               Window          Help
  Puzzle   Open ...        Array                Size/Move       Contents
  Calendar Save              [x] Array          Zoom            Index
  Ascii	   Save as...        		        Cascade         Help on help
  Calc	   Exit              Init Array...      Tile            -
			   [x] Commas           Next            About
			   Radix                Close
			     [x] Binary         Close All
			     [x] Octal          -
			     [x] Decimal        Binary File
			     [x] Hex            Output File
			     [x] Other...
			     Precede...
			     Follow...
			   (Encyrpt)
			   (Compress)
*/

class TGetBinApp:public TApplication{
public:
  TGetBinApp(int argc, char **argv);
  virtual void handleEvent(TEvent&);
  static TMenuBar *initMenuBar(TRect);
  static TStatusLine *initStatusLine(TRect);
private:
  int Radix;
  char *Precede, *Follow;
  int Commas;
  char *FileOpen, *FileSave;

  void Puzzle();
  void Calendar();
  void AsciiTable();
  void Calculator();

  void OpenFile(char *);
  void SaveFile();
  void SaveAsFile(char *);

  void ArrayCheck();
  void InitArray();
  void CommasCheck();
  void RadixBinaryCheck();
  void RadixOctalCheck();
  void RadixDecimalCheck();
  void RadixHexCheck();
  void RadixOtherCheck();
  void RadixPrecede();
  void RadixFollow();
  void Encyrpt();
  void Compress();

  void Tile();
  void Cascade();
  void WinBinaryFile();
  void WinOutputFile();

  void HelpContents();
  void HelpIndex();
  void HelpOnHelp();
  void About();
};
