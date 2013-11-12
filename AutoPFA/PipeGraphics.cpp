// PipeGraphics.cpp: implementation of the PipeGraphics class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "AutoPFA.h"
#include "PipeGraphics.h"
#include "Pipe.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

PipeGraphics::PipeGraphics()
{

}

PipeGraphics::~PipeGraphics()
{

}

PipeGraphics* PipeGraphics::Instance(Pipe *pPipe)
{
	static PipeGraphics m_pipeGraphics;
	m_pipeGraphics.m_pPipe = pPipe;
	return &m_pipeGraphics;
}

BOOL PipeGraphics::Pick(CPoint point,int Size)
{
	BOOL	ret=FALSE;
	double	x = point.x - m_pPipe->StartPt().x;
	double	y = point.y - m_pPipe->StartPt().y;
	
	double	a = m_pPipe->EndPt().x - m_pPipe->StartPt().x;
	double	b = m_pPipe->EndPt().y - m_pPipe->StartPt().y;
	double	c = sqrt(a*a+b*b);
	
	double	sin_theta = b / c;
	double  cos_theta = a / c;
	
	double	chg_x = x*cos_theta + y*sin_theta;
	double	chg_y = -x*sin_theta + y*cos_theta;
	
	double	sd=5.0;
	if(fabs(chg_y)<sd&&(chg_x>-2&&chg_x<c+2))
		ret = TRUE;
	return ret;			
}

void PipeGraphics::Draw(CDC *pDc,COLORREF color,int nStyle, int nWidth,int Size)
{
	CPen *pNewPen=new CPen; 
	pNewPen->CreatePen(nStyle,nWidth,color);
	CPen *pOldPen = pDc->SelectObject(pNewPen);

	pDc->MoveTo(m_pPipe->StartPt());
	pDc->LineTo(m_pPipe->EndPt());
	DrawArrow(pDc,nWidth);
	pDc->SelectObject( pOldPen );
	delete pNewPen;
}

void PipeGraphics::DrawArrow(CDC *pDc,int nWidth)
{
	double dX,dY,dLx,dLy,dRx,dRy;
	double a,b,c,dMx,dMy,dTx,dTy;
	double sin,cos;
	a = m_pPipe->EndPt().x - m_pPipe->StartPt().x;
	b = m_pPipe->EndPt().y - m_pPipe->StartPt().y;
	c = sqrt(a*a + b*b);
	sin = a/c;
	cos = b/c;
	dX = m_pPipe->StartPt().x + (c * 0.5) * sin;
	dY = m_pPipe->StartPt().y + (c * 0.5) * cos;
	dMx = m_pPipe->StartPt().x + (c * 0.5-nWidth*3) * sin;
	dMy = m_pPipe->StartPt().y + (c * 0.5-nWidth*3) * cos;
	dTx = m_pPipe->StartPt().x + (c * 0.5+nWidth*3) * sin;
	dTy = m_pPipe->StartPt().y + (c * 0.5+nWidth*3) * cos;
	dLx = dMx - nWidth * cos;
    dLy = dMy + nWidth * sin;
	dRx = dMx + nWidth * cos;
	dRy = dMy - nWidth * sin;
	
	CPoint pointText(dTx,dTy+2);
	CPoint pointM(dX,dY);
	CPoint pointL(dLx,dLy);
	CPoint pointR(dRx,dRy);
	CString strText;
	strText.Format(_T("P%d"),m_pPipe->GetKey());
	DrawText(pDc,strText,pointText);
	pDc->MoveTo(pointL);
	pDc->LineTo(pointM);
    pDc->LineTo(pointR);
	pDc->LineTo(pointL);
}

void PipeGraphics::DrawMark(CDC *pDc,COLORREF color,int nStyle, int nWidth,int Size)
{
	CPen *pNewPen=new CPen; 
	pNewPen->CreatePen(nStyle,nWidth,color);
	CPen *pOldPen = pDc->SelectObject(pNewPen);
    CPoint startPt = m_pPipe->StartPt();
	CPoint endPt   = m_pPipe->EndPt();
	pDc->MoveTo(startPt);
	pDc->LineTo(endPt);
	pDc->PatBlt(startPt.x-2, startPt.y-2, 5, 5, BLACKNESS);
	pDc->PatBlt(endPt.x-2, endPt.y-2, 5, 5, BLACKNESS);
	DrawArrow(pDc,nWidth);
	pDc->SelectObject( pOldPen );
	delete pNewPen;
}