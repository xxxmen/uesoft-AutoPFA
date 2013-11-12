// DrawJunTool.cpp: implementation of the DrawJunTool class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "DrawJunTool.h"
#include "Jun.h"
#include "ComponentManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DrawJunTool::DrawJunTool()
{

}

DrawJunTool::~DrawJunTool()
{

}

DrawJunTool* DrawJunTool::Instance(ComponentManager *pManager,int Size,int nID)
{
	static DrawJunTool m_drawJunTool;
	m_drawJunTool.m_nSize = Size;
	m_drawJunTool.m_nID   = nID;
	m_drawJunTool.m_pManager = pManager;
	return &m_drawJunTool;
}

void DrawJunTool::Move(UINT nFlags,CPoint point,CDC* pDc)
{
}

void DrawJunTool::UpClick(UINT nFlags, CPoint point)
{
}

void DrawJunTool::DownClick(UINT nFlags, CPoint point)
{
	Component *pComponent = NULL;
	Jun *pJun = NULL;
	pComponent = m_pManager->CreatComponent(m_nID);
	if(pComponent != NULL)
	{
		pJun = dynamic_cast<Jun*>(pComponent);
		UpData(pJun,point);
	}
}

void DrawJunTool::Delete()
{
}

void DrawJunTool::DrawMark(CDC *pDc, WorkSpaceRef &ref)
{
}

void DrawJunTool::UpData(Jun *pJun,CPoint point)
{
	pJun->ChangePosition(m_pManager,point,m_nSize);
}

BOOL DrawJunTool::IsManipulator(CPoint point)
{
	return FALSE;
}

int DrawJunTool::CetTypeID()
{
	return 12;
}

CRect DrawJunTool::Region(CPoint pt)const
{
	CRect rc(1,1,1,1);
	return rc;
}
