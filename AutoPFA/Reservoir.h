// Reservoir.h: interface for the Reservoir class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Reservoir.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESERVOIR_H__C35D23BE_1ED7_4C79_960D_57ECAD4D66E6__INCLUDED_)
#define AFX_RESERVOIR_H__C35D23BE_1ED7_4C79_960D_57ECAD4D66E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"
#include "Transient.h"

class Reservoir : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatReservoir();
	Reservoir();
	virtual ~Reservoir();

private:
	ScenarioObject* DoClone();

public:
	void DelLinkPipeInfo(UINT nKey);
	void SaveData();
	void InitData();
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bReadOnly = FALSE);
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
	static TableFlyWeight<6> ms_PipeInfo;
	static NumFlyWeight ms_EleOrDepthUnit;                //0未知\管道标高或深度单位
	static NumFlyWeight ms_SurfacePress;				 //表面压力值\单位
	static NumFlyWeight ms_Teamperature;			     //流体温度\单位
	static NumFlyWeight ms_Density;						 //流体密度\单位
	static StrFlyWeight ms_EleOrDepthType;				 //管道与水库连接点标高或深度
	static Transient         ms_Transient;          //瞬变共享数据

private:
	int m_nTran1Num;				//瞬变数据表1数据数量
	int m_nTran2Num;				//瞬变数据表2数据数量

};

inline CBitmap& Reservoir::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& Reservoir::GetArray()
{
	return s_StateName;
}


#endif // !defined(AFX_RESERVOIR_H__C35D23BE_1ED7_4C79_960D_57ECAD4D66E6__INCLUDED_)
