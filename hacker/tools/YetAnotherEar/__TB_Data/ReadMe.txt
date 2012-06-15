========================================================================
       MICROSOFT FOUNDATION CLASS LIBRARY : __TB_Data
========================================================================


AppWizard has created this __TB_Data application for you.  This application
not only demonstrates the basics of using the Microsoft Foundation classes
but is also a starting point for writing your application.

This file contains a summary of what you will find in each of the files that
make up your __TB_Data application.

__TB_Data.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

__TB_Data.h
    This is the main header file for the application.  It includes other
    project specific headers (including Resource.h) and declares the
    C__TB_DataApp application class.

__TB_Data.cpp
    This is the main application source file that contains the application
    class C__TB_DataApp.

__TB_Data.rc
    This is a listing of all of the Microsoft Windows resources that the
    program uses.  It includes the icons, bitmaps, and cursors that are stored
    in the RES subdirectory.  This file can be directly edited in Microsoft
	Visual C++.

__TB_Data.clw
    This file contains information used by ClassWizard to edit existing
    classes or add new classes.  ClassWizard also uses this file to store
    information needed to create and edit message maps and dialog data
    maps and to create prototype member functions.

res\__TB_Data.ico
    This is an icon file, which is used as the application's icon.  This
    icon is included by the main resource file __TB_Data.rc.

res\__TB_Data.rc2
    This file contains resources that are not edited by Microsoft
	Visual C++.  You should place all resources not editable by
	the resource editor in this file.

__TB_Data.reg
    This is an example .REG file that shows you the kind of registration
    settings the framework will set for you.  You can use this as a .REG
    file to go along with your application or just delete it and rely
    on the default RegisterShellFileTypes registration.

__TB_Data.odl
    This file contains the Object Description Language source code for the
    type library of your application.


/////////////////////////////////////////////////////////////////////////////

For the main frame window:

MainFrm.h, MainFrm.cpp
    These files contain the frame class CMainFrame, which is derived from
    CMDIFrameWnd and controls all MDI frame features.

res\Toolbar.bmp
    This bitmap file is used to create tiled images for the toolbar.
    The initial toolbar and status bar are constructed in the CMainFrame
    class. Edit this toolbar bitmap using the resource editor, and
    update the IDR_MAINFRAME TOOLBAR array in __TB_Data.rc to add
    toolbar buttons.
/////////////////////////////////////////////////////////////////////////////

For the child frame window:

ChildFrm.h, ChildFrm.cpp
    These files define and implement the CChildFrame class, which
    supports the child windows in an MDI application.

/////////////////////////////////////////////////////////////////////////////

AppWizard creates one document type and one view:

__TB_DataDoc.h, __TB_DataDoc.cpp - the document
    These files contain your C__TB_DataDoc class.  Edit these files to
    add your special document data and to implement file saving and loading
    (via C__TB_DataDoc::Serialize).

__TB_DataView.h, __TB_DataView.cpp - the view of the document
    These files contain your C__TB_DataView class.
    C__TB_DataView objects are used to view C__TB_DataDoc objects.

res\__TB_DataDoc.ico
    This is an icon file, which is used as the icon for MDI child windows
    for the C__TB_DataDoc class.  This icon is included by the main
    resource file __TB_Data.rc.


/////////////////////////////////////////////////////////////////////////////
Other standard files:

StdAfx.h, StdAfx.cpp
    These files are used to build a precompiled header (PCH) file
    named __TB_Data.pch and a precompiled types file named StdAfx.obj.

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
