// DrawJunTool.h: interface for the DrawJunTool class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：DrawJunTool.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAWJUNTOOL_H__7629B19E_57EB_4DB8_A0FC_87C9537B8712__INCLUDED_)
#define AFX_DRAWJUNTOOL_H__7629B19E_57EB_4DB8_A0FC_87C9537B8712__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Manipulator.h"
class Jun;

class DrawJunTool : public Manipulator  
{
public:
	void Move(UINT nFlags,CPoint point,CDC* pDc);
	void UpClick(UINT nFlags, CPoint point);
	void DownClick(UINT nFlags, CPoint point);
	void Delete();
	void DrawMark(CDC* pDc,WorkSpaceRef &ref);
public:
	virtual CRect Region(CPoint pt)const;
	int CetTypeID();
	BOOL IsManipulator(CPoint point);
	void UpData(Jun *pJun,CPoint point);
	static DrawJunTool* Instance(ComponentManager *pManager,int Size,int nID);
	DrawJunTool();
	virtual ~DrawJunTool();
	DrawJunTool(const DrawJunTool&);
	DrawJunTool& operator=(const DrawJunTool&);

	ComponentManager *m_pManager;
	int m_nSize;
	int m_nID;
};

#endif // !defined(AFX_DRAWJUNTOOL_H__7629B19E_57EB_4DB8_A0FC_87C9537B8712__INCLUDED_)
