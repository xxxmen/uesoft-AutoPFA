// DrawPipeTool.cpp: implementation of the DrawPipeTool class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "DrawPipeTool.h"
#include "ComponentManager.h"
#include "Pipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DrawPipeTool::DrawPipeTool()
{

}

DrawPipeTool::~DrawPipeTool()
{

}

DrawPipeTool* DrawPipeTool::Instance(ComponentManager *pManager,int Size,int nID)
{
	static DrawPipeTool m_drawPipeTool;
	m_drawPipeTool.m_nSize = Size;
	m_drawPipeTool.m_nID   = nID;
	m_drawPipeTool.m_pManager = pManager;
	return &m_drawPipeTool;
}

void DrawPipeTool::Move(UINT nFlags,CPoint point,CDC* pDc)
{
	if(nFlags==MK_LBUTTON)
	{
		int nDrawMode=pDc->SetROP2(R2_NOT);
		pDc->MoveTo(m_downPt);
		pDc->LineTo(m_curPt);
		pDc->MoveTo(m_downPt);
		pDc->LineTo(point);
		pDc->SetROP2(nDrawMode);
		m_curPt = point;
	}
}

void DrawPipeTool::Draw(CDC* pDc)
{
}

void DrawPipeTool::UpClick(UINT nFlags, CPoint point)
{
	long a = point.x - m_downPt.x;
	long b = point.y - m_downPt.y;
	long c = sqrt( double(a*a + b*b) );
	if(c > 16)
	{
		Component *pComponent = NULL;
		Pipe *pPipe = NULL;
		pComponent = m_pManager->CreatComponent(m_nID);
		if(pComponent != NULL)
		{
			pPipe = dynamic_cast<Pipe*>(pComponent);
			UpData(pPipe,point);
		}	
	}
}
void DrawPipeTool::UpData(Pipe *pPipe,CPoint point)
{
	pPipe->ChangePosition(m_pManager,m_downPt,point,m_nSize);
}

void DrawPipeTool::DownClick(UINT nFlags, CPoint point)
{
	m_downPt = point;
	m_curPt = point;
}

void DrawPipeTool::Delete()
{
}

void DrawPipeTool::DrawMark(CDC *pDc, WorkSpaceRef &ref)
{

}

BOOL DrawPipeTool::IsManipulator(CPoint point)
{
	return FALSE;
}

int DrawPipeTool::CetTypeID()
{
	return 11;
}

CRect DrawPipeTool::Region(CPoint pt)const
{
	CRect rc(1,1,1,1);
	return rc;
}
