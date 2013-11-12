// MacroManipulator.cpp: implementation of the MacroManipulator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "MacroManipulator.h"
#include "Component.h"
#include "ComponentManager.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

MacroManipulator* MacroManipulator::Instance(ComponentManager *pManager,int Size)
{
	static MacroManipulator m_macroManipulator;
	m_macroManipulator.m_pManager = pManager;
	m_macroManipulator.m_nSize    = Size;
	m_macroManipulator.m_bManipulator = FALSE;
	m_macroManipulator.DelManipulator();
	return &m_macroManipulator;
}

MacroManipulator::MacroManipulator()
{

}

MacroManipulator::~MacroManipulator()
{
	DelManipulator();
}

void MacroManipulator::Add(Component *pComponent)
{
	Manipulator *pManipulator = NULL;
	pManipulator = pComponent->CreatManipulator(m_pManager,m_nSize,FALSE);
	m_ManiList.AddTail(pManipulator);
}


void MacroManipulator::Move(UINT nFlags,CPoint point,CDC* pDc)
{
	if(m_bManipulator)
	{
		if(IsInClient(point))
		{
			POSITION pos = m_ManiList.GetHeadPosition();
			Manipulator *pManipulator = NULL;
			while(pos)
			{
				pManipulator = m_ManiList.GetNext(pos);
				pManipulator->Move(nFlags,point,pDc);
			}
		}
	}
	else
	{
		if(nFlags==MK_LBUTTON)
		{
			Draw(pDc,point);
		}
	}

}

void MacroManipulator::UpClick(UINT nFlags, CPoint point)
{
	if(m_bManipulator)
	{
		POSITION pos = m_ManiList.GetHeadPosition();
		Manipulator *pManipulator = NULL;
		while(pos)
		{
			pManipulator = m_ManiList.GetNext(pos);
			pManipulator->UpClick(nFlags,point);
		}
		m_bManipulator = FALSE;
	}
	else
	{
		m_Rc.SetRect(m_downPt,point);
		m_Rc.NormalizeRect();
		m_pManager->InitSelectTool(m_Rc,this);	
	}

}

void MacroManipulator::DownClick(UINT nFlags, CPoint point)
{
	if(m_bManipulator)
	{
		POSITION pos = m_ManiList.GetHeadPosition();
		Manipulator *pManipulator = NULL;
		while(pos)
		{
			pManipulator = m_ManiList.GetNext(pos);
			pManipulator->DownClick(nFlags,point);
		}
	}
	else
	{
		m_downPt = point;
		m_Rc.SetRect(point,point);
	}
	
}

void MacroManipulator::Delete()
{
	POSITION pos = m_ManiList.GetHeadPosition();
	Manipulator *pManipulator = NULL;
	while(pos)
	{
		pManipulator = m_ManiList.GetNext(pos);
		pManipulator->Delete();
	}	
}

void MacroManipulator::DrawMark(CDC *pDc, WorkSpaceRef &ref)
{
	POSITION pos = m_ManiList.GetHeadPosition();
	Manipulator *pManipulator = NULL;
	while(pos)
	{
		pManipulator = m_ManiList.GetNext(pos);
		pManipulator->DrawMark(pDc,ref);
	}	
}

BOOL MacroManipulator::IsManipulator(CPoint point)
{
	POSITION pos = m_ManiList.GetHeadPosition();
	Manipulator *pManipulator = NULL;
	while(pos)
	{
		pManipulator = m_ManiList.GetNext(pos);
		if(pManipulator->IsManipulator(point))
		{
			m_bManipulator = TRUE;
			break;
		}
	}
	return m_bManipulator;
}

void MacroManipulator::Draw(CDC* pDc,CPoint point)
{
	int nDrawMode=pDc->SetROP2(R2_NOT);
	pDc->DrawFocusRect(m_Rc);
	m_Rc.SetRect(m_downPt,point);
	m_Rc.NormalizeRect();
	pDc->DrawFocusRect(m_Rc);
	pDc->SetROP2(nDrawMode);
}

void MacroManipulator::DelManipulator()
{
	POSITION pos = m_ManiList.GetHeadPosition();
	Manipulator *pManipulator = NULL;
	while(pos)
	{
		pManipulator = m_ManiList.GetNext(pos);
		delete pManipulator;
	}
	m_ManiList.RemoveAll();
}

int MacroManipulator::CetTypeID()
{
	return 3;
}


Manipulator* MacroManipulator::Clone()
{
	POSITION pos = m_ManiList.GetHeadPosition();
	Manipulator *pManipulator = NULL;
	while(pos)
	{
		pManipulator = m_ManiList.GetNext(pos);
		pManipulator->Clone();
	}
	return this;
}

CRect MacroManipulator::Region(CPoint pt)const
{
	CRect rc;
	CRect tempRc;
	POSITION pos = m_ManiList.GetHeadPosition();
	Manipulator *pManipulator = NULL;
	if(pos)
	{
		pManipulator = m_ManiList.GetNext(pos);
		rc = pManipulator->Region(pt);
	}
	while(pos)
	{
		pManipulator = m_ManiList.GetNext(pos);
		tempRc = pManipulator->Region(pt);
		{
			if(rc.top>tempRc.top)
				rc.top = tempRc.top;
			if(rc.left>tempRc.left)
				rc.left = tempRc.left;
			if(rc.bottom<tempRc.bottom)
				rc.bottom=tempRc.bottom;
			if(rc.right<tempRc.right)
				rc.right=tempRc.right;
		}
	}
	return rc;
}
