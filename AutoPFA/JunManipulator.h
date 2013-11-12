// JunManipulator.h: interface for the JunManipulator class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：JunManipulator.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_JUNMANIPULATOR_H__C9FEBF11_055D_4AA4_9EC8_738B4AB67BE3__INCLUDED_)
#define AFX_JUNMANIPULATOR_H__C9FEBF11_055D_4AA4_9EC8_738B4AB67BE3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Manipulator.h"

class Jun;

class JunManipulator : public Manipulator  
{
public:
	void Drag(CDC* pDc,CPoint point);
	void Move(UINT nFlags,CPoint point,CDC* pDc);
	void UpClick(UINT nFlags, CPoint point);
	void DownClick(UINT nFlags, CPoint point);
	void Delete();
public:
	virtual CRect Region(CPoint pt)const;
	Manipulator* Clone();
	BOOL DbClick(UnitSubSystem &UnitSys);
	int CetTypeID();
	BOOL IsManipulator(CPoint point);
	void DrawMark(CDC* pDc,WorkSpaceRef &ref);
	static JunManipulator* Instance(Jun *pJun,ComponentManager *pManager,int Size,BOOL bSingle);
    virtual ~JunManipulator();
private:
	void Draw(CDC* pDc,CPoint point);
	JunManipulator(const JunManipulator&);
	JunManipulator& operator=(const JunManipulator&);
	JunManipulator();
	Jun *m_pJun;
	ComponentManager *m_pManager;
	int m_nSize;

private:
	CPoint m_downPt;
	CPoint m_curPt;
	CSize m_centerOff;
};

#endif // !defined(AFX_JUNMANIPULATOR_H__C9FEBF11_055D_4AA4_9EC8_738B4AB67BE3__INCLUDED_)
