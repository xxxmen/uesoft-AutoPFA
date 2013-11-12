// MacroManipulator.h: interface for the MacroManipulator class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：MacroManipulator.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MACROMANIPULATOR_H__FE322927_1582_4A5C_98FF_95C05D70D6F6__INCLUDED_)
#define AFX_MACROMANIPULATOR_H__FE322927_1582_4A5C_98FF_95C05D70D6F6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Manipulator.h"
class Component;

class MacroManipulator : public Manipulator  
{
public:
	void Move(UINT nFlags,CPoint point,CDC* pDc);
	void UpClick(UINT nFlags, CPoint point);
	void DownClick(UINT nFlags, CPoint point);
	void Delete();
public:
	CRect Region(CPoint pt)const;
	Manipulator* Clone();
	int CetTypeID();
	void Add(Component* pComponent);
	BOOL IsManipulator(CPoint point);
	void DrawMark(CDC* pDc,WorkSpaceRef &ref);
	virtual ~MacroManipulator();
	static MacroManipulator* Instance(ComponentManager *pManager,int Size);
private:
	void DelManipulator();
	void Draw(CDC* pDc,CPoint point);
	MacroManipulator();
	MacroManipulator(const MacroManipulator&);
	MacroManipulator& operator=(const MacroManipulator&);

	ComponentManager *m_pManager;
    int m_nSize;
	BOOL m_bManipulator;
	typedef CList<Manipulator*,Manipulator*>ManipulatorList;
	ManipulatorList m_ManiList;
	CPoint m_downPt;
	CRect  m_Rc;
};

#endif // !defined(AFX_MACROMANIPULATOR_H__FE322927_1582_4A5C_98FF_95C05D70D6F6__INCLUDED_)
