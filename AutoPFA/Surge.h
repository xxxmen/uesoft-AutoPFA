// Surge.h: interface for the Surge class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Surge.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SURGE_H__9E3C7D91_E02B_4DA8_9DF7_147E3B639767__INCLUDED_)
#define AFX_SURGE_H__9E3C7D91_E02B_4DA8_9DF7_147E3B639767__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"
#include "Transient.h"

class Surge : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatSurge();
	Surge();
	virtual ~Surge();

private:
	ScenarioObject* DoClone();

public:
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
	void DelLinkPipeInfo(UINT nKey);
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	virtual Transient* GetTransient();
	static TableFlyWeight<4> ms_PipeInfo;
	static StrFlyWeight ms_DistanceUnit;
	static NumFlyWeight ms_SurgeHeight;					//调压塔的高度\单位
	static NumFlyWeight ms_ConstArea;					//底面积值\单位
	static NumFlyWeight ms_SurfacePress;				//表面压力\单位
	static ArrayFlyWeight<5> ms_Orifice;				//选中节流孔板模型标记\入流量系数\出流量系数\面积值\单位
	static ArrayFlyWeight<10> ms_ShortPipe;				//0：没有选择短管道模型，-1：选择短管道模型
														//短管道摩擦系数
														//短管道内直径\单位
														//短管道面积\单位
														//短管道长度\单位
														//短管道标高变化\单位
	static StrFlyWeight ms_OneWay;						//“One-Way Surge Tank”0：没有选择，-1选择来建模有止回阀特征的缓冲罐。
	static ArrayFlyWeight<4> ms_Vessel;					//模拟文丘里管0：没有选择，-1：选择
														//文丘里管到管道的高度\单位
														//多变的常量
	static StrFlyWeight ms_Variable;					//标记：选择面积恒定0，面积变化1
	static ArrayFlyWeight<3> ms_InitSurfaceH;			//稳定状态初始化流体高度0：没有选择-1：选择
														//高度值\单位
	static ArrayFlyWeight<5> ms_CheckValve;				//止回阀流量系数
														//止回阀初始位置0：打开1：关闭
														//打开阀门Delta压力或水头的压力类型0：水头1：压力
														//压力值\单位
	static Transient         ms_Transient;          //瞬变共享数据
	static TransDataTable<2>    ms_AreaTable;

private:
	int m_nTran1Num;				//瞬变数据表1数据数量
	int m_nTran2Num;				//瞬变数据表2数据数量
private:
	int m_VariableAreaNum;								//变化面积的数量
									

};

inline CBitmap& Surge::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& Surge::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_SURGE_H__9E3C7D91_E02B_4DA8_9DF7_147E3B639767__INCLUDED_)
