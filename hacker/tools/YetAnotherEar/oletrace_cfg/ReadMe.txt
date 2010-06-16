========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : oletrace_cfg
========================================================================


AppWizard has created this oletrace_cfg application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your oletrace_cfg application.

oletrace_cfg.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

oletrace_cfg.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    COletrace_cfgApp application class.

oletrace_cfg.cpp
    This is the main application source file that contains the application
    class COletrace_cfgApp.

oletrace_cfg.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

oletrace_cfg.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\oletrace_cfg.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file oletrace_cfg.rc.

res\oletrace_cfg.rc2
    This file contains resources that are not edited by Microsoft
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.




/////////////////////////////////////////////////////////////////////////////

AppWizard creates one dialog class:

oletrace_cfgDlg.h, oletrace_cfgDlg.cpp - the dialog
    These files contain your COletrace_cfgDlg class.  This class defines
    the behavior of your application's main dialog.  The dialog's
    template is in oletrace_cfg.rc, which can be edited in Microsoft
	Visual C++.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named oletrace_cfg.pch and a precompiled types file named StdAfx.obj.

Resource.h
    This is the standard header file, which defines new resource IDs.
    Microsoft Visual C++ reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

AppWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

If your application uses MFC in a shared DLL, and your application is
in a language other than the operating system's current language, you
will need to copy the corresponding localized resources MFC42XXX.DLL
from the Microsoft Visual C++ CD-ROM onto the system or system32 directory,
and rename it to be MFCLOC.DLL.  ("XXX" stands for the language abbreviation.
For example, MFC42DEU.DLL contains resources translated to German.)  If you
don't do this, some of the UI elements of your application will remain in the
language of the operating system.

/////////////////////////////////////////////////////////////////////////////
