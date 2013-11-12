// Component.h: interface for the Component class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Component.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPONENT_H__3D8F51FB_133C_4A9F_9678_A73F8AB1FB86__INCLUDED_)
#define AFX_COMPONENT_H__3D8F51FB_133C_4A9F_9678_A73F8AB1FB86__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ScenarioObject.h"
#include "WorkSpaceRef.h"
#include "ComponentStatus.h"

class Graphics;
class Manipulator;
class ComponentManager;

namespace UeCoponentType
{
	const CString ePipe =  _T("PIPE");
    const CString eJun  =  _T("JUN");
}

class Component : public ScenarioObject  
{
public:
	virtual BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bReadOnlyDlg = FALSE)=0;
	virtual BOOL Pick(CRect rc)=0;
	virtual BOOL Pick(CPoint point,int Size=0)=0;
	virtual void Draw(CDC* pDc,WorkSpaceRef &ref)=0;
	virtual Graphics* GetGarph()=0;
	virtual Manipulator* CreatManipulator(ComponentManager *pManager,int Size,BOOL bSingle = TRUE)=0;
public:
	CString GetName();
	void SetName(CString strName);
    CString GetName(Scenario *pScenario);
	int GetType()=0;
	virtual int GetID()=0;
	virtual CString GetTypeName()=0;
	NameArray& GetArray()=0;
	static void Instance(NameArray &array);
	Component();
	virtual ~Component();
	Component(const Component &ref);
	Component& operator=(const Component &ref);
public:
	virtual void InitData()=0;
	BOOL IsDefine(BOOL bTrans=TRUE);
	virtual void Status(ComponentStatus &ref,BOOL bTrans=TRUE)=0;
	virtual void SetDesignFactor(CString strFactor)=0;
	virtual void SetPressType(CString strType)=0;
	static StrFlyWeight ms_Name;
private:
	virtual ScenarioObject* DoClone()=0;


};

#endif // !defined(AFX_COMPONENT_H__3D8F51FB_133C_4A9F_9678_A73F8AB1FB86__INCLUDED_)
