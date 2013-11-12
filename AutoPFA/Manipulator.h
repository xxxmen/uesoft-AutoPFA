// Manipulator.h: interface for the Manipulator class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Manipulator.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MANIPULATOR_H__35E8E803_FA49_459E_A248_C582931FFAD0__INCLUDED_)
#define AFX_MANIPULATOR_H__35E8E803_FA49_459E_A248_C582931FFAD0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class ComponentManager;
class WorkSpaceRef;

class Manipulator  
{
public:

	//点point是否在当前操作图型上
	virtual BOOL IsManipulator(CPoint point)=0;
	//接收鼠标移动消息操作
	virtual void Move(UINT nFlags,CPoint point,CDC* pDc)=0;
	virtual void UpClick(UINT nFlags, CPoint point)=0;
	virtual void DownClick(UINT nFlags, CPoint point)=0;
	virtual BOOL DbClick(UnitSubSystem &UnitSys);
	virtual Manipulator* Clone();
	//得到操作类型的ID号
	virtual int  CetTypeID()=0;
	virtual void Delete()=0;
	//改变当前操作的图形的颜色作为操作的标记
	virtual void DrawMark(CDC* pDc,WorkSpaceRef &ref)=0;
	//得到当前操作图形的区域
	virtual CRect Region(CPoint pt)const=0;
	Manipulator();
	virtual ~Manipulator();

protected:
	BOOL IsInClient(CPoint pt);
	
};

#endif // !defined(AFX_MANIPULATOR_H__35E8E803_FA49_459E_A248_C582931FFAD0__INCLUDED_)
