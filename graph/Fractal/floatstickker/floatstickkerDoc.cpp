// floatstickkerDoc.cpp : implementation of the CFloatstickkerDoc class
//

#include "stdafx.h"
#include "floatstickker.h"
#include "floatstickkerDoc.h"
#include "GetParametersDialog.h"

#include <math.h>

#define PI		3.1415926535897

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerDoc

IMPLEMENT_DYNCREATE(CFloatstickkerDoc, CDocument)

BEGIN_MESSAGE_MAP(CFloatstickkerDoc, CDocument)
	//{{AFX_MSG_MAP(CFloatstickkerDoc)
	ON_COMMAND(ID_BUTTON_SET_PARAMETERS, OnButtonSetParameters)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerDoc construction/destruction

CFloatstickkerDoc::CFloatstickkerDoc()
{
	this->p_nums	= 100;
	this->p_power	= 1/360.0;
	this->p_radius	= 0.03;
	this->p_speed	= 0.01;
}

CFloatstickkerDoc::~CFloatstickkerDoc()
{
}

BOOL CFloatstickkerDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	regenerate();

	this->UpdateAllViews(NULL);

	return TRUE;
}


void CFloatstickkerDoc::regenerate() {
	stickked.RemoveAll();

	stickked.AddTail(PT(0, 0));

	for (int i = 0; i < p_nums; ++i) {
		PT newp;
		double newa = (double)::rand() / RAND_MAX * 2 * PI;
		newp.x = cos(newa);
		newp.y = sin(newa);

		while (notcollision(newp)) {
			double olddist = sqrt(newp.x * newp.x + newp.y * newp.y);
			double newdist = olddist - p_speed;
			if (newdist < 0) break;
			double oldangle = atan2(newp.y, newp.x);
			double newangle = oldangle + rand() / RAND_MAX * 2 * PI * p_power;
			newp.x = newdist * cos(newangle);
			newp.y = newdist * sin(newangle);
		}
		stickked.AddTail(newp);

		//this->UpdateAllViews(NULL);
	}
}
BOOL CFloatstickkerDoc::notcollision(CFloatstickkerDoc::PT p) {
	POSITION pos;
	for (pos = stickked.GetHeadPosition(); pos != NULL; stickked.GetNext(pos)) {
		PT pi = stickked.GetAt(pos);
		if (sqrt((pi.x - p.x) * (pi.x - p.x) + (pi.y - p.y) * (pi.y - p.y))
			<= (this->p_radius * 2)) {
			return FALSE;
		}
	}
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerDoc serialization

void CFloatstickkerDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerDoc diagnostics

#ifdef _DEBUG
void CFloatstickkerDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CFloatstickkerDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CFloatstickkerDoc commands

void CFloatstickkerDoc::OnButtonSetParameters()
{
	// TODO: Add your command handler code here
	CGetParametersDialog gpdlg;
	gpdlg.m_nums	= this->p_nums;
	gpdlg.m_speed	= this->p_speed;
	gpdlg.m_power	= this->p_power;
	gpdlg.m_radius	= this->p_radius;
	if (gpdlg.DoModal()) {
		this->p_nums	= gpdlg.m_nums;
		this->p_speed	= gpdlg.m_speed;
		this->p_power	= gpdlg.m_power;
		this->p_radius	= gpdlg.m_radius;
		regenerate();
		this->UpdateAllViews(NULL);
	}
}
