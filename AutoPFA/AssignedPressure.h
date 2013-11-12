// AssignedPressure.h: interface for the AssignedPressure class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：AssignedPressure.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ASSIGNEDPRESSURE_H__C2FF4728_612F_49B9_937F_3EA66D148E6E__INCLUDED_)
#define AFX_ASSIGNEDPRESSURE_H__C2FF4728_612F_49B9_937F_3EA66D148E6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"
#include "Transient.h"

class AssignedPressure : public Jun  
{	
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatAssignedPressure();
	AssignedPressure();
	virtual ~AssignedPressure();

private:
	ScenarioObject* DoClone();

public:
	void DelLinkPipeInfo(UINT nKey);
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
	void AddLinkPipeInfo(UINT nKey);
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	virtual Transient* GetTransient();
	static TableFlyWeight<4> ms_PipeInfo;
	static StrFlyWeight ms_DistanceUnit;			//管道端口与节点标高距离单位
	static ArrayFlyWeight<3> ms_Pressure;			//压力类型0：停滞压力1：静止压力\值\单位
	static Transient         ms_Transient;          //瞬变共享数据

private:
	int m_nTran1Num;				//瞬变数据表1数据数量
	int m_nTran2Num;				//瞬变数据表2数据数量
};

inline CBitmap& AssignedPressure::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& AssignedPressure::GetArray()
{
	return s_StateName;
}
#endif // !defined(AFX_ASSIGNEDPRESSURE_H__C2FF4728_612F_49B9_937F_3EA66D148E6E__INCLUDED_)
