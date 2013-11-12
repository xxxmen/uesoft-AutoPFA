// PipeManipulator.h: interface for the PipeManipulator class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：PipeManipulator.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PIPEMANIPULATOR_H__7110B3CD_B596_4872_A315_28E10F7AFB71__INCLUDED_)
#define AFX_PIPEMANIPULATOR_H__7110B3CD_B596_4872_A315_28E10F7AFB71__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Manipulator.h"
class Pipe;

class PipeManipulator : public Manipulator  
{
public:
	void Drag(CDC* pDc,CPoint point);
	void Move(UINT nFlags,CPoint point,CDC* pDc);
	void Draw(CDC* pDc,CPoint startPt0,CPoint endPt0);
	void UpClick(UINT nFlags, CPoint point);
	void DownClick(UINT nFlags, CPoint point);
	void Delete();
public:
	virtual CRect Region(CPoint pt)const;
	Manipulator* Clone();
	BOOL DbClick(UnitSubSystem &UnitSys);
	void Reverse();
	int CetTypeID();
	BOOL IsManipulator(CPoint point);
	void DrawMark(CDC* pDc,WorkSpaceRef &ref);
	virtual ~PipeManipulator();
	static PipeManipulator* Instance(Pipe *pPipe,ComponentManager *pManager,int Size,BOOL bSingle);
private:
	void CalcCoordinate(CPoint point,CPoint &startPt,CPoint &endPt)const;
	PipeManipulator();
	PipeManipulator(const PipeManipulator &ref);
	PipeManipulator& operator=(const PipeManipulator&);
	Pipe *m_pPipe;
	ComponentManager *m_pManager;
    int m_nSize;
	CPoint m_curPt;
	CPoint m_stratPt;
	CPoint m_endPt;
	int m_nType;
};

#endif // !defined(AFX_PIPEMANIPULATOR_H__7110B3CD_B596_4872_A315_28E10F7AFB71__INCLUDED_)
