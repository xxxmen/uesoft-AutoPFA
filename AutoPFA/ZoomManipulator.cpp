// ZoomManipulator.cpp: implementation of the ZoomManipulator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "ZoomManipulator.h"
#include "AutoPFAView.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ZoomManipulator::ZoomManipulator()
{
}

ZoomManipulator::~ZoomManipulator()
{
}

ZoomManipulator* ZoomManipulator::Instance(CAutoPFAView *pView)
{
	static ZoomManipulator m_zoomManipulator;
	m_zoomManipulator.m_pView = pView;
	m_zoomManipulator.m_bManipulator = TRUE;
	return &m_zoomManipulator;
}

void ZoomManipulator::Move(UINT nFlags,CPoint point,CDC* pDc)
{
	if(nFlags==MK_LBUTTON)
	{
		int nDrawMode=pDc->SetROP2(R2_NOT);
		pDc->DrawFocusRect(m_Rc);
		m_Rc.SetRect(m_downPt,point);
		m_Rc.NormalizeRect();
		pDc->DrawFocusRect(m_Rc);
		pDc->SetROP2(nDrawMode);
	}
}

void ZoomManipulator::UpClick(UINT nFlags, CPoint point)
{
	m_Rc.SetRect(m_downPt,point);
	m_Rc.NormalizeRect();
	if(m_Rc.Height()>10 && m_Rc.Width()>10)
	{
		m_pView->ZoomScrollSizes(m_Rc,FALSE);
	}
	m_bManipulator = FALSE;
}

void ZoomManipulator::DownClick(UINT nFlags, CPoint point)
{
	m_downPt = point;
	m_Rc.SetRect(point,point);
}

void ZoomManipulator::Delete()
{
}

void ZoomManipulator::DrawMark(CDC *pDc, WorkSpaceRef &ref)
{
}


BOOL ZoomManipulator::IsManipulator(CPoint point)
{
	return m_bManipulator;
}

int ZoomManipulator::CetTypeID()
{
	return 20;
}

CRect ZoomManipulator::Region(CPoint pt)const
{
	CRect rc(1,1,1,1);
	return rc;
}
