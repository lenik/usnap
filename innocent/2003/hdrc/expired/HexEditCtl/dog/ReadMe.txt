========================================================================
		ActiveX Control DLL : DOG
========================================================================

ControlWizard has created this project for your DOG ActiveX Control
DLL, which contains 1 control.

This skeleton project not only demonstrates the basics of writing an
ActiveX Control, but is also a starting point for writing the specific
features of your control.

This file contains a summary of what you will find in each of the files
that make up your DOG ActiveX Control DLL.

dog.dsp
    This file (the project file) contains information at the project level and
    is used to build a single project or subproject. Other users can share the
    project (.dsp) file, but they should export the makefiles locally.

dog.h
	This is the main include file for the ActiveX Control DLL.  It
	includes other project-specific includes such as resource.h.

dog.cpp
	This is the main source file that contains code for DLL initialization,
	termination and other bookkeeping.

dog.rc
	This is a listing of the Microsoft Windows resources that the project
	uses.  This file can be directly edited with the Visual C++ resource
	editor.

dog.def
	This file contains information about the ActiveX Control DLL that
	must be provided to run with Microsoft Windows.

dog.clw
	This file contains information used by ClassWizard to edit existing
	classes or add new classes.  ClassWizard also uses this file to store
	information needed to generate and edit message maps and dialog data
	maps and to generate prototype member functions.

dog.odl
	This file contains the Object Description Language source code for the
	type library of your control.

/////////////////////////////////////////////////////////////////////////////
Dog control:

DogCtl.h
	This file contains the declaration of the CDogCtrl C++ class.

DogCtl.cpp
	This file contains the implementation of the CDogCtrl C++ class.

DogPpg.h
	This file contains the declaration of the CDogPropPage C++ class.

DogPpg.cpp
	This file contains the implementation of the CDogPropPage C++ class.

DogCtl.bmp
	This file contains a bitmap that a container will use to represent the
	CDogCtrl control when it appears on a tool palette.  This bitmap
	is included by the main resource file dog.rc.

/////////////////////////////////////////////////////////////////////////////
Other standard files:

stdafx.h, stdafx.cpp
	These files are used to build a precompiled header (PCH) file
	named stdafx.pch and a precompiled types (PCT) file named stdafx.obj.

resource.h
	This is the standard header file, which defines new resource IDs.
	The Visual C++ resource editor reads and updates this file.

/////////////////////////////////////////////////////////////////////////////
Other notes:

ControlWizard uses "TODO:" to indicate parts of the source code you
should add to or customize.

/////////////////////////////////////////////////////////////////////////////
