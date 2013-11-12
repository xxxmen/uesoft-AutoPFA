// PipeManipulator.cpp: implementation of the PipeManipulator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "PipeManipulator.h"
#include "WorkSpaceRef.h"
#include "Pipe.h"
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

PipeManipulator* PipeManipulator::Instance(Pipe *pPipe,ComponentManager *pManager,int Size,BOOL bSingle)
{
	if(bSingle)
	{
		static PipeManipulator m_pipeManipulator;
		m_pipeManipulator.m_nSize = Size;
		m_pipeManipulator.m_pPipe = pPipe;
		m_pipeManipulator.m_pManager = pManager;
		return &m_pipeManipulator;
	}
	else
	{
		PipeManipulator *pManipulator = new PipeManipulator;
		pManipulator->m_nSize = Size;
		pManipulator->m_pPipe = pPipe;
		pManipulator->m_pManager = pManager;
		return pManipulator;
	}
}

PipeManipulator::PipeManipulator()
{
	m_nType = 3;
}

PipeManipulator::~PipeManipulator()
{
}


void PipeManipulator::Drag(CDC* pDc,CPoint point)
{
	if(IsInClient(point))
	{
		CPoint startPt = m_stratPt;
		CPoint endPt   = m_endPt;
		CalcCoordinate(point,m_stratPt,m_endPt);
		m_curPt = point;
		Draw(pDc,startPt,endPt);
	}

}

void PipeManipulator::Move(UINT nFlags,CPoint point,CDC* pDc)
{
	if(nFlags == MK_LBUTTON)
	{
		Drag(pDc,point);
	}
	else
	{
		CSize sz(2,2);
		CPoint startPt = m_pPipe->StartPt();
		CPoint endPt = m_pPipe->EndPt();
		CRect startRc(startPt-sz,startPt+sz);
		CRect endRc(endPt-sz,endPt+sz);
		if(startRc.PtInRect(point))
		{
			m_nType = 1;
		}
		else if(endRc.PtInRect(point))
		{
			m_nType = 2;
		}
		else
		{
			m_nType = 3;
		}
	}

	if(m_nType ==1 || m_nType ==2)
	{
		::SetCursor(AfxGetApp()->LoadStandardCursor(IDC_CROSS));
	}
}

void PipeManipulator::Draw(CDC* pDc,CPoint startPt0,CPoint endPt0)
{
	int nDrawMode=pDc->SetROP2(R2_NOT);
	pDc->MoveTo(startPt0);
	pDc->LineTo(endPt0);
	pDc->MoveTo(m_stratPt);
	pDc->LineTo(m_endPt);
	pDc->SetROP2(nDrawMode);
}

void PipeManipulator::UpClick(UINT nFlags, CPoint point)
{
	m_pPipe->ChangePosition(m_pManager,m_stratPt,m_endPt,m_nSize);
}

void PipeManipulator::DownClick(UINT nFlags, CPoint point)
{
	m_curPt = point;
	m_stratPt = m_pPipe->StartPt();
	m_endPt   = m_pPipe->EndPt();
}

void PipeManipulator::Delete()
{
	m_pPipe->DelJunLink(m_pManager);
	m_pManager->Delete(m_pPipe->GetType(),m_pPipe->GetKey());
}

void PipeManipulator::DrawMark(CDC *pDc, WorkSpaceRef &ref)
{
	int nPipeStyle = PS_SOLID;
	int nPipeThick = ref.GetPipeThick();
	COLORREF pipeColor = ref.GetSelectItemColor();
	pDc->SetTextColor(ref.GetPipeText());
	m_pPipe->GetGarph()->DrawMark(pDc,pipeColor,nPipeStyle,nPipeThick);
}

BOOL PipeManipulator::IsManipulator(CPoint point)
{
	return m_pPipe->Pick(point,m_nSize);
}

int PipeManipulator::CetTypeID()
{
	return 1;
}

void PipeManipulator::Reverse()
{
	CPoint pt1 = m_pPipe->StartPt();
	CPoint pt2 = m_pPipe->EndPt();
	m_pPipe->ChangePosition(m_pManager,pt2,pt1,m_nSize);
}

BOOL PipeManipulator::DbClick(UnitSubSystem &UnitSys)
{
	return m_pPipe->Show(UnitSys,m_pManager);
}

Manipulator* PipeManipulator::Clone()
{
	Component *pComponent = m_pManager->CreatComponent(m_pPipe);
	if(pComponent != NULL)
	{
		Pipe *pPipe = dynamic_cast<Pipe*>(pComponent);
		CPoint pt1 = m_pPipe->StartPt();
	    CPoint pt2 = m_pPipe->EndPt();
		CSize sz(16,16);
		sz.cx = sz.cx * (float(m_nSize)/100);
		sz.cy = sz.cy * (float(m_nSize)/100);
		pPipe->StartPt(pt1+sz);
	    pPipe->EndPt(pt2+sz);
		pPipe->EmptyJunLink();//刪除保存的逻辑连接信息
		m_pPipe = pPipe;
	}
	return this;
}

CRect PipeManipulator::Region(CPoint pt)const
{
	CPoint pt1,pt2;
	CalcCoordinate(pt,pt1,pt2);
	CRect rc(pt1,pt2);
	rc.NormalizeRect();
	return rc;
}

void PipeManipulator::CalcCoordinate(CPoint point,CPoint &startPt,CPoint &endPt)const
{
	CSize szOff;
	switch(m_nType)
	{
	case 1:
		startPt = point;
		endPt  = m_endPt;
		break;
	case 2:
		startPt = m_stratPt;
		endPt = point;
		break;
	case 3:
		szOff = point - m_curPt;
		startPt = m_stratPt;
		endPt   = m_endPt;
		startPt.Offset(szOff);
		endPt.Offset(szOff);
		break;
	default:
		break;
	}
}
