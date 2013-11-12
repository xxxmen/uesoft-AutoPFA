// AreaChange.h: interface for the AreaChange class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：AreaChange.h
  摘要：    异径管是局部阻力元件，由于异径管连接管道面积不同所以经过异径管流量变化大
            所以需要详细建模异径管，建模异径管如果需要即时得到k系数必须访问连接管道的面积，
			同时必须响应连接管道面积改变自动更新K系数。
            
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AREACHANGE_H__85DE6716_4E8C_4283_AC07_1FEDF638BCBF__INCLUDED_)
#define AFX_AREACHANGE_H__85DE6716_4E8C_4283_AC07_1FEDF638BCBF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"

class AreaChange : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatAreaChange();
	AreaChange();
	virtual ~AreaChange();

public:
	void SaveData();
	void InitData();
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bDlgReadOnly = FALSE);
	BOOL Save(Junperisist *pPersistent);
	BOOL Read(Junperisist *pPersistent);
	CString GetTypeName();
	int GetID();
	static const int m_nTypeID;
	
private:
	ScenarioObject* DoClone();
	BOOL CanLink(int nMaxLink,int nKey);
private:
	void EmptyPipeInfo();
	void DelLinkPipeInfo(UINT nKey);
	void AddLinkPipeInfo(UINT nKey);
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

public:
	static int AreaType(double dAreaUp,double dAreaDown);
	static void CalcK(double dAreaUp,double dAreaDown,int nRetype,double BaseArea);
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	static StrFlyWeight ms_Type;			//异径管类型（0：圆锥，1：圆柱，2：用户定义）
	static StrFlyWeight ms_Dir;				//（1：收缩，2：扩张）
	static StrFlyWeight ms_Angle;			//角度
	static StrFlyWeight ms_K;				//K系数值
	static ArrayFlyWeight<3> ms_BasisArea;	//损失模型的面积引用
};

inline CBitmap& AreaChange::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& AreaChange::GetArray()
{
	return s_StateName;
}
#endif // !defined(AFX_AREACHANGE_H__85DE6716_4E8C_4283_AC07_1FEDF638BCBF__INCLUDED_)
