// MazeDoc.h : interface of the CMazeDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAZEDOC_H__34B7488F_7EC3_4A58_84D7_BEF9FB723EE4__INCLUDED_)
#define AFX_MAZEDOC_H__34B7488F_7EC3_4A58_84D7_BEF9FB723EE4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "_Maze.h"

class CMazeDoc : public CDocument
{
protected: // create from serialization only
	CMazeDoc();
	DECLARE_DYNCREATE(CMazeDoc)

// Attributes
public:
	BoxMaze	maze;

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMazeDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMazeDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMazeDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAZEDOC_H__34B7488F_7EC3_4A58_84D7_BEF9FB723EE4__INCLUDED_)
