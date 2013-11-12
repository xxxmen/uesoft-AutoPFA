// ReliefValve.h: interface for the ReliefValve class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称： ReliefValve.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RELIEFVALVE_H__EA245972_1BBC_4AB9_A7B4_0BCCAAD971FB__INCLUDED_)
#define AFX_RELIEFVALVE_H__EA245972_1BBC_4AB9_A7B4_0BCCAAD971FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"
#include "Transient.h"

class ReliefValve : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatReliefValve();
	ReliefValve();
	virtual ~ReliefValve();

private:
	ScenarioObject* DoClone();

public:
	void DelLinkPipeInfo(UINT nKey);
	void AddLinkPipeInfo(UINT nKey);
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
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	virtual Transient* GetTransient();
	static StrFlyWeight ms_Type;							//类型(1:内部安全阀（internal relief）2:出口安全阀（exit relief）3:内嵌安全阀（inline relief）)
    static ArrayFlyWeight<13> ms_Curve;						//损失模型曲线。
	static ArrayFlyWeight<5>  ms_CrackExitPress;			//压力/水头类型0：绝对水头1：绝对压力2：水头差3：压力差
															//破裂压力\单位
															//出口压力\单位
	static StrFlyWeight ms_KOrCv;							//K或Cv系数值
	static ArrayFlyWeight<3> ms_BasisArea;					//损失模型的面积引用0：默认上游管道面积，1：下游管道面积2：用户指定面积3：用户指定直径
													    	//值/单位
	static Transient         ms_Transient;                  //瞬变共享数据

private:
	int m_nTran1Num;				//瞬变数据表1数据数量
	int m_nTran2Num;				//瞬变数据表2数据数量 
private:
	int m_nCurve;
};

inline CBitmap& ReliefValve::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& ReliefValve::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_RELIEFVALVE_H__EA245972_1BBC_4AB9_A7B4_0BCCAAD971FB__INCLUDED_)
