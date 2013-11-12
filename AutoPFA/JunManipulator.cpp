// JunManipulator.cpp: implementation of the JunManipulator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "JunManipulator.h"
#include "WorkSpaceRef.h"
#include "Jun.h"
#include "Graphics.h"
#include "ComponentManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
 

JunManipulator::JunManipulator()
{

}

JunManipulator::~JunManipulator()
{

}

JunManipulator* JunManipulator::Instance(Jun *pJun,ComponentManager *pManager,int Size,BOOL bSingle)
{
	if(bSingle)
	{
		static JunManipulator m_JunManipulator;
		m_JunManipulator.m_nSize = Size;
		m_JunManipulator.m_pJun = pJun;
		m_JunManipulator.m_pManager = pManager;
		return &m_JunManipulator;
	}
	else
	{
		JunManipulator *pManipulator = new JunManipulator;
        pManipulator->m_nSize = Size;
		pManipulator->m_pJun = pJun;
		pManipulator->m_pManager = pManager;
		return pManipulator;
	}
}

void JunManipulator::Drag(CDC* pDc,CPoint point)
{
	if(IsInClient(point))
	{
		Draw(pDc,point);
		m_curPt = point;
	}
}

void JunManipulator::Move(UINT nFlags,CPoint point,CDC* pDc)
{
	if(nFlags==MK_LBUTTON)
	{
		Drag(pDc,point);
	}
}

void JunManipulator::Draw(CDC* pDc,CPoint point)
{
	CSize sz(16,16);
	sz.cx = sz.cx * (float(m_nSize)/100);
	sz.cy = sz.cy * (float(m_nSize)/100);
	int nDrawMode=pDc->SetROP2(R2_NOT);

	CPoint oldCenter(m_curPt);
	oldCenter.Offset(m_centerOff);
    CRect oldRc(oldCenter-sz,oldCenter+sz);
	pDc->DrawFocusRect(oldRc);

	CPoint newCenter(point);
	newCenter.Offset(m_centerOff);
    CRect newRc(newCenter-sz,newCenter+sz);
	pDc->DrawFocusRect(newRc);
	pDc->SetROP2(nDrawMode);
}

void JunManipulator::UpClick(UINT nFlags, CPoint point)
{
	m_curPt.Offset(m_centerOff);
	m_pJun->ChangePosition(m_pManager,m_curPt,m_nSize);
}

void JunManipulator::DownClick(UINT nFlags, CPoint point)
{
	CSize offSz;
	m_downPt = point;
	m_curPt  = point;
	m_centerOff = m_pJun->CenterPt() - point;
}

void JunManipulator::Delete()
{
	m_pJun->EmptyLinkPipe(m_pManager);
	m_pManager->Delete(m_pJun->GetType(),m_pJun->GetKey());
}

void JunManipulator::DrawMark(CDC *pDc, WorkSpaceRef &ref)
{
	int nJunStyle = PS_SOLID;
	int nJunThick = ref.GetPipeThick();
	int nSize = ref.GetJunSize();
	COLORREF JunColor = ref.GetSelectItemColor();
	pDc->SetTextColor(ref.GetJunText());
	m_pJun->GetGarph()->DrawMark(pDc,JunColor,nJunStyle,nJunThick,nSize);
}

BOOL JunManipulator::IsManipulator(CPoint point)
{
	return m_pJun->Pick(point,m_nSize);
}

int JunManipulator::CetTypeID()
{
	return 2;
}

Manipulator* JunManipulator::Clone()
{
	Component *pComponent = m_pManager->CreatComponent(m_pJun);
	if(pComponent != NULL)
	{
		Jun *pJun = dynamic_cast<Jun*>(pComponent);
		CPoint ptCenter = m_pJun->CenterPt();
		CSize sz(16,16);
		sz.cx = sz.cx * (float(m_nSize)/100);
		sz.cy = sz.cy * (float(m_nSize)/100);
		pJun->CenterPt(ptCenter+sz);
		pJun->EmptyLinkPipe();
		m_pJun = pJun;
	}
	return this;
}

BOOL JunManipulator::DbClick(UnitSubSystem &UnitSys)
{
	return m_pJun->Show(UnitSys,m_pManager);
}

CRect JunManipulator::Region(CPoint pt)const
{
	CPoint center(pt);
	center.Offset(m_centerOff);
	CSize sz(16,16);
	sz.cx = sz.cx * (float(m_nSize)/100);
	sz.cy = sz.cy * (float(m_nSize)/100);
    CRect rc(center-sz,center+sz);
	rc.NormalizeRect();
	return rc;
}
