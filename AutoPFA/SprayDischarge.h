// SprayDischarge.h: interface for the SprayDischarge class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：SprayDischarge.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SPRAYDISCHARGE_H__AA330A64_BE04_4BEF_A445_AD53300E5523__INCLUDED_)
#define AFX_SPRAYDISCHARGE_H__AA330A64_BE04_4BEF_A445_AD53300E5523__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"
#include "Transient.h"

class SprayDischarge : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatSprayDischarge();
	SprayDischarge();
	virtual ~SprayDischarge();

private:
	ScenarioObject* DoClone();

public:
	void AddLinkPipeInfo(UINT nKey);
	void SaveData();
	void InitData();
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager,BOOL bDlgReadOnly);
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
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;
	
public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	virtual Transient* GetTransient();
	static StrFlyWeight ms_Type;							//Spray类型0：喷嘴管口1：喷雾
    static ArrayFlyWeight<13> ms_Curve;						//损失模型曲线。
	static ArrayFlyWeight<3> ms_ExitArea;					//单个口的面积\面积单位\数量
	static StrFlyWeight ms_KOrCv;							//K或Cv系数值
	static ArrayFlyWeight<3>  ms_ExitPress;					//出口压力类型0：水头1：压力
															//出口压力\单位
	static Transient         ms_Transient;          //瞬变共享数据
	//6.0下管道流向多加入了K系数和管道端口与节点标高
	static TableFlyWeight<4> ms_PipeInfo;
	static StrFlyWeight ms_DistanceUnit;			//管道端口与节点标高距离单位
private:
	int m_nTran1Num;				//瞬变数据表1数据数量
	int m_nTran2Num;				//瞬变数据表2数据数量
private:
	int m_nCurve;	
	

};

inline CBitmap& SprayDischarge::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& SprayDischarge::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_SPRAYDISCHARGE_H__AA330A64_BE04_4BEF_A445_AD53300E5523__INCLUDED_)
