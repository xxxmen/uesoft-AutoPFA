// ControlValve.h: interface for the ControlValve class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：ControlValve.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONTROLVALVE_H__9081409C_5E0F_4F54_B57C_71DD6E78C1E8__INCLUDED_)
#define AFX_CONTROLVALVE_H__9081409C_5E0F_4F54_B57C_71DD6E78C1E8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"
#include "Transient.h"

class ControlValve : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatControlValve();
	ControlValve();
	virtual ~ControlValve();

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
	static ArrayFlyWeight<5> ms_ControlSet;		//阀门类型0：PRF 1：PSV 2：FCV 3：PDCV
												//控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
												//0：停滞压力1：静态压力
												//控制点参数值
												//控制点参数单位
	static StrFlyWeight ms_ModelType;			//损失模型(0：流量系数模型，1：K系数模型 -2：使用系数表的值)
	static StrFlyWeight ms_KOrCv;				//K或Cv系数值
	static ArrayFlyWeight<4> ms_failAction;		//稳定状态总是控制0：没有选择 1：选择
												//使用默认的行为  0：没有选择 1：选择
												//上游压力不足表现0：全部打开 1：关闭
												//下游压力超过表现0：全部打开 1：关闭
	static Transient    ms_Transient;          //控制瞬变共享数据
	static Transient    ms_FailTransient;      //打开/关闭瞬变共享数据
	static TransDataTable<3> ms_KorCvData;
private:
	int m_nTran1Num;				//瞬变数据表1数据数量
	int m_nTran2Num;				//瞬变数据表2数据数量
	int m_nFailTran1Num;			//瞬变数据表1数据数量
	int m_nFailTran2Num;			//瞬变数据表2数据数量
	int m_nKorCvData;               //阀门开度vs流量系数表

	

};

inline CBitmap& ControlValve::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& ControlValve::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_CONTROLVALVE_H__9081409C_5E0F_4F54_B57C_71DD6E78C1E8__INCLUDED_)
