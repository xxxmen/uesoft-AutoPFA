// PCFPumpConfig.h: interface for the PCFPumpConfig class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PCFPUMPCONFIG_H__BB86F2C1_D484_4FE3_8243_7B95397A1300__INCLUDED_)
#define AFX_PCFPUMPCONFIG_H__BB86F2C1_D484_4FE3_8243_7B95397A1300__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "PCFPumpConfigData.h"
class AFX_EXT_CLASS PCFPumpConfig  
{
public:
	Iterator<PCFPumpConfigData>* CreatIterator()const;
public:
	CString PressType();
	void PressType(CString strValue);
	CString PressUnit();
	void PressUnit(CString strValue);
	CString FlowType();
	void FlowType(CString strValue);
	CString FlowUnit();
	void FlowUnit(CString strValue);
	CString PowerType();
	void PowerType(CString strValue);
	CString PowerUnit();
	void PowerUnit(CString strValue);
	CString Type();
	void Type(CString strValue);
	void Num(int nValue);
	CString InitData(CString strData);
	PCFPumpConfig();
	virtual ~PCFPumpConfig();
public:
	PCFPumpConfigData* CreatConfigData();
	RowObjectFace<1> m_PressType;			//泵结构压力的类型0：水头1：压力
	RowObjectFace<1> m_PressUnit;			//泵结构压力单位
	RowObjectFace<1> m_FlowType;			//泵结构流量参数0：体积流量1：质量流量
	RowObjectFace<1> m_FlowUnit;			//泵结构流量单位
	RowObjectFace<1> m_PowerType;			//效率或功率参数0：效率1：功率
	RowObjectFace<1> m_PowerUnit;			//效率或功率参数单位
	RowObjectFace<1> m_Type;				//泵构造方法0：简单 n：Multiple Configuations泵结构定义选择n作为当前
	RowObjectFace<1> m_Num;					//泵结构定义的数量(1)
	ListImp<PCFPumpConfigData> m_list;
	
	CString InitList(CString strData);
	int GetNum();
};

#endif // !defined(AFX_PCFPUMPCONFIG_H__BB86F2C1_D484_4FE3_8243_7B95397A1300__INCLUDED_)
