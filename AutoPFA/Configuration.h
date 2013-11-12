// Configuration.h: interface for the Configuration class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CONFIGURATION_H__E20047CF_C54D_436F_B170_373FB4F70F5F__INCLUDED_)
#define AFX_CONFIGURATION_H__E20047CF_C54D_436F_B170_373FB4F70F5F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "StrFlyWeight.h"
#include "ScenarioObject.h"
#include "onfigPerisist.h"
#include "TransDataTable.h"

class Configuration  
{
public:
	Configuration();
	virtual ~Configuration();

public:
	StrFlyWeight m_PressType;			//泵结构压力的类型0：水头1：压力
	StrFlyWeight m_PressUnit;			//泵结构压力单位
	StrFlyWeight m_FlowType;			//泵结构流量参数0：体积流量1：质量流量
	StrFlyWeight m_FlowUnit;			//泵结构流量单位
	StrFlyWeight m_PowerType;			//效率或功率参数0：效率1：功率
	StrFlyWeight m_PowerUnit;			//效率或功率参数单位
	StrFlyWeight m_Num;

	//
	StrFlyWeight m_Name;				//泵结构定义描述
	StrFlyWeight m_RPM;					//泵的RPM值
	NumFlyWeight m_ImpellerDia;			//泵的叶轮直径\单位
	StrFlyWeight m_MaxFlow;				//泵结构泵图形的X轴最大值
	ArrayFlyWeight<7> m_Curve1;			//H-Q曲线类型（1：压力损失多项式，2：压力损失内插值）
										//公式中参数和常量的个数
										//公式中的参数和常量a，b，c，d，e的值
	StrFlyWeight m_ID;					//标记（RDS+Num）在[RAW DATA SETS]和[RAW DATA REFERENCES]中的标记ID
	TransDataTable<4> m_RawData;
	ArrayFlyWeight<7> m_Curve2;			//HNPSHR曲线类型（1：压力损失多项式，2：压力损失内插值）
										//公式中参数和常量的个数
										//公式中的参数和常量a，b，c，d，e的值
	StrFlyWeight m_Affiniity ;			//NPSHR Affiniity Exponent At Operating Speed 的K值
	ArrayFlyWeight<7> m_Curve3;			//BEP曲线类型（1：压力损失多项式，2：压力损失内插值）
										//公式中参数和常量的个数
										//公式中的参数和常量a，b，c，d，e的值
	ArrayFlyWeight<3>  m_CurveEndFlow;	//流量类型（0：体积流量，1：质量流量）\流量值\单位
	NumFlyWeight  m_BEP;				//最佳功效点BEP的值\单位

	CString CreatID();
public:
	static void GetPrame(ArrayFlyWeight<7>& curve,double dPrame[]);
	CString PowerTitle();
	CString PressTitle();
	CString FlowTitle();
	
	void InitData(ScenarioObject *pObject);
	BOOL SaveData(ScenarioObject *pObject,int &num1,int &num2,int &num3);
	int Instance(NameArray &array,int nKey);
	BOOL Save(ConfigPerisist &Persistent,int num1,int num2,int num3);
	BOOL Read(ConfigPerisist &Persistent);

private:
	int m_nKey;


};

#endif // !defined(AFX_CONFIGURATION_H__E20047CF_C54D_436F_B170_373FB4F70F5F__INCLUDED_)
