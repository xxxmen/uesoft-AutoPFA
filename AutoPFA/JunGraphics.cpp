// JunGraphics.cpp: implementation of the JunGraphics class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "JunGraphics.h"
#include "JunManipulator.h"
#include "Jun.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

JunGraphics::JunGraphics()
{

}

JunGraphics::~JunGraphics()
{

}


JunGraphics* JunGraphics::Instance(Jun *pJun)
{
	static JunGraphics m_junGraphics;
    m_junGraphics.m_pJun = pJun;
	return &m_junGraphics;
}

BOOL JunGraphics::Pick(CPoint point,int Size)
{
	CSize sz(16,16);
	sz.cx = sz.cx * (float(Size)/100);
	sz.cy = sz.cy * (float(Size)/100);
	CPoint topleft = m_pJun->CenterPt()-sz;
	CPoint bottomright = m_pJun->CenterPt()+sz;
	CRect rc(topleft,bottomright);
	return rc.PtInRect(point);
}

void JunGraphics::Draw(CDC *pDc,COLORREF color,int nStyle,int nWidth,int Size)
{
	CSize sz(16,16);
	sz.cx = sz.cx * (float(Size)/100);
	sz.cy = sz.cy * (float(Size)/100);
	CPoint topleft = m_pJun->CenterPt()-sz;
	CPoint bottomright = m_pJun->CenterPt()+sz;
	CPen *pNewPen=new CPen; 
	CRect rc(topleft,bottomright);
	pNewPen->CreatePen(nStyle,nWidth,color);
	CPen *pOldPen = pDc->SelectObject(pNewPen);
	pDc->Rectangle(rc);
	pDc->SelectObject(pOldPen);
	
	CDC dcMem;
	BITMAP bm;
	dcMem.CreateCompatibleDC(pDc);
	CBitmap& bitmap = m_pJun->GetBitMap();
	bitmap.GetObject(sizeof(bm),&bm);
	CBitmap* oldbmp=dcMem.SelectObject(&bitmap);
	pDc->SetStretchBltMode(COLORONCOLOR);
	pDc->StretchBlt(rc.left,rc.top,rc.right-rc.left,rc.bottom-rc.top,&dcMem,0,0,bm.bmWidth,bm.bmHeight,SRCAND);
	dcMem.SelectObject(oldbmp);

    CString strText;
	CPoint pointText(rc.CenterPoint().x,rc.bottom+3);
	strText.Format(_T("J%d"),m_pJun->GetKey());
	DrawText(pDc,strText,pointText);
	delete pNewPen;
}

void JunGraphics::DrawMark(CDC *pDc,COLORREF color,int nStyle,int nWidth,int Size)
{
	CSize sz(16,16);
	sz.cx += nWidth/2;
	sz.cy += nWidth/2;
	sz.cx = sz.cx * (float(Size)/100);
	sz.cy = sz.cy * (float(Size)/100);
	CPoint topleft = m_pJun->CenterPt()-sz;
	CPoint bottomright = m_pJun->CenterPt()+sz;
	CPen *pNewPen=new CPen; 
	CRect rc(topleft,bottomright);
	pNewPen->CreatePen(nStyle,nWidth,color);
	CPen *pOldPen = pDc->SelectObject(pNewPen);
	pDc->MoveTo(rc.left,rc.top);
	pDc->LineTo(rc.right,rc.top);
	pDc->LineTo(rc.right,rc.bottom);
	pDc->LineTo(rc.left,rc.bottom);
	pDc->LineTo(rc.left,rc.top);
	pDc->SelectObject(pOldPen);
	delete pNewPen;
}