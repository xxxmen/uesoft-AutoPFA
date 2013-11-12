// VacuumBreaker.h: interface for the VacuumBreaker class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：VacuumBreaker.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VACUUMBREAKER_H__9D914E85_2295_4910_A6B7_930E79D045C1__INCLUDED_)
#define AFX_VACUUMBREAKER_H__9D914E85_2295_4910_A6B7_930E79D045C1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"

class VacuumBreaker : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatVacuumBreaker();
    VacuumBreaker();
	virtual ~VacuumBreaker();

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
	void Status(ComponentStatus &ref, BOOL bTrans=TRUE);
	static ArrayFlyWeight<3> ms_CrackPress;				 //破裂的压力类型0：水头，1：压力/压力值/压力单位
	static NumFlyWeight      ms_OrificeInCdA;			 //孔口全部打开流入面积值/单位
	static NumFlyWeight      ms_OrificeOutCdA;			 //流出面积值/单位
	static ArrayFlyWeight<3> ms_LiquidTemp;				 //流体温度选择0：系统属性1：用户指定温度/温度值/单位
	static ArrayFlyWeight<9> ms_GasProperty;			 //气体属性0：空气1、其它气体/分子量/Cp/Cv/气体温度/气体压力/内部初始化气体气体质量/单位
	static StrFlyWeight      ms_ConnectPipe;			 //连接管道数0：两根管道1：一根管道
	static StrFlyWeight      ms_ValveType;			     //阀门类型
	static NumFlyWeight      ms_InterMediateCdA;		 //孔口全部打开媒介流出面积值/单位
	static ArrayFlyWeight<3> ms_MediateActivation;		 //媒介孔口激活标准0：压力不同1：流速不同/标准值/准值的单位
	

};

inline CBitmap& VacuumBreaker::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& VacuumBreaker::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_VACUUMBREAKER_H__9D914E85_2295_4910_A6B7_930E79D045C1__INCLUDED_)
