// AssignedFlow.h: interface for the AssignedFlow class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：AssignedFlow.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASSIGNEDFLOW_H__D408514A_CB54_4131_9314_884CED99275A__INCLUDED_)
#define AFX_ASSIGNEDFLOW_H__D408514A_CB54_4131_9314_884CED99275A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"
#include "Transient.h"

class AssignedFlow : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatAssignedFlow();
	AssignedFlow();
	virtual ~AssignedFlow();

private:
	ScenarioObject* DoClone();

public:
	void SaveData();
	void InitData();
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bDlgReadOnly = FALSE);
	BOOL Save(Junperisist *pPersistent);
	BOOL Read(Junperisist *pPersistent);
	CString GetTypeName();
	int GetID();
	static const int m_nTypeID;
private:
	BOOL CanLink(int nMaxLink,int nKey);
private:
	void EmptyPipeInfo();
	void DelLinkPipeInfo(UINT nKey);
	void AddLinkPipeInfo(UINT nKey);
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	virtual Transient* GetTransient();
    static ArrayFlyWeight<3> ms_Flow;				//流量类型\大小\单位
	static StrFlyWeight      ms_FlowDir;			//0：流体流入，1：流体流出
	static StrFlyWeight      ms_K;					//损失系数K值
	static ArrayFlyWeight<4> ms_InitPress;			//恒定流量为0的初始化压力（0，没有选，-1选中）\压力类型（0水头，1：压力）\压力值\单位
	static Transient         ms_Transient;          //瞬变共享数据

private:
	int m_nTran1Num;				//瞬变数据表1数据数量
	int m_nTran2Num;				//瞬变数据表2数据数量
};

inline CBitmap& AssignedFlow::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& AssignedFlow::GetArray()
{
	return s_StateName;
}
#endif // !defined(AFX_ASSIGNEDFLOW_H__D408514A_CB54_4131_9314_884CED99275A__INCLUDED_)
