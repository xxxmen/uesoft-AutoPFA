// DrawPipeTool.h: interface for the DrawPipeTool class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DrawPipeTool.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWPIPETOOL_H__86CFB28F_CBF9_4633_AB41_A2586AD05DEE__INCLUDED_)
#define AFX_DRAWPIPETOOL_H__86CFB28F_CBF9_4633_AB41_A2586AD05DEE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Manipulator.h"
class Pipe;

class DrawPipeTool : public Manipulator  
{
public:
	void Move(UINT nFlags,CPoint point,CDC* pDc);
	void UpClick(UINT nFlags, CPoint point);
	void DownClick(UINT nFlags, CPoint point);
	void Delete();
	void DrawMark(CDC* pDc,WorkSpaceRef &ref);
	void Draw(CDC* pDc);
public:
	virtual CRect Region(CPoint pt)const;
	int CetTypeID();
	BOOL IsManipulator(CPoint point);
	void UpData(Pipe *pPipe,CPoint point);
	static DrawPipeTool* Instance(ComponentManager *pManager,int Size,int nID);
	DrawPipeTool();
	virtual ~DrawPipeTool();
	DrawPipeTool(const DrawPipeTool&);
	DrawPipeTool& operator=(const DrawPipeTool&);

	ComponentManager *m_pManager;
	int m_nSize;
	int m_nID;
	CPoint m_downPt;
	CPoint m_curPt;
};

#endif // !defined(AFX_DRAWPIPETOOL_H__86CFB28F_CBF9_4633_AB41_A2586AD05DEE__INCLUDED_)
