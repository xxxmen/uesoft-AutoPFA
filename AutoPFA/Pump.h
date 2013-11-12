// Pump.h: interface for the Pump class.
/*
 * Copyright (C), 2006,长沙优易软件公司CAE开发部
 * All rights reserved.
 *
  文件名称：Pump.h
  摘要：    
  author  : LSP          
*/
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PUMP_H__3028A462_3227_4AA8_B028_35251C8D57CC__INCLUDED_)
#define AFX_PUMP_H__3028A462_3227_4AA8_B028_35251C8D57CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Jun.h"
#include "PumpTransient.h"
#include "Configuration.h"

class Pump : public Jun  
{
public:
	CBitmap& GetBitMap();
	static void Instance();
	NameArray& GetArray();
	static Component* CreatPump();
	Pump();
	virtual ~Pump();

private:
	ScenarioObject* DoClone();

public:
	void DelLinkPipeInfo(UINT nKey);
	
	void SaveData();
	void InitData();
	BOOL Show(UnitSubSystem &UnitSys,ComponentManager *pManager, BOOL bDlgReadOnly = FALSE);//第三个参数表示在显示节点属性的对话框里不能修改节点任何属性
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
	virtual Transient* GetTransient();
    static StrFlyWeight			ms_PumpType;				//泵模型的类型0：泵曲线，1：指定体积流量2：指定质量流量
	static ArrayFlyWeight<3>	ms_PumpFlow;				//流量类型\流量大小\单位
	static StrFlyWeight			ms_SpeedRatio;				//变速泵的速率相对泵曲线的速率（1：表示100%）
	static ArrayFlyWeight<4>	ms_PumpControl;				//控制泵类型（0：没有控制，1：输出端压力/水头控制，3：输入端压力/水头控制，2：流量控制
															//控制点参数类型0：水头/水头损失/体积流量1：压力/压力损失/质量流量
															//控制点参数值
															//控制点参数单位
	static StrFlyWeight			ms_ControlApply;            //控制对应的情况设置（0：总是控制1：压力超过控制设置2：压力低于控制设置）
	static StrFlyWeight			ms_PressType;				//0：停滞压力1：静态压力
	static ArrayFlyWeight<4>	ms_SubmergePump;           	//0：潜水泵没有选择；-1：潜水泵选择
															//压力的类型0：水头1：压力
															//吸入口压力值
															//吸入口压力单位
	static StrFlyWeight			ms_ExitCheck;				//-1：选择出口止回阀，0：没有选择出口止回阀
	static NumFlyWeight			ms_CloseVel;		        //关闭阀门的最小速度\速度单位
	static StrFlyWeight			ms_antiReverse;				//-1：没有选择限制泵反转，0选择限制泵反转
	static ArrayFlyWeight<3>	ms_ReOpenPress;				//重新打开阀门Delta(压力或水头)0：水头1：压力\压力值\单位
	static StrFlyWeight			ms_PumpSet;					//泵机组，并联泵：泵的数量；串连泵：负号+泵的数量,0:单泵
    static PumpTransient        ms_Transient; 
	static Configuration        ms_Configuration;
public:
	void Status(ComponentStatus &ref,BOOL bTrans=TRUE);
	static const CmbDataItem    ms_TransModel1[2];           //容积泵瞬变模型
	static const CmbDataItem    ms_TransModel2[8];           //离心泵瞬变模型

private:
	int m_nTran1Num;				//瞬变数据表1数据数量
	int m_nTran2Num;				//瞬变数据表2数据数量
	int m_nFourQuadNum;				//四象限数据数据数量

private:
	int m_nCurve1;
	int m_nCurve2;
	int m_nCurve3;
};

inline CBitmap& Pump::GetBitMap()
{
	return m_bitmap;
}

inline NameArray& Pump::GetArray()
{
	return s_StateName;
}

#endif // !defined(AFX_PUMP_H__3028A462_3227_4AA8_B028_35251C8D57CC__INCLUDED_)
