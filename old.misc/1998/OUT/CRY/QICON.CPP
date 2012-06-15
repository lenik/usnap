
#include "qicon.h"
#include "qiconl.cpp"

int	main(int argc, char **argv) {
  int i, b;
  ffblk ffblk;

  if (argc < 2) {
    printf("quick icon data generator	author: dansei, 1999.1.24\nqicon <qicon file>\n");
    return 1;
  }
  strcpy(myfile.filename, argv[1]);
  if (findfirst(argv[1], &ffblk, FA_RDONLY | FA_HIDDEN | FA_ARCH) == 0) {
    myfile.load();
  }

  if (myicons.i == NULL) {
    myicons.add();
  }

  randomize();
  initscr();

  do {
    i = getch();
    b = bioskey(2); 	// _KEYBRD_SHIFTSTATUS A- C- LS- RS-

    switch (i) {
      case 0:
	i = getch();
	switch (i) {
	  case 0x3B:	// F1	Help
	    utils.help(); break;
	  case 0x3C:	// F2	Save
	    myfile.save(); break;
	  case 0x3D:	// F3	Reload
	    myfile.load(); break;

	  case 0x3E:	// F4	New
	    myicons.clear(); break;
	  case 0x3F:	// F5	Add
	    myicons.add(); break;
	  case 0x52:	// <Insert>
	    myicons.ins(); break;
	  case 0x53:	// <Delete>
	    myicons.del(); break;

	  case 0x49:	// <Page up>
	    myicons.prev(); break;
	  case 0x84:	// <Ctrl>-<Page up>:	Page 1
	    myicons.top(); break;
	  case 0x51:	// <Page down>
	    myicons.next(); break;
	  case 0x76:	// <Ctrl-<Page Down>:	Last page
	    myicons.bottom(); break;

	  case 0x47:	// <Home>
	    if (b & 0x10) myicons.i->left(myicons.i->x);
	    else if (b & 3) myicons.i->cutleft(myicons.i->x);
	    else myicons.curhome(); break;
	  case 0x4F:	// <End>
	    if (b & 0x10) myicons.i->right(myicons.i->maxx * 8 - myicons.i->x - 1);
	    else if (b & 3) myicons.i->cutright(myicons.i->maxx * 8 - myicons.i->x - 1);
	    else myicons.curend(); break;
	  case 0x77:	// <Ctrl>-<Home>
	    if (b & 0x10) myicons.i->up(myicons.i->y);
	    else if (b & 3) myicons.i->cutup(myicons.i->y);
	    else myicons.curmostup(); break;
	  case 0x75:	// <Ctrl>-<End>
	    if (b & 0x10) myicons.i->down(myicons.i->maxy - myicons.i->y - 1);
	    else if (b & 3) myicons.i->cutdown(myicons.i->maxy - myicons.i->y - 1);
	    else myicons.curmostdown(); break;
	  case 0x4B:	// <Left>
	    if (b & 0x10) myicons.i->left(1);
	    else if (b & 3) myicons.i->cutleft(1);
	    else myicons.curleft(); break;
	  case 0x4D:	// <Right>
	    if (b & 0x10) myicons.i->right(1);
	    else if (b & 3) myicons.i->cutright(1);
	    else myicons.curright(); break;
	  case 0x48:	// <Up>
	    if (b & 0x10) myicons.i->up(1);
	    else if (b & 3) myicons.i->cutup(1);
	    else myicons.curup(); break;
	  case 0x50:	// <Down>
	    if (b & 0x10) myicons.i->down(1);
	    else if (b & 3) myicons.i->cutdown(1);
	    else myicons.curdown(); break;

	  case 0x21:	// Alt-F	Full
	    myicons.i->full(); break;
	  case 0x2E:	// Alt-C	Clear
	    myicons.i->clear(); break;
	  case 0x31:	// Alt-N	Noise
	    myicons.i->noise(); break;

	  case 0x62:	// Ctrl-F5	File set
	    utils.fileset(); break;
	  case 0x63:	// Ctrl-F6	System set
	    utils.sysset(); break;
	  case 0x64:	// Ctrl-F7	Font set
	    utils.fontset(); break;

	  case 0x2D:	// Alt-X	Exit
	    utils.exit(); break;
	  default:;
	} break;

      case 'r':
	clrscr(); break;

      case 'd':
	myicons.i->pen = Draw; break;
      case 'e':
	myicons.i->pen = Erase; break;
      case 'i':
	myicons.i->pen = Invert; break;
      case 'v':
	myicons.i->pen = View; break;

      case ' ':
	myicons.curinvert(); break;
      case 8:		// Ctrl-H, <BS>:	Fill
	myicons.i->fill(); break;
      case 9:           // Ctrl-I, Tab:		Invert
	myicons.i->invert(); break;
      case 0xF:		// Ctrl-O:		Outline
	myicons.i->outline(); break;
      case 'x':
	myicons.i->invertx(); break;
      case 'y':
	myicons.i->inverty(); break;

      case '=':
	myicons.incw(1); break;
      case '-':
	myicons.incw(-1); break;
      case '+':
	myicons.inch(1); break;
      case '_':
	myicons.inch(-1); break;

      case 'c':
	copybuf(); break;
      case 'p':
	pastebuf(); break;

      case 1:		// Ctrl-A
	myicons.i->redo(); break;
      case 26:		// Ctrl-Z
	myicons.i->undo(); break;

      case 'q':
	utils.exit(); break;
    }
    if (myicons.i == NULL) {
      myicons.add();
    }
    myicons.changed = myicons.i->noring() != True;
    myicons.refresh();
  } while (1);
}
