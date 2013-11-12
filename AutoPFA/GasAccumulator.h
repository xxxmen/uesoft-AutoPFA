// GasAccumulator.h: interface for the GasAccumulator class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：GasAccumulator.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_GASACCUMULATOR_H__AD458CF6_07DC_4FDD_845B_F4297072550A__INCLUDED_)
#define AFX_GASACCUMULATOR_H__AD458CF6_07DC_4FDD_845B_F4297072550A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"

class GasAccumulator : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatGasAccumulator();
	GasAccumulator();
	virtual ~GasAccumulator();

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
	void AddLinkPipeInfo(UINT nKey);
private:
	void EmptyPipeInfo();
	static NameArray s_StateName;
    static CBitmap m_bitmap;
	static CString s_typeName;

public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	static StrFlyWeight ms_Polytropic;					//变化的常量
	static NumFlyWeight ms_InitVolume;					//初始化气体体积\单位
	static ArrayFlyWeight<5> ms_Orifice;				//选中节流孔板模型标记\入流量系数\出流量系数\面积值\单位
	static ArrayFlyWeight<10> ms_ShortPipe;				//0：没有选择短管道模型，-1：选择短管道模型
														//短管道摩擦系数
														//短管道内直径\单位
														//短管道面积\单位
														//短管道长度\单位
														//短管道标高变化\单位
	static ArrayFlyWeight<4> ms_InitPress;				//0:没有选中设置静态流初试压力，-1:没有选中设置静态流初试压力
														//0：压力类型为水头，1：压力类型为压力
														//压力大小\单位
	static StrFlyWeight ms_MaxVolume;					//最大体积
	static StrFlyWeight ms_MinVolume;					//最小体积
	static ArrayFlyWeight<3> ms_GasVolume;				//类型（0：初始化指定体积，1：初始化指定压力）
														//参考气体压力\单位
									

};

inline CBitmap& GasAccumulator::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& GasAccumulator::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_GASACCUMULATOR_H__AD458CF6_07DC_4FDD_845B_F4297072550A__INCLUDED_)
